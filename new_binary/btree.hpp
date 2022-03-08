/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:32:58 by bledda            #+#    #+#             */
/*   Updated: 2022/03/08 19:45:29 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <cstddef>

#define CLASS				template <class Alloc> ft::btree<Alloc>
#define CLASS_TYPE(type)	template <class Alloc> type ft::btree<Alloc>

namespace ft
{
	struct node
	{
		int		key_value;
		node	*left;
		node	*right;
		node	*parent;
	};
}

namespace ft
{
	template <class Alloc = std::allocator<node> >
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
		private:
			pointer			_root;
			allocator_type	_alloc;
			unsigned int	_size;
		public:
			btree(const allocator_type& alloc = allocator_type());
			~btree();
	
			void insert(int key);
			void clear();
			void tree();
			void remove(int key);
			node *search(int key) const;
			bool exist(int key) const;
			unsigned int size() const;
		private:
			node *search(int key, node *leaf) const;
			void destroy_tree(node *&leaf);
			void insert(int key, node *leaf);
			void insert(node *&leaf, node *&placing);
			void remove(int key, node *&leaf);
			void tree(node *root, std::string indent = "", bool right = false);
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

CLASS_TYPE(bool)::exist(int key) const { return (search(key) != NULL); }

CLASS_TYPE(ft::node *)::search(int key) const
{
	if (_root == NULL)
		return (NULL);
	else if (key == _root->key_value)
		return (_root);
	else if (key < _root->key_value)
		return (search(key, _root->left));
	return (search(key, _root->right));
}

CLASS_TYPE(ft::node *)::search(int key, node *leaf) const
{
	if (leaf == NULL)
		return (NULL);
	else if (key == leaf->key_value)
		return (leaf);
	else if (key < leaf->key_value)
		return (search(key, leaf->left));
	return (search(key, leaf->right));
}

CLASS_TYPE(void)::insert(int key)
{
	if(_root != NULL)
		insert(key, _root);
	else
	{
		_root = _alloc.allocate(1);
		_root->key_value = key;
		_root->left = NULL;
		_root->right = NULL;
		_root->parent = NULL;
		_size++;
	}
}

CLASS_TYPE(void)::insert(int key, node *leaf)
{
	if(key < leaf->key_value)
	{
		if(leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left = _alloc.allocate(1);
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
			leaf->left->parent = leaf;
			_size++;
		}  
	}
	else if(key > leaf->key_value)
	{
		if(leaf->right != NULL)
			insert(key, leaf->right);
		else
		{
			leaf->right = _alloc.allocate(1);
			leaf->right->key_value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
			leaf->right->parent = leaf;
			_size++;
		}
	}
	else if (key == leaf->key_value)
		return ;
}

CLASS_TYPE(void)::insert(node *&leaf, node *&placing)
{
	if (leaf == NULL || placing == NULL)
		return ;
	if (placing->key_value < leaf->key_value)
	{
		if (leaf->left == NULL)
		{
			placing->parent = leaf;
			leaf->left = placing;
			_size++;
		}
		else
			insert(leaf->left, placing);
	}
	else if (placing->key_value > leaf->key_value)
	{
		if (leaf->right == NULL)
		{
			placing->parent = leaf;
			leaf->right = placing;
			_size++;
		}
		else
			insert(leaf->right, placing);
	}
}

CLASS_TYPE(void)::remove(int key)
{
	if (_root != NULL)
	{
		if (key == _root->key_value)
		{
			_size--;
			node	*left = _root->left,
					*right = _root->right;

			_alloc.deallocate(_root, 1);
			_root = ((left != NULL) ? left : right);
			insert(_root, (left != NULL) ? right : left);
		}
		else if (key < _root->key_value)
			remove(key, _root->left);
		else if (key > _root->key_value)
			remove(key, _root->right);
	}
}

CLASS_TYPE(void)::remove(int key, node *&leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key_value)
		{
			_size--;
			node	*left = leaf->left,
					*right = leaf->right,
					*parent = leaf->parent;

			_alloc.deallocate(leaf, 1);
			leaf = ((left != NULL) ? left : right);
			if (leaf == NULL)
				return ;
			if (leaf->key_value < parent->key_value)
				parent->left = leaf;
			else if (leaf->key_value > parent->key_value)
				parent->right = leaf;
			insert(leaf, (left != NULL) ? right : left);
		}
		else if (key < leaf->key_value)
			remove(key, leaf->left);
		else if (key > leaf->key_value)
			remove(key, leaf->right);
	}
}

CLASS_TYPE(void)::clear() { destroy_tree(_root); }

CLASS_TYPE(void)::destroy_tree(node *&leaf)
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

CLASS_TYPE(void)::tree() { tree(_root); }

CLASS_TYPE(void)::tree(node *root, std::string indent, bool right)
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
	std::cout << root->key_value << std::endl;
	tree(root->left, indent, false);
	tree(root->right, indent, true);
}
