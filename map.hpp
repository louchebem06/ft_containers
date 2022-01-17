/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:04:33 by bledda            #+#    #+#             */
/*   Updated: 2022/01/17 19:09:55 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>
#include "utils/type_traits.hpp"
#include "utils/iterator.hpp"
#include "utils/functional.hpp"
#include "utils/utility.hpp"

namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key, T> > >
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
			typedef ft::bidirectional_iterator<T>						iterator;
			typedef ft::bidirectional_iterator<const T>					const_iterator;
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
		public:
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				(void)comp;
				(void)alloc;
			};

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				(void)first;
				(void)last;
				(void) comp;
				(void) alloc;
			};
			map (const map& x) { (void)x; };

			~map() {};

			map& operator= (const map& x) { (void)x; };

			iterator begin() {};
			const_iterator begin() const {};

			iterator end() {};
			const_iterator end() const {};

			reverse_iterator rbegin() {};
			const_reverse_iterator rbegin() const {};

			reverse_iterator rend() {};
			const_reverse_iterator rend() const {};

			bool empty() const {};

			size_type size() const {};

			size_type max_size() const {};

			mapped_type& operator[] (const key_type& k) { (void)k; };

			ft::pair<iterator, bool> insert (const value_type& val) {
				(void)val;
			};
			
			iterator insert (iterator position, const value_type& val) {
				(void)position;
				(void)val;
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

			iterator find (const key_type& k) {
				(void)k;
			};
			const_iterator find (const key_type& k) const {
				(void)k;
			};

			size_type count (const key_type& k) const {
				(void)k;
			};

			iterator lower_bound (const key_type& k) {
				(void)k;
			};
			const_iterator lower_bound (const key_type& k) const {
				(void)k;
			};

			iterator upper_bound (const key_type& k) {
				(void)k;
			};
			const_iterator upper_bound (const key_type& k) const {
				(void)k;
			};

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				(void)k;
			};
			pair<iterator,iterator> equal_range (const key_type& k) {
				(void)k;
			};

			allocator_type get_allocator() const {};
	};
}
