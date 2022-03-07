/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:32:58 by bledda            #+#    #+#             */
/*   Updated: 2022/03/08 00:34:04 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <string>
#include <iostream>

namespace ft
{
	struct node
	{
		int		key_value;
		node	*left;
		node	*right;
	};

	template <class Alloc = std::allocator<node> >
	class btree
	{
		public:
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type 			size_type;
		private:
			pointer			_root;
			allocator_type	_alloc;
		public:
			btree(const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_root = NULL;
			}
			~btree() { destroy_tree(); }
	
			void insert(int key)
			{
				if(_root != NULL)
					insert(key, _root);
				else
				{
					_root = new node;
					_root->key_value = key;
					_root->left = NULL;
					_root->right = NULL;
				}
			}
			pointer search(int key) { return search(key, _root); };
			void destroy_tree() { destroy_tree(_root); }

			void tree()
			{
				tree(_root);
			}
		private:
			void destroy_tree(node *leaf)
			{
				if(leaf != NULL)
				{
					destroy_tree(leaf->left);
					destroy_tree(leaf->right);
					_alloc.deallocate(leaf, 1);
				}
			}
			void insert(int key, node *leaf)
			{
				if(key< leaf->key_value)
				{
					if(leaf->left != NULL)
						insert(key, leaf->left);
					else
					{
						leaf->left = _alloc.allocate(1);
						leaf->left->key_value = key;
						leaf->left->left = NULL;
						leaf->left->right = NULL;
					}  
				}
				else if(key >= leaf->key_value)
				{
					if(leaf->right != NULL)
						insert(key, leaf->right);
					else
					{
						leaf->right = _alloc.allocate(1);
						leaf->right->key_value = key;
						leaf->right->left = NULL;
						leaf->right->right = NULL;
					}
				}
			}
			pointer search(int key, node *leaf)
			{
				if(leaf != NULL)
				{
					if(key == leaf->key_value)
						return (leaf);
					if(key < leaf->key_value)
						return (search(key, leaf->left));
					else
						return (search(key, leaf->right));
				}
				else
					return (NULL);
			}
			void tree(node *root, std::string indent = "", bool right = false)
			{
				if (root == 0)
					return ;

				std::cout << indent;
				if (right)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}
				std::cout << root->key_value << std::endl;
				tree(root->left, indent, false);
				tree(root->right, indent, true);
			}
	};
}
