/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:32:58 by bledda            #+#    #+#             */
/*   Updated: 2022/03/13 08:33:45 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <cstddef>
#include "iterator/btree_iterator.hpp"
#include "node.hpp"

#define TEMPLATE			template <class Key, class T, class Compare, class Alloc>
#define CLASS_BTREE			ft::btree<Key, T, Compare, Alloc>
#define NODEPTR				ft::node<Key, T> *
#define ITERATOR			ft::btree_iterator<Key, T, Compare>
#define CONSTITERATOR		ft::btree_const_iterator<Key, T, Compare>
#define REFERENCE			ft::btree<Key, T, Compare, Alloc> &
#define REBIND				template rebind<node<Key, T> >::other
#define ALLOCATOR_TYPE		typename CLASS_BTREE::allocator_type
#define CLASS				TEMPLATE CLASS_BTREE
#define CLASS_TYPE(type)	TEMPLATE type CLASS_BTREE

namespace ft
{
	template <class Key, class T, class Compare, class Alloc>
	class btree
	{
		public:
			typedef typename Alloc::REBIND						allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type 			size_type;
		public:
			typedef typename node<Key, T>::type_value			type_value;
			typedef	btree_iterator<Key, T, Compare>				iterator;
			typedef	btree_const_iterator<Key, T, Compare>		const_iterator;
		public:
			typedef Compare										key_compare;
		private:
			pointer			_root;
			allocator_type	_alloc;
			unsigned int	_size;
			key_compare		_comp;
		public:
			btree(key_compare const & comp = key_compare(),
					allocator_type const & alloc = allocator_type());
			~btree();
			btree 			& operator=(btree const & rhs);
			void			insert(type_value const & value);
			void			clear();
			void			tree() const;
			int				remove(Key const & key);
			node<Key, T>	*search(Key const & key) const;
			bool			exist(Key const & key) const;
			unsigned int	size() const;
			iterator		begin();
			iterator		end();
			const_iterator	begin() const;
			const_iterator	end() const;
			void			swap(btree & rhs);
			allocator_type	get_allocator() const;
		private:
			iterator		begin(node<Key, T> *leaf);
			iterator		end(node<Key, T> *leaf);
			const_iterator	begin(node<Key, T> *leaf) const;
			const_iterator	end(node<Key, T> *leaf) const;
			node<Key, T>	*search(Key const & key, node<Key, T> *leaf) const;
			void 			destroy_tree(node<Key, T> *&leaf);
			void 			insert(type_value const & value, node<Key, T> *leaf);
			void 			insert(node<Key, T> *&leaf, node<Key, T> *placing);
			int				remove(Key key, node<Key, T> *&leaf);
			void 			tree(node<Key, T> *root, std::string indent = "",
									bool right = false) const;
			void			copy(node<Key, T> *leaf);
	};
}

CLASS_TYPE(void)::swap(btree & rhs)
{
	unsigned int	tmp_size;
	node<Key, T>	*tmp_root;
	allocator_type	tmp_alloc;
	key_compare		tmp_comp;

	tmp_size = rhs._size;
	rhs._size = _size;
	_size = tmp_size;

	tmp_root = rhs._root;
	rhs._root = _root;
	_root = tmp_root;

	tmp_alloc = rhs._alloc;
	rhs._alloc = _alloc;
	_alloc = tmp_alloc;

	tmp_comp = rhs._comp;
	rhs._comp = _comp;
	_comp = tmp_comp;
}

CLASS::btree(key_compare const & comp, allocator_type const & alloc)
{
	_alloc = alloc;
	_root = NULL;
	_size = 0;
	_comp = comp;
}

CLASS::~btree() { clear(); }

CLASS_TYPE(ALLOCATOR_TYPE)::get_allocator() const { return (_alloc); }

CLASS_TYPE(REFERENCE)::operator=(ft::btree<Key, T, Compare, Alloc> const & rhs)
{
	if (this != &rhs)
	{
		clear();
		if (rhs._root != NULL)
		{
			copy(rhs._root);
			copy(rhs._root->left);
			copy(rhs._root->right);
			_size = rhs._size;
			_alloc = rhs._alloc;
		}
	}
	return (*this);
};

CLASS_TYPE(void)::copy(node<Key, T> *leaf)
{
	if (leaf != NULL)
	{
		insert(leaf->value);
		copy(leaf->left);
		copy(leaf->right);
	}
}

CLASS_TYPE(ITERATOR)::begin()
{
	if (_root == NULL)
		return (ITERATOR(NULL));
	if (_root->left == NULL)
		return (ITERATOR(_root));
	else
		return (begin(_root->left));
}

CLASS_TYPE(ITERATOR)::begin(node<Key, T> *leaf)
{
	if (leaf->left == NULL)
		return (ITERATOR(leaf));
	else
		return (begin(leaf->left));
}

CLASS_TYPE(ITERATOR)::end()
{
	if (_root == NULL)
		return (ITERATOR(NULL));
	if (_root->right == NULL)
		return (ITERATOR(_root));
	else
		return (end(_root->right));
}

CLASS_TYPE(ITERATOR)::end(node<Key, T> *leaf)
{
	if (leaf->right == NULL)
		return (ITERATOR(leaf));
	else
		return (end(leaf->right));
}

CLASS_TYPE(CONSTITERATOR)::begin() const
{
	if (_root == NULL)
		return (CONSTITERATOR(NULL));
	if (_root->left == NULL)
		return (CONSTITERATOR(_root));
	else
		return (begin(_root->left));
}

CLASS_TYPE(CONSTITERATOR)::begin(node<Key, T> *leaf) const
{
	if (leaf->left == NULL)
		return (CONSTITERATOR(leaf));
	else
		return (begin(leaf->left));
}

CLASS_TYPE(CONSTITERATOR)::end() const
{
	if (_root == NULL)
		return (CONSTITERATOR(NULL));
	if (_root->right == NULL)
		return (CONSTITERATOR(_root));
	else
		return (end(_root->right));
}

CLASS_TYPE(CONSTITERATOR)::end(node<Key, T> *leaf) const
{
	if (leaf->right == NULL)
		return (CONSTITERATOR(leaf));
	else
		return (end(leaf->right));
}

CLASS_TYPE(unsigned int)::size() const { return (_size); }

CLASS_TYPE(bool)::exist(Key const & key) const
{ return (search(key) != NULL); }

CLASS_TYPE(NODEPTR)::search(Key const & key) const
{
	if (_root == NULL)
		return (NULL);
	else if (key == _root->value.first)
		return (_root);
	else if (_comp(key, _root->value.first))
		return (search(key, _root->left));
	return (search(key, _root->right));
}

CLASS_TYPE(NODEPTR)::search(Key const & key, node<Key, T> *leaf) const
{
	if (leaf == NULL)
		return (NULL);
	else if (key == leaf->value.first)
		return (leaf);
	else if (_comp(key, leaf->value.first))
		return (search(key, leaf->left));
	return (search(key, leaf->right));
}

CLASS_TYPE(void)::insert(type_value const & value)
{
	if(_root != NULL)
		insert(value, _root);
	else
	{
		_root = _alloc.allocate(1);
		_alloc.construct(_root, ft::node<Key, T>(value, NULL, NULL, NULL));
		_size++;
	}
}

CLASS_TYPE(void)::insert(type_value const & value, node<Key, T> *leaf)
{
	if (_comp(value.first, leaf->value.first))
	{
		if(leaf->left != NULL)
			insert(value, leaf->left);
		else
		{
			leaf->left = _alloc.allocate(1);
			_alloc.construct(leaf->left, ft::node<Key, T>(value, NULL, NULL, leaf));
			_size++;
		}  
	}
	else if (_comp(leaf->value.first, value.first))
	{
		if(leaf->right != NULL)
			insert(value, leaf->right);
		else
		{
			leaf->right = _alloc.allocate(1);
			_alloc.construct(leaf->right, ft::node<Key, T>(value, NULL, NULL, leaf));
			_size++;
		}
	}
}

CLASS_TYPE(void)::insert(node<Key, T> *&leaf, node<Key, T> *placing)
{
	if (leaf == NULL || placing == NULL)
		return ;
	if (_comp(placing->value.first, leaf->value.first))
	{
		if (leaf->left == NULL)
		{
			placing->parent = leaf;
			leaf->left = placing;
		}
		else
			insert(leaf->left, placing);
	}
	else if (_comp(leaf->value.first, placing->value.first))
	{
		if (leaf->right == NULL)
		{
			placing->parent = leaf;
			leaf->right = placing;
		}
		else
			insert(leaf->right, placing);
	}
}

CLASS_TYPE(int)::remove(Key const & key)
{
	if (_root != NULL)
	{
		if (key == _root->value.first)
		{
			_size--;
			node<Key, T>	*left = _root->left,
							*right = _root->right;

			_alloc.destroy(_root);
			_alloc.deallocate(_root, 1);
			_root = ((left != NULL) ? left : right);
			if (_root != NULL)
			{
				_root->parent = NULL;
				insert(_root, (left != NULL) ? right : left);
			}
			return (1);
		}
		else if (_comp(key, _root->value.first))
			return (remove(key, _root->left));
		else if (_comp(_root->value.first, key))
			return (remove(key, _root->right));
	}
	return (0);
}

CLASS_TYPE(int)::remove(Key key, node<Key, T> *&leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->value.first)
		{
			_size--;
			node<Key, T>	*left = leaf->left,
							*right = leaf->right,
							*parent = leaf->parent;

			_alloc.destroy(leaf);
			_alloc.deallocate(leaf, 1);
			leaf = ((left != NULL) ? left : right);
			if (leaf != NULL)
			{
				if (_comp(leaf->value.first, parent->value.first))
					parent->left = leaf;
				else if (_comp(parent->value.first, leaf->value.first))
					parent->right = leaf;
				leaf->parent = parent;
				insert(leaf, (left != NULL) ? right : left);
			}
			return (1);
		}
		else if (_comp(key, leaf->value.first))
			return (remove(key, leaf->left));
		else if (_comp(leaf->value.first, key))
			return (remove(key, leaf->right));
	}
	return (0);
}

CLASS_TYPE(void)::clear() { destroy_tree(_root); }

CLASS_TYPE(void)::destroy_tree(node<Key, T> *&leaf)
{
	if(leaf != NULL)
	{
		_size--;
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		_alloc.destroy(leaf);
		_alloc.deallocate(leaf, 1);
		leaf = NULL;
	}
}

CLASS_TYPE(void)::tree() const { tree(_root); }

CLASS_TYPE(void)::tree(node<Key, T> *root, std::string indent, bool right) const
{
	if (root == NULL)
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
	std::cout << root->value.first << std::endl;
	tree(root->left, indent, false);
	tree(root->right, indent, true);
}
