/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:13:50 by bledda            #+#    #+#             */
/*   Updated: 2022/01/27 11:07:57 by bledda           ###   ########.fr       */
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
	
	template <class Keys, class T>
	class B_tree
	{
		private:
			typedef Node<Keys, T>						*NodePtr;
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
				NodePtr ptr = new Node<Keys, T>;
				ptr->data = val;
				ptr->leftChild = 0;
				ptr->rightChild = 0;
				_where(ptr);
			}
			NodePtr first() { return (this->_ptr->parent); }
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
		private:
			void _where(NodePtr ptr)
			{
				if (_ptr == 0)
				{
					_ptr = ptr;
					_ptr->parent = ptr;
					return ;
				}

				NodePtr current = _ptr->parent;
				NodePtr prev = _ptr->parent;
				while (true)
				{
					if (current && current->data.first == ptr->data.first)
						return ;
					else if (current && ptr->data.first < current->data.first)
					{
						prev = current;
						current = current->leftChild;
					}
					else if (current && ptr->data.first > current->data.first)
					{
						prev = current;
						current = current->rightChild;
					}
					else if (current == 0)
					{
						if (ptr->data < prev->data && prev->leftChild == 0)
						{
							prev->parent = _ptr->parent;
							prev->leftChild = ptr;
						}
						else if (ptr->data > prev->data && prev->rightChild == 0)
						{
							prev->parent = _ptr->parent;
							prev->rightChild = ptr;
						}
						else if (ptr->data < prev->data)
							current = prev->leftChild;
						else if (ptr->data > prev->data)
							current = prev->rightChild;
					}
				}
			}
	};
}