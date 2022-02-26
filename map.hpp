/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:04:33 by bledda            #+#    #+#             */
/*   Updated: 2022/02/26 15:34:45 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>
#include "utils/type_traits.hpp"
#include "utils/iterator.hpp"
#include "utils/functional.hpp"
#include "utils/utility.hpp"
#include "utils/node.hpp"

namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key>,
		class Alloc = std::allocator<ft::B_tree<const Key, T> > >
	class map
	{
		public:
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::pair<const key_type, mapped_type>				value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename ft::B_tree<Key, T>							iterator;
			typedef typename ft::B_tree<Key, T>							const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type 					size_type;
		public:
			// Official <map> and docs cplusplus.com
			class value_compare : public ft::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					key_compare comp;
					value_compare(key_compare c) : comp(c) {};
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
				public:
					bool operator()(const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					};
			};
		private:
			ft::B_tree<Key, T>	_node;
			key_compare			_comp;
			allocator_type		_alloc;
			size_type			_size;
		public:
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				_size = 0;
				_node = 0;
				_comp = comp;
				_alloc = alloc;
			};

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				_size = 0;
				_alloc = alloc;
				_comp = comp;
				_node = 0;
				for (; first != last; first++)
				{
					_size++;
					_node.insert(*first);
				}
			};
			map (const map& x) {
				_node = 0;
				*this = x;
			};

			~map() {};

			map& operator=(const map& x)
			{
				if (_node.getRoot() != x._node.getRoot())
				{
					_node = x._node;
				}
				return (*this);
			};

			iterator begin() {
				return (_node.begin());
			};
			const_iterator begin() const {
				return (_node.begin());
			};

			iterator end() {
				return (_node.end());
			};
			const_iterator end() const {
				return (_node.end());
			};

			reverse_iterator rbegin() {
				return (reverse_iterator(_node->end()));
			};
			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(_node->end()));
			};

			reverse_iterator rend() {
				return (reverse_iterator(_node->begin()));
			};
			const_reverse_iterator rend() const {
				return (const_reverse_iterator(_node->begin()));
			};

			bool empty() const {
				return (true);
			};

			size_type size() const {
				return (_size);
			};

			size_type max_size() const {
				return (this->_alloc.max_size());
			};

			mapped_type& operator[] (const key_type& k)
			{
				B_tree<Key, T> t(_node.find(k));
				mapped_type tmp;

				if (t.getPtr() == 0)
					_node.insert(value_type(k, tmp));
				return (_node.find(k)->data.second);
			};

			iterator find (const key_type& k) {_node.find(k);};
			const_iterator find (const key_type& k) const {
				return (_node.find(k));
			};

			ft::pair<iterator, bool> insert (const value_type& val)
			{
				_node.insert(val);
				return (ft::pair<iterator, bool>(0, false));
			};
			
			iterator insert (iterator position, const value_type& val) {
				(void)position;
				this->insert(val);
				return (position);
			};
			
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				(void)first;
				(void)last;
			};

			void erase (iterator position) { 
				(void)position;
			};
			size_type erase (const key_type& k) {
				(void)k;
			};
			void erase (iterator first, iterator last) {
				(void)first;
				(void)last;
			};

			void swap (map& x) {
				(void)x;
			};

			void clear() {};

			key_compare key_comp() const {};

			value_compare value_comp() const {};

			size_type count (const key_type& k) const
			{
				if (_node.find(k) != 0)
					return (1);
				return (0);
			};

			iterator lower_bound(const key_type& k)
			{
				map::iterator it = this->begin();
				for (;it != this->end(); it++)
				{
					if ((*it).first >= k)
						return (it);
				}
				return (this->end());
			};
			const_iterator lower_bound (const key_type& k) const
			{
				map::iterator it = this->begin();
				for (;it != this->end(); it++)
				{
					if ((*it).first >= k)
						return (it);
				}
				return (this->end());
			};

			iterator upper_bound(const key_type& k)
			{
				map::iterator it = this->begin();
				for (;it != this->end(); it++)
				{
					if ((*it).first > k)
						return (it);
				}
				return (this->end());
			};
			const_iterator upper_bound (const key_type& k) const
			{
				map::iterator it = this->begin();
				for (;it != this->end(); it++)
				{
					if ((*it).first > k)
						return (it);
				}
				return (this->end());
			};

			pair<iterator, iterator> equal_range(const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			};
			pair<const_iterator, const_iterator> equal_range (const key_type& k) const {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			};

			allocator_type get_allocator() const {
				return (_alloc);
			};
	};
}
