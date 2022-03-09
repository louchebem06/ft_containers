/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:32:55 by bledda            #+#    #+#             */
/*   Updated: 2022/03/09 20:24:49 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../utils/iterator.hpp"
#include <iostream>
#include "node.hpp"

namespace ft
{
	template <class Key, class T>
	class btree_iterator :
		public iterator<bidirectional_iterator_tag, ft::node<Key, T> >
	{
		protected:
			typedef iterator<bidirectional_iterator_tag,
					ft::node<Key, T> >						iterator;
		public:
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference 			reference;
		public:
			btree_iterator() { this->_ptr = NULL; };
			btree_iterator(pointer leaf) { this->_ptr = leaf; };
			~btree_iterator() {};
			btree_iterator & operator++()
			{
				this->_ptr = next();
				if (this->_ptr == NULL)
					std::cout << "Nothing" << std::endl;
				return (*this);
			}
			btree_iterator operator++(int)
			{
				btree_iterator tmp(this->_ptr);
				++(*this);
				return (tmp);
			}
			btree_iterator & operator--()
			{
				this->_ptr = prev();
				if (this->_ptr == NULL)
					std::cout << "Nothing" << std::endl;
				return (*this);
			}
			btree_iterator operator--(int)
			{
				btree_iterator tmp(this->_ptr);
				--(*this);
				return (tmp);
			}
			void print() { if (this->_ptr) std::cout << this->_ptr->value.first << std::endl; };
		private:
			pointer next()
			{
				if (this->_ptr == NULL)
					return (NULL);
				pointer			left, right, tmp = this->_ptr;
				Key				value = tmp->value.first;

				while (tmp->parent)
					tmp = tmp->parent;
				left = next(tmp->left, value);
				right = next(tmp->right, value);
				if (left && left->value.first > value)
					return (left);
				else if (tmp->value.first > value)
					return (tmp);
				else if (right && right->value.first > value)
					return (right);
				return (NULL);
			};
			pointer next(pointer ptr, Key value)
			{
				if (ptr == NULL)
					return (NULL);
				pointer	left, right;

				left = next(ptr->left, value);
				right = next(ptr->right, value);
				if (left && left->value.first > value)
					return (left);
				else if (ptr->value.first > value)
					return (ptr);
				else if (right && right->value.first > value)
					return (right);
				return (NULL);
			};
			pointer prev()
			{
				return (NULL);
			};
	};
}
