/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:32:55 by bledda            #+#    #+#             */
/*   Updated: 2022/03/12 23:37:10 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterator.hpp"
#include <iostream>
#include "../node.hpp"

namespace ft
{
	template <class Key, class T, class Compare>
	class move : public iterator<bidirectional_iterator_tag, ft::node<Key, T> >
	{
		protected:
			typedef Compare		key_compare;
			key_compare			_comp;
		protected:
			ft::node<Key, T> * next()
			{
				if (this->_ptr == NULL)
					return (NULL);
				ft::node<Key, T>	*tmp = this->_ptr;
				Key					value = tmp->value.first;

				if (tmp->right)
				{
					tmp = tmp->right;
					while (tmp->left && _comp(value, tmp->left->value.first))
						tmp = tmp->left;
				}
				else if (tmp->parent && _comp(value, tmp->parent->value.first))
				{
					while (tmp->parent && _comp(value, tmp->parent->value.first))
					{
						tmp = tmp->parent;
						if (tmp->parent
							&& _comp(tmp->value.first, tmp->parent->value.first))
							break;
					}
				}
				else if (tmp->parent && !_comp(value, tmp->parent->value.first))
				{
					Key tmp_key = tmp->value.first;

					while (tmp->parent && !_comp(value, tmp->parent->value.first))
						tmp = tmp->parent;
					if (tmp->parent)
						tmp = tmp->parent;
					if (_comp(tmp->value.first, tmp_key))
						return (NULL);
				}
				else
					return (NULL);
				return (tmp);
			}
			
			ft::node<Key, T> * prev()
			{
				if (this->_ptr == NULL)
					return (NULL);
				ft::node<Key, T> 	*tmp = this->_ptr;
				Key					value = tmp->value.first;

				if (tmp->left)
				{
					tmp = tmp->left;
					while (tmp->right && _comp(tmp->right->value.first, value))
						tmp = tmp->right;
				}
				else if (tmp->parent)
				{
					while (tmp->parent && _comp(value, tmp->parent->value.first))
						tmp = tmp->parent;
					tmp = tmp->parent;
				}
				return (tmp);
			}
	};
}

namespace ft
{
	template <class Key, class T, class Compare>
	class btree_iterator : public move<Key, T, Compare>
	{
		protected:
			typedef iterator<bidirectional_iterator_tag,
					ft::node<Key, T> >						iterator;
		public:
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename ft::pair<Key, T> *				pointer;
			typedef typename ft::pair<Key, T> &				reference;
			typedef Compare									key_compare;
		private:
			bool				_end;
			bool				_begin;
			ft::node<Key, T> *	_save;
		public:
			ft::node<Key, T> * base() { return (this->_ptr); }
		public:
			btree_iterator() : _end(false), _begin(false)
			{ this->_ptr = NULL; };
			btree_iterator(ft::node<Key, T> *leaf) : _end(false), _begin(false) {
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
					this->_ptr = this->next();
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
					this->_ptr = this->prev();
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
				return (this->_ptr->value.first != rhs._ptr->value.first);
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
	};
}

namespace ft
{
	template <class Key, class T, class Compare>
	class btree_const_iterator : public move<Key, T, Compare>
	{
		protected:
			typedef iterator<bidirectional_iterator_tag,
					ft::node<Key, T> >						iterator;
		public:
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename ft::pair<Key, T> const *		pointer;
			typedef typename ft::pair<Key, T> const & 		reference;
			typedef Compare									key_compare;
		private:
			bool				_end;
			bool				_begin;
			ft::node<Key, T> *	_save;
		public:
			btree_const_iterator() : _end(false), _begin(false)
			{ this->_ptr = NULL; };
			btree_const_iterator(ft::node<Key, T> *leaf) : _end(false), _begin(false) {
				if (leaf == NULL)
				{
					_end = true;
					_begin = true;
				}
				else
					this->_ptr = leaf;
			};
			btree_const_iterator(btree_iterator<Key, T, Compare> it) : _end(false), _begin(false) {
				if (it.base() == NULL)
				{
					_end = true;
					_begin = true;
				}
				else
					this->_ptr = it.base();
			};
			~btree_const_iterator() {};
			btree_const_iterator & operator++()
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
					this->_ptr = this->next();
					if (this->_ptr == NULL)
						_end = true;
				}
				return (*this);
			}
			btree_const_iterator operator++(int)
			{
				btree_const_iterator tmp(this->_ptr);
				++(*this);
				return (tmp);
			}
			btree_const_iterator & operator--()
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
					this->_ptr = this->prev();
					if (this->_ptr == NULL)
						_begin = true;
				}
				return (*this);
			}
			btree_const_iterator operator--(int)
			{
				btree_const_iterator tmp(this->_ptr);
				--(*this);
				return (tmp);
			}
			bool operator!=(btree_const_iterator const & rhs) const
			{
				if (rhs._end)
					return (this->_end != rhs._end);
				else if (rhs._begin)
					return (this->_begin != rhs._begin);
				return (this->_ptr->value.first != rhs._ptr->value.first);
			}
			bool operator==(btree_const_iterator const & rhs) const
			{
				return (this->_ptr == rhs._ptr);
			}
			ft::pair<Key, T> const & operator*() const
			{
				return (*(operator->()));
			}
			ft::pair<Key, T> const * operator->() const
			{
				return ((ft::pair<Key, T> *)&this->_ptr->value);
			}
	};
}
