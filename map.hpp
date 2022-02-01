/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:04:33 by bledda            #+#    #+#             */
/*   Updated: 2022/02/01 13:45:19 by bledda           ###   ########.fr       */
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
			typedef ft::bidirectional_iterator<ft::B_tree<const Key, T> >		iterator;
			typedef ft::bidirectional_iterator<const ft::B_tree<const Key, T> >	const_iterator;
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
			allocator_type		_alloc;
			pointer 			_ptr;
			pointer				_start;
			pointer 			_end;
			size_type			_size;
			key_compare			_key_compare;
			ft::B_tree<Key, T>	test;
		public:
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				this->_key_compare = comp;
				this->_alloc = alloc;
				this->_size = 0;
				this->_start = 0;
				this->_end = 0;
				this->_ptr = 0;
			};

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				difference_type diff = ft::distance(first, last);
				size_type		i = 0;

				this->_size = diff;
				this->_alloc = alloc;
				this->_key_compare = comp;
				this->_ptr = this->_alloc.allocate(this->_size);
				if (!this->_ptr)
					throw std::bad_alloc();
				while (first != last)
       				this->_alloc.construct(this->_ptr + i++, *first++);
				this->_start = this->_ptr;
				this->_end = this->_ptr + (this->_size - 1);
			};
			map (const map& x) {
				_alloc = x._alloc;
				_ptr = 0;
				_start = 0;
				_end = 0;
				_size = 0;
				_key_compare = x._key_compare;
				*this = x;
			};

			~map() {};

			map& operator= (const map& x) {
				if (this->_ptr != x._ptr)
				{
					allocator_type	new_alloc;
					pointer 		new_pointer;
					size_type		i = 0;

					new_pointer = new_alloc.allocate(x.size());
					if (!new_pointer)
						throw std::bad_alloc();
					for (iterator it = this->begin(); it != this->end(); it++)
						new_alloc.construct(new_pointer + i++, *it);
					this->_alloc = new_alloc;
					this->_ptr = new_pointer;
					this->_start = new_pointer;
					this->_end = new_pointer + (x.size() - 1);
					this->_size = x._size;
					this->_key_compare = x._key_compare;
				}
				return (*this);
			};

			iterator begin() {
				return (iterator(this->_start));
			};
			const_iterator begin() const {
				return (const_iterator(this->_start));
			};

			iterator end() {
				return (iterator(this->_end + 1));
			};
			const_iterator end() const {
				return (const_iterator(this->_end + 1));
			};

			reverse_iterator rbegin() {
				return (reverse_iterator(this->end()));
			};
			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(this->end()));
			};

			reverse_iterator rend() {
				return (reverse_iterator(this->begin()));
			};
			const_reverse_iterator rend() const {
				return (const_reverse_iterator(this->begin()));
			};

			bool empty() const {
				if (this->size() == 0)
					return (true);
				return (false);
			};

			size_type size() const {
				return (this->_size);
			};

			size_type max_size() const {
				return (this->_alloc.max_size());
			};

			mapped_type& operator[] (const key_type& k)
			{
				B_tree<Key, T> t(test.find(k));
				mapped_type tmp;

				if (t.getPtr() == 0)
					test.insert(value_type(k, tmp));
				return (test.find(k)->data.second);
			};

			iterator find (const key_type& k) {
				std::cout << "find" << std::endl;
				(void)k;
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					std::cout << "start it" << std::endl;
					if ((*it).first == k)
					{
						std::cout << "return it" << std::endl;
						return (it);
					}
					std::cout << "next it" << std::endl;
				}
				return (this->end());
			};
			const_iterator find (const key_type& k) const {
				for (const_iterator it = this->begin(); it != this->end(); it++)
				{
					if (*it.first == k)
						return (it);
				}
				return (this->end());
			};

			ft::pair<iterator, bool> insert (const value_type& val)
			{
				test.insert(val);
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
