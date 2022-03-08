/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:32:58 by bledda            #+#    #+#             */
/*   Updated: 2022/03/08 20:39:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <cstddef>
#include "../utils/utility.hpp"

#define CLASS				template <class Key, class T, class Alloc> ft::btree<Key, T, Alloc>
#define CLASS_TYPE(type)	template <class Key, class T, class Alloc> type ft::btree<Key, T, Alloc>
#define CLASS_PTR_NODE		template <class Key, class T, class Alloc> ft::node<Key, T> * ft::btree<Key, T, Alloc>

namespace ft
{
	template <class Key, class T>
	struct node
	{
		typedef pair<Key, T> type_value;

		type_value		value;
		node			*left;
		node			*right;
		node			*parent;
	};
}

namespace ft
{
	template <class Key, class T, class Alloc = std::allocator<node<Key, T> > >
	class btree
	{
		public:
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type 			size_type;
			typedef typename node<Key, T>::type_value			type_value;
		private:
			pointer			_root;
			allocator_type	_alloc;
			unsigned int	_size;
		public:
			btree(const allocator_type& alloc = allocator_type());
			~btree();
	
			void insert(type_value value);
			void clear();
			void tree() const;
			void remove(Key key);
			node<Key, T> *search(Key key) const;
			bool exist(Key key) const;
			unsigned int size() const;
		private:
			node<Key, T> *search(Key key, node<Key, T> *leaf) const;
			void destroy_tree(node<Key, T> *&leaf);
			void insert(type_value value, node<Key, T> *leaf);
			void insert(node<Key, T> *&leaf, node<Key, T> *&placing);
			void remove(Key key, node<Key, T> *&leaf);
			void tree(node<Key, T> *root, std::string indent = "", bool right = false) const;
	};
}

CLASS::btree(const Alloc & alloc)
{
	_alloc = alloc;
	_root = NULL;
	_size = 0;
}

CLASS::~btree() { clear(); }

CLASS_TYPE(unsigned int)::size() const { return (_size); }

CLASS_TYPE(bool)::exist(Key key) const { return (search(key) != NULL); }

CLASS_PTR_NODE::search(Key key) const
{
	if (_root == NULL)
		return (NULL);
	else if (key == _root->value.first)
		return (_root);
	else if (key < _root->value.first)
		return (search(key, _root->left));
	return (search(key, _root->right));
}

CLASS_PTR_NODE::search(Key key, node<Key, T> *leaf) const
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
	else if (value.first == leaf->value.first)
	{
		leaf->value.second = value.second;
	}
}

CLASS_TYPE(void)::insert(node<Key, T> *&leaf, node<Key, T> *&placing)
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

CLASS_TYPE(void)::remove(Key key)
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
			insert(_root, (left != NULL) ? right : left);
		}
		else if (key < _root->value.first)
			remove(key, _root->left);
		else if (key > _root->value.first)
			remove(key, _root->right);
	}
}

CLASS_TYPE(void)::remove(Key key, node<Key, T> *&leaf)
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
				return ;
			if (leaf->value.first < parent->value.first)
				parent->left = leaf;
			else if (leaf->value.first > parent->value.first)
				parent->right = leaf;
			insert(leaf, (left != NULL) ? right : left);
		}
		else if (key < leaf->value.first)
			remove(key, leaf->left);
		else if (key > leaf->value.first)
			remove(key, leaf->right);
	}
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
