/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:27:48 by bledda            #+#    #+#             */
/*   Updated: 2022/01/28 18:05:16 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utility.hpp"
#include <iostream>

namespace ft
{
	template <class Keys, class T>
	struct Node
	{
		typedef	typename ft::pair<Keys, T>	value_type;

		Node 		*leftChild;
		Node 		*rightChild;
		Node 		*parent;
		value_type 	data;
	};
}

namespace ft
{
	template <class Keys, class T>
	class B_tree
	{
		private:
			typedef Node<Keys, T>						*NodePtr;
			typedef	B_tree<Keys, T>						*pointer;
			typedef typename Node<Keys, T>::value_type	value_type;
		private:
			NodePtr _ptr;
		public:
			B_tree() {
				_ptr = 0;
			};
			~B_tree() {};
			void	insert(value_type val)
			{
				if (find(val.first))
					return ;
				NodePtr ptr = new Node<Keys, T>;
				ptr->data = val;
				ptr->leftChild = 0;
				ptr->rightChild = 0;
				_where(ptr);
			}
			NodePtr master()
			{
				return (_ptr);
			}
			void log(NodePtr root, std::string indent = "", bool right = false)
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
				std::cout << root->data.first << std::endl;
				log(root->leftChild, indent, false);
				log(root->rightChild, indent, true);
			}
			NodePtr find(Keys k)
			{
				if (_ptr == 0)
					return (0);

				NodePtr current = _ptr;

				while (true)
				{
					if (k == current->data.first)
						return (current);
					else if (current->leftChild && k <= current->data.first)
						current = current->leftChild;
					else if (current->rightChild && k >= current->data.first)
						current = current->rightChild;
					else
						return (0);
				}
			}
			void remove(Keys k)
			{
				if (_ptr == 0)
					return ;

				NodePtr current = _ptr;
				while (current->parent)
					current = current->parent;

				if (current->data.first == k)
				{
					NodePtr left, right;

					left = current->leftChild;
					right = current->rightChild;
					delete _ptr;
					_ptr = 0;
					if (left)
					{
						_ptr = left;
						_ptr->parent = 0;
						_where(right);
					}
					else if (right)
					{
						_ptr = right;
						_ptr->parent = 0;
						_where(left);
					}
					return ;	
				}
				while (true)
				{
					if (k < current->data.first && !_del(current, k))
						current = current->leftChild;
					else if (k > current->data.first && !_del(current, k))
						current = current->rightChild;
					else
						return ;
				}
			}
			NodePtr begin()
			{
				NodePtr current = _ptr;
				
				while (current->leftChild)
					current = current->leftChild;
				return (current);
			}
			NodePtr end()
			{
				NodePtr current = _ptr;
				
				while (current->rightChild)
					current = current->rightChild;
				return (current);
			}
			value_type getData()
			{
				return (_ptr->data);
			}
			void testos()
			{
				NodePtr current = begin();

				while (current)
				{
					std::cout << current->data.first << std::endl;
					current = current->rightChild;
				}
				current = begin();
				while (current)
				{
					std::cout << current->data.first << std::endl;
					current = current->rightChild;
				}
			}
		private:
			bool _del(NodePtr ptr, Keys k)
			{
				bool ok = false ;
				NodePtr left, right;
				
				left = right = 0;
				if (ptr->leftChild && ptr->leftChild->data.first == k)
				{
					ok = true;
					left = ptr->leftChild->leftChild;
					right = ptr->leftChild->rightChild;
					delete ptr->leftChild;
					ptr->leftChild = 0;
				}
				else if (ptr->rightChild && ptr->rightChild->data.first == k)
				{
					ok = true;
					left = ptr->rightChild->leftChild;
					right = ptr->rightChild->rightChild;
					delete ptr->rightChild;
					ptr->rightChild = 0;
				}
				_where(left);
				_where(right);
				return (ok);
			}
			void _where(NodePtr ptr)
			{
				if (ptr == 0)
					return ;
				if (_ptr == 0)
				{
					_ptr = ptr;
					_ptr->parent = 0;
					return ;
				}
				
				NodePtr current = _ptr;
				while (true)
				{
					if (current->data.first == ptr->data.first)
						return ;
					else if (current->leftChild
						&& ptr->data.first < current->data.first)
						current = current->leftChild;
					else if (current->rightChild
						&& ptr->data.first > current->data.first)
						current = current->rightChild;
					else if (!current->leftChild
						&& ptr->data.first < current->data.first)
					{
						ptr->parent = current;
						current->leftChild = ptr;
						return ;
					}
					else if (!current->rightChild
						&& ptr->data.first > current->data.first)
					{
						ptr->parent = current;
						current->rightChild = ptr;
						return ;
					}
				}
			}
	};
}
