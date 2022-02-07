/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:27:48 by bledda            #+#    #+#             */
/*   Updated: 2022/02/07 14:15:12 by bledda           ###   ########.fr       */
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
		public:
			typedef Node<Keys, T>						*NodePtr;
			typedef	B_tree<Keys, T>						*pointer;
			// typedef typename Node<Keys, T>::value_type	value_type;
			typedef	typename ft::pair<Keys, T>			value_type;
			typedef value_type *						pairPtr;
			typedef value_type &						reference;
		private:
			NodePtr _ptr;
		public:
			pairPtr operator->() const
			{
				//std::cout << "Fleche" << std::endl;
				pairPtr tmp = (pairPtr)&_ptr->data;
				return (tmp);
			};
			
			value_type operator*() const
			{
				//std::cout << "Coucou" << std::endl;
				return (*(this->operator->()));
			};

			reference data() const
			{
				return (this->_ptr->data);
			}
			
			B_tree() {
				_ptr = 0;
			};
			~B_tree() {};
			B_tree(NodePtr ptr) {
				_ptr = ptr;
			};
			B_tree & operator=(NodePtr ptr)
			{
				_ptr = ptr;
				return (*this);
			}
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
			NodePtr getRoot() const
			{
				NodePtr root = _ptr;

				while (root && root->parent != 0)
					root = root->parent;
				return (root);
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

				NodePtr current = getRoot();

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

				NodePtr current = getRoot();
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
			// NodePtr  begin()
			// {
			// 	NodePtr current = getRoot();

			// 	while (current->leftChild)
			// 		current = current->leftChild;
			// 	return (current);
			// }

			NodePtr  begin() const
			{
				NodePtr current = getRoot();

				if (current == 0)
					return (0);
				while (current->leftChild)
					current = current->leftChild;
				return (current);
			}
			
			NodePtr end() const
			{
				NodePtr current = getRoot();
				
				if (current == 0)
					return (0);
				while (current->rightChild)
					current = current->rightChild;
				return (current);
			}

			B_tree & operator++() {
				Keys tmp = this->_ptr->data.first;
				if (this->_ptr->rightChild)
				{
					this->_ptr = this->_ptr->rightChild;
					while(this->_ptr->leftChild && this->_ptr->leftChild->data.first >= tmp)
						this->_ptr = this->_ptr->leftChild;
				}
				else
				{
					while (this->_ptr->data.first <= tmp)
					{
						if (this->_ptr->parent == 0)
						{
							this->_ptr = end() ;
							break ;
						}
						else
							this->_ptr = this->_ptr->parent;
					}
				}
				return (*this);
			};

			B_tree operator++(int) {
				B_tree tmp(_ptr);
				++(*this);
				return (tmp);
			};

			B_tree & operator--() {
				Keys tmp = this->_ptr->data.first;
				if (this->_ptr->leftChild)
				{
					this->_ptr = this->_ptr->leftChild;
					while(this->_ptr->rightChild && this->_ptr->rightChild->data.first <= tmp)
						this->_ptr = this->_ptr->rightChild;
				}
				else
				{
					while (this->_ptr->data.first >= tmp)
					{
						if (this->_ptr->parent == 0)
						{
							this->_ptr = begin() ;
							break ;
						}
						else
							this->_ptr = this->_ptr->parent;
					}
				}
				return (*this);
			};

			B_tree operator--(int) {
				B_tree tmp(_ptr);
				--(*this);
				return (tmp);
			};

			NodePtr getPtr()
			{
				return (this->_ptr);
			}

			bool operator!=(B_tree const & rhs) const {
				if (_ptr == 0 || rhs._ptr == 0)
					return (true);
				if (this->data() != rhs.data())
					return (true);
				return (false);
			};

			
			
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
				if (getRoot() == 0)
				{
					_ptr = ptr;
					_ptr->parent = 0;
					return ;
				}
				
				NodePtr current = getRoot();
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
