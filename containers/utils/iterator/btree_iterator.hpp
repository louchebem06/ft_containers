/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:32:55 by bledda            #+#    #+#             */
/*   Updated: 2022/03/14 06:18:38 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterator.hpp"
#include <iostream>
#include "../node.hpp"

#define TEMPLATE_BTREE_ITERATOR	template <class Key, class T, class Compare>
#define NODEPTR					ft::node<Key, T> *

#define CLASSMOVE				ft::move<Key, T, Compare>
#define CLASSMOVE_TYPE(type)	TEMPLATE_BTREE_ITERATOR type CLASSMOVE

#define IT						ft::btree_iterator<Key, T, Compare>
#define CLASS_IT				TEMPLATE_BTREE_ITERATOR IT
#define CLASS_IT_TYPE(type)		TEMPLATE_BTREE_ITERATOR type IT
#define REFERENCE_IT			IT &

#define C_IT					ft::btree_const_iterator<Key, T, Compare>
#define CLASS_C_IT				TEMPLATE_BTREE_ITERATOR C_IT
#define CLASS_C_IT_TYPE(type)	TEMPLATE_BTREE_ITERATOR type C_IT
#define REFERENCE_C_IT			C_IT &

#define REFERENCE_PAIR			ft::pair<Key, T> &
#define POINTER_PAIR			ft::pair<Key, T> *
#define REFERENCE_C_PAIR		ft::pair<Key, T> const &
#define POINTER_C_PAIR			ft::pair<Key, T> const *

#define BIT	ft::iterator<bidirectional_iterator_tag, ft::node<Key, T> >

namespace ft
{
	template <class Key, class T, class Compare>
	class move : public iterator<bidirectional_iterator_tag, ft::node<Key, T> >
	{
		public:
			typedef Compare		key_compare;
		protected:
			key_compare			_comp;
			ft::node<Key, T> * next();
			ft::node<Key, T> * prev();
	};
}

namespace ft
{
	template <class Key, class T, class Compare>
	class btree_iterator : public move<Key, T, Compare>
	{
		public:
			typedef typename BIT::value_type			value_type;
			typedef typename BIT::difference_type		difference_type;
			typedef typename BIT::iterator_category	iterator_category;
			typedef typename ft::pair<Key, T> *				pointer;
			typedef typename ft::pair<Key, T> &				reference;
		private:
			bool				_end;
			bool				_begin;
			ft::node<Key, T> *	_save;
		public:
			btree_iterator();
			btree_iterator(ft::node<Key, T> *leaf);
			btree_iterator(btree_iterator const & x);
			~btree_iterator() {};
			btree_iterator & operator++();
			btree_iterator operator++(int);
			btree_iterator & operator--();
			btree_iterator operator--(int);
			bool operator!=(btree_iterator const & rhs) const;
			bool operator==(btree_iterator const & rhs) const;
			ft::pair<Key, T> & operator*() const;
			ft::pair<Key, T> * operator->() const;
			ft::node<Key, T> * base() const;
			ft::node<Key, T> * save() const;
			bool	begin() const;
			bool	end() const;
	};
}

namespace ft
{
	template <class Key, class T, class Compare>
	class btree_const_iterator : public move<Key, T, Compare>
	{
		public:
			typedef typename BIT::value_type			value_type;
			typedef typename BIT::difference_type		difference_type;
			typedef typename BIT::iterator_category	iterator_category;
			typedef typename ft::pair<Key, T> const *		pointer;
			typedef typename ft::pair<Key, T> const & 		reference;
		private:
			bool				_end;
			bool				_begin;
			ft::node<Key, T> *	_save;
		public:
			btree_const_iterator();
			btree_const_iterator(ft::node<Key, T> *leaf);
			btree_const_iterator(btree_const_iterator const & x);
			btree_const_iterator(btree_iterator<Key, T, Compare> it);
			~btree_const_iterator() {};
			btree_const_iterator & operator++();
			btree_const_iterator operator++(int);
			btree_const_iterator & operator--();
			btree_const_iterator operator--(int);
			bool operator!=(btree_const_iterator const & rhs) const;
			bool operator==(btree_const_iterator const & rhs) const;
			ft::pair<Key, T> const & operator*() const;
			ft::pair<Key, T> const * operator->() const;
	};
}
////////////////////////////////////////////////////////////////////////////////
CLASS_IT::btree_iterator()
{
	_end = _begin = false;
	_save = this->_ptr = NULL;
}

CLASS_C_IT::btree_const_iterator()
{
	_end = _begin = false;
	_save = this->_ptr = NULL;
}
////////////////////////////////////////////////////////////////////////////////
CLASS_IT::btree_iterator(NODEPTR leaf)
{
	_save = NULL;
	_end = _begin = false;
	if (leaf == NULL)
	{
		_end = true;
		_begin = true;
	}
	else
		this->_ptr = leaf;
}

CLASS_C_IT::btree_const_iterator(NODEPTR leaf)
{
	_save = NULL;
	_end = _begin = false;
	if (leaf == NULL)
	{
		_end = true;
		_begin = true;
	}
	else
		this->_ptr = leaf;
}
////////////////////////////////////////////////////////////////////////////////
CLASS_IT::btree_iterator(btree_iterator const & x)
{
	this->_ptr = x._ptr;
	_end = x._end;
	_begin = x._begin;
	_save = x._save;
}

CLASS_C_IT::btree_const_iterator(btree_const_iterator const & x) {
	this->_ptr = x._ptr;
	_end = x._end;
	_begin = x._begin;
	_save = x._save;
}
////////////////////////////////////////////////////////////////////////////////
CLASS_C_IT::btree_const_iterator(IT it)
{
	_end = it.end();
	_begin = it.begin();
	this->_ptr = it.base();
	_save = it.save();
}
////////////////////////////////////////////////////////////////////////////////
CLASS_IT_TYPE(REFERENCE_IT)::operator++()
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

CLASS_C_IT_TYPE(REFERENCE_C_IT)::operator++()
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
////////////////////////////////////////////////////////////////////////////////
CLASS_IT_TYPE(REFERENCE_IT)::operator--()
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

CLASS_C_IT_TYPE(REFERENCE_C_IT)::operator--()
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
////////////////////////////////////////////////////////////////////////////////
CLASS_IT_TYPE(bool)::operator!=(btree_iterator const & rhs) const
{
	if (rhs._end)
		return (this->_end != rhs._end);
	else if (rhs._begin)
		return (this->_begin != rhs._begin);
	else if (this->_ptr == NULL)
	{
		if (rhs._ptr == NULL)
			return (false);
		return (true);
	}
	return (this->_ptr->value.first != rhs._ptr->value.first);
}

CLASS_C_IT_TYPE(bool)::operator!=(btree_const_iterator const & rhs) const
{	
	if (rhs._end)
		return (this->_end != rhs._end);
	else if (rhs._begin)
		return (this->_begin != rhs._begin);
	else if (this->_ptr == NULL)
	{
		if (rhs._ptr == NULL)
			return (false);
		return (true);
	}
	return (this->_ptr->value.first != rhs._ptr->value.first);
}
////////////////////////////////////////////////////////////////////////////////
CLASSMOVE_TYPE(NODEPTR)::next()
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

CLASSMOVE_TYPE(NODEPTR)::prev()
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
////////////////////////////////////////////////////////////////////////////////
CLASS_IT_TYPE(NODEPTR)::base() const { return (this->_ptr); }
CLASS_IT_TYPE(NODEPTR)::save() const { return (this->_save); }
CLASS_IT_TYPE(bool)::end() const { return (this->_end); }
CLASS_IT_TYPE(bool)::begin() const { return (this->_begin); }
////////////////////////////////////////////////////////////////////////////////
CLASS_IT_TYPE(bool)::operator==(btree_iterator const & rhs) const
{ return (this->_ptr == rhs._ptr); }

CLASS_C_IT_TYPE(bool)::operator==(btree_const_iterator const & rhs) const
{ return (this->_ptr == rhs._ptr); }
////////////////////////////////////////////////////////////////////////////////
CLASS_IT_TYPE(REFERENCE_PAIR)::operator*() const
{ return (*(operator->())); }

CLASS_C_IT_TYPE(REFERENCE_C_PAIR)::operator*() const
{ return (*(operator->())); }
////////////////////////////////////////////////////////////////////////////////
CLASS_IT_TYPE(POINTER_PAIR)::operator->() const
{ return ((ft::pair<Key, T> *)&this->_ptr->value); }

CLASS_C_IT_TYPE(POINTER_C_PAIR)::operator->() const
{ return ((ft::pair<Key, T> *)&this->_ptr->value); }
////////////////////////////////////////////////////////////////////////////////
CLASS_IT_TYPE(IT)::operator++(int)
{
	btree_iterator tmp(this->_ptr);
	++(*this);
	return (tmp);
}

CLASS_C_IT_TYPE(C_IT)::operator++(int)
{
	btree_const_iterator tmp(this->_ptr);
	++(*this);
	return (tmp);
}
////////////////////////////////////////////////////////////////////////////////
CLASS_IT_TYPE(IT)::operator--(int)
{
	btree_iterator tmp(this->_ptr);
	--(*this);
	return (tmp);
}

CLASS_C_IT_TYPE(C_IT)::operator--(int)
{
	btree_const_iterator tmp(this->_ptr);
	--(*this);
	return (tmp);
}
////////////////////////////////////////////////////////////////////////////////
