/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:32:55 by bledda            #+#    #+#             */
/*   Updated: 2022/03/11 02:38:38 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterator.hpp"
#include <iostream>
#include "../node.hpp"

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
		private:
			bool	_end;
			bool	_begin;
			pointer _save;
		public:
			btree_iterator() : _end(false), _begin(false)
			{ this->_ptr = NULL; };
			btree_iterator(pointer leaf) : _end(false), _begin(false) {
				if (leaf == NULL)
				{
					_end = true;
					_begin = true;
				}
				else
					this->_ptr = leaf;
			};
			~btree_iterator() {};
			btree_iterator & operator++()
			{
				if (!_end && !_begin)
					_save = this->_ptr;
				if (_begin)
				{
					this->_ptr = _save;
					_begin = false;
				}
				else
				{
					this->_ptr = next();
					if (this->_ptr == NULL)
						_end = true;
				}
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
				if (!_begin && !_end)
					_save = this->_ptr;
				if (_end)
				{
					this->_ptr = _save;
					_end = false;
				}
				else
				{
					this->_ptr = prev();
					if (this->_ptr == NULL)
						_begin = true;
				}
				return (*this);
			}
			btree_iterator operator--(int)
			{
				btree_iterator tmp(this->_ptr);
				--(*this);
				return (tmp);
			}
			bool operator!=(btree_iterator const & rhs) const
			{
				if (rhs._end)
					return (this->_end != rhs._end);
				else if (rhs._begin)
					return (this->_begin != rhs._begin);
				return (this->_ptr->value != rhs._ptr->value);
			}
			bool operator==(btree_iterator const & rhs) const
			{
				return (this->_ptr == rhs._ptr);
			}
			ft::pair<Key, T> & operator*() const
			{
				return (*(operator->()));
			}
			ft::pair<Key, T> * operator->() const
			{
				return ((ft::pair<Key, T> *)&this->_ptr->value);
			}
		private:
			pointer next()
			{
				if (this->_ptr == NULL)
					return (NULL);
				pointer	left, right, tmp = this->_ptr;
				Key		value = tmp->value.first;

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
				if (this->_ptr == NULL)
					return (NULL);
				pointer	tmp = this->_ptr;
				Key		value = tmp->value.first;

				if (tmp->left)
				{
					tmp = tmp->left;
					while (tmp->right && tmp->right->value.first < value)
						tmp = tmp->right;
				}
				else if (tmp->parent)
				{
					while (tmp->parent && tmp->parent->value.first > value)
						tmp = tmp->parent;
					tmp = tmp->parent;
				}
				return (tmp);
			};
	};
}
