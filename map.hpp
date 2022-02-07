/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:04:33 by bledda            #+#    #+#             */
/*   Updated: 2022/02/07 13:55:59 by bledda           ###   ########.fr       */
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
			typedef typename ft::B_tree<Key, T>			iterator;
			typedef typename ft::B_tree<Key, T>											const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			// typedef typename iterator_traits<iterator>::difference_type	difference_type;
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
			ft::B_tree<Key, T>	test;
		public:
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				(void) comp;
				(void) alloc;
				test = 0;
			};

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				(void) comp;
				(void) alloc;
				(void) first;
				(void) last;
				test = 0;
			};
			map (const map& x) {
				test = 0;
				*this = x;
			};

			~map() {};

			map& operator= (const map& x)
			{
				if (this->test.getRoot() != x.test.getRoot())
				{
					test = x.test;
				}
				return (*this);
			};

			iterator begin() {
				return (this->test.begin());
			};
			const_iterator begin() const {
				return (this->test.begin());
			};

			iterator end() {
				return (this->test.end());
			};
			const_iterator end() const {
				return (this->test.end());
			};

			reverse_iterator rbegin() {
				return (reverse_iterator(this->test->end()));
			};
			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(this->test->end()));
			};

			reverse_iterator rend() {
				return (reverse_iterator(this->test->begin()));
			};
			const_reverse_iterator rend() const {
				return (const_reverse_iterator(this->test->begin()));
			};

			bool empty() const {
				return (true);
			};

			size_type size() const {
				return (0);
			};

			size_type max_size() const {
				return (0);
			};

			mapped_type& operator[] (const key_type& k)
			{
				B_tree<Key, T> t(test.find(k));
				mapped_type tmp;

				if (t.getPtr() == 0)
					test.insert(value_type(k, tmp));
				return (test.find(k)->data.second);
			};

			iterator find (const key_type& k) {test.find(k);};
			const_iterator find (const key_type& k) const {test.find(k);};

			ft::pair<iterator, bool> insert (const value_type& val)
			{
				test.insert(val);
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

			size_type count (const key_type& k) const {
				iterator it = this->find(k);

				if (it != this->end())
					return (1);
				return (0);
			};

			iterator lower_bound (const key_type& k) {
				(void)k;
			};
			const_iterator lower_bound (const key_type& k) const {
				return (this->lower_bound(k));
			};

			iterator upper_bound (const key_type& k) {
				(void)k;
			};
			const_iterator upper_bound (const key_type& k) const {
				return (this->upper_bound(k));
			};

			pair<iterator,iterator> equal_range (const key_type& k) {
				(void)k;
			};
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return (equal_range(k));
			};

			allocator_type get_allocator() const {
				return (this->_alloc);
			};
	};
}
