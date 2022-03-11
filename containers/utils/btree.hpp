/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:32:58 by bledda            #+#    #+#             */
/*   Updated: 2022/03/11 20:34:58 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <cstddef>
#include "iterator/btree_iterator.hpp"
#include "node.hpp"

#define TEMPLATE			template <class Key, class T, class Alloc>
#define CLASS_BTREE			ft::btree<Key, T, Alloc>
#define NODEPTR				ft::node<Key, T> *
#define ITERATOR			ft::btree_iterator<Key, T>
#define CONSTITERATOR		ft::btree_const_iterator<Key, T>
#define REFERENCE			ft::btree<Key, T, Alloc> &
#define REBIND				template rebind<node<Key, T> >::other
#define CLASS				TEMPLATE CLASS_BTREE
#define CLASS_TYPE(type)	TEMPLATE type CLASS_BTREE

namespace ft
{
	template <class Key, class T, class Alloc>
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
			typedef	btree_iterator<Key, T>						iterator;
			typedef	btree_const_iterator<Key, T>				const_iterator;
		private:
			pointer			_root;
			allocator_type	_alloc;
			unsigned int	_size;
		public:
			btree(const allocator_type& alloc = allocator_type());
			~btree();
			btree 			& operator=(btree const & rhs);
			void			insert(type_value value);
			void			clear();
			void			tree() const;
			int				remove(Key key);
			node<Key, T>	*search(Key key) const;
			bool			exist(Key key) const;
			unsigned int	size() const;
			iterator		begin();
			iterator		end();
			const_iterator	begin() const;
			const_iterator	end() const;
			void			swap(btree & rhs);
		private:
			iterator		begin(node<Key, T> *leaf);
			iterator		end(node<Key, T> *leaf);
			const_iterator	begin(node<Key, T> *leaf) const;
			const_iterator	end(node<Key, T> *leaf) const;
			node<Key, T>	*search(Key key, node<Key, T> *leaf) const;
			void 			destroy_tree(node<Key, T> *&leaf);
			void 			insert(type_value value, node<Key, T> *leaf);
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

	tmp_size = rhs._size;
	rhs._size = _size;
	_size = tmp_size;

	tmp_root = rhs._root;
	rhs._root = _root;
	_root = tmp_root;
}

CLASS::btree(const allocator_type & alloc)
{
	_alloc = alloc;
	_root = NULL;
	_size = 0;
}

CLASS::~btree() { clear(); }

CLASS_TYPE(REFERENCE)::operator=(ft::btree<Key, T, Alloc> const & rhs)
{
	if (this != &rhs)
	{
		clear();
		if (rhs._root != NULL)
		{
			copy(rhs._root);
			copy(rhs._root->left);
			copy(rhs._root->right);
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

CLASS_TYPE(bool)::exist(Key key) const { return (search(key) != NULL); }

CLASS_TYPE(NODEPTR)::search(Key key) const
{
	if (_root == NULL)
		return (NULL);
	else if (key == _root->value.first)
		return (_root);
	else if (key < _root->value.first)
		return (search(key, _root->left));
	return (search(key, _root->right));
}

CLASS_TYPE(NODEPTR)::search(Key key, node<Key, T> *leaf) const
{
	if (leaf == NULL)
		return (NULL);
	else if (key == leaf->value.first)
		return (leaf);
	else if (key < leaf->value.first)
		return (search(key, leaf->left));
	return (search(key, leaf->right));
}

CLASS_TYPE(void)::insert(type_value value)
{
	if(_root != NULL)
		insert(value, _root);
	else
	{
		_root = _alloc.allocate(1);
		_root->value = value;
		_root->left = NULL;
		_root->right = NULL;
		_root->parent = NULL;
		_size++;
	}
}

CLASS_TYPE(void)::insert(type_value value, node<Key, T> *leaf)
{
	if(value.first < leaf->value.first)
	{
		if(leaf->left != NULL)
			insert(value, leaf->left);
		else
		{
			leaf->left = _alloc.allocate(1);
			leaf->left->value = value;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
			leaf->left->parent = leaf;
			_size++;
		}  
	}
	else if(value.first > leaf->value.first)
	{
		if(leaf->right != NULL)
			insert(value, leaf->right);
		else
		{
			leaf->right = _alloc.allocate(1);
			leaf->right->value = value;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
			leaf->right->parent = leaf;
			_size++;
		}
	}
}

CLASS_TYPE(void)::insert(node<Key, T> *&leaf, node<Key, T> *placing)
{
	if (leaf == NULL || placing == NULL)
		return ;
	if (placing->value.first < leaf->value.first)
	{
		if (leaf->left == NULL)
		{
			placing->parent = leaf;
			leaf->left = placing;
		}
		else
			insert(leaf->left, placing);
	}
	else if (placing->value.first > leaf->value.first)
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

CLASS_TYPE(int)::remove(Key key)
{
	if (_root != NULL)
	{
		if (key == _root->value.first)
		{
			_size--;
			node<Key, T>	*left = _root->left,
							*right = _root->right;

			_alloc.deallocate(_root, 1);
			_root = ((left != NULL) ? left : right);
			if (_root != NULL)
				_root->parent = NULL;
			insert(_root, (left != NULL) ? right : left);
			return (1);
		}
		else if (key < _root->value.first)
			return (remove(key, _root->left));
		else if (key > _root->value.first)
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

			_alloc.deallocate(leaf, 1);
			leaf = ((left != NULL) ? left : right);
			if (leaf == NULL)
				return (1);
			if (leaf->value.first < parent->value.first)
				parent->left = leaf;
			else if (leaf->value.first > parent->value.first)
				parent->right = leaf;
			if (leaf != NULL)
				leaf->parent = parent;
			insert(leaf, (left != NULL) ? right : left);
			return (1);
		}
		else if (key < leaf->value.first)
			return (remove(key, leaf->left));
		else if (key > leaf->value.first)
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
