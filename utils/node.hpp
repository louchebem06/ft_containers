/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:13:50 by bledda            #+#    #+#             */
/*   Updated: 2022/01/26 18:20:52 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utility.hpp"

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
				ptr->data(val);
				ptr->leftChild = 0;
				ptr->rightChild = 0;
				_where(&ptr);
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
				while (true)
				{
					if (current->data.first == ptr->data.first)
						return ;
					else if (current->data.first < ptr->data.first)
					{
						if (_ptr->leftChild == 0)
						{
							current->leftChild = ptr;
							return ;
						}
						current = _ptr->leftChild;
					}
					else if (current->data.first > ptr->data.first)
					{
						if (_ptr->rightChild == 0)
						{
							current->rightChild = ptr;
							return ;
						}
						current = _ptr->rightChild;
					}
				}
				
			}
	};
}