/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:04:33 by bledda            #+#    #+#             */
/*   Updated: 2022/03/12 20:50:29 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>
#include "utils/type_traits.hpp"
#include "utils/iterator.hpp"
#include "utils/utility.hpp"
#include "utils/btree.hpp"
#include "utils/algorithm.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>,
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
			typedef typename ft::btree<Key, T, Compare, Alloc>::iterator			iterator;
			typedef typename ft::btree<Key, T, Compare, Alloc>::const_iterator	const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type 					size_type;
		public:
			// Official <map> and docs cplusplus.com
			class value_compare : public std::binary_function<value_type, value_type, bool>
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
			ft::btree<Key, T, Compare, Alloc>	_node;
			allocator_type						_alloc;
			key_compare							_comp;
		public:
			void tree() const { _node.tree(); } // a remove
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
			};

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_comp = comp;
				for (; first != last; first++)
					_node.insert(*first);
			};
			map (const map & x)
			{
				*this = x;
			};

			~map() { _node.clear(); };

			map & operator=(const map& x)
			{
				if (this != &x)
				{
					_alloc = x._alloc;
					_comp = x._comp;
					_node = x._node;
				}
				return (*this);
			};

			iterator begin() {
				return (iterator(_node.begin()));
			};
			
			const_iterator begin() const {
				return (const_iterator(_node.begin()));
			};

			iterator end() {
				iterator it = _node.end();
				++it;
				return (it);
			};

			const_iterator end() const {
				const_iterator it = _node.end();
				++it;
				return (it);
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
				return (size() == 0);
			};

			size_type size() const {
				return (_node.size());
			};

			size_type max_size() const {
				return (get_allocator().max_size());
			};

			mapped_type & operator[] (const key_type& k)
			{
				return (
					(*((this->insert(ft::make_pair(k, mapped_type())))
					.first)).second);
			};

			iterator find (const key_type& k)
			{ return (iterator(_node.search(k))); };

			const_iterator find (const key_type& k) const
			{ return (const_iterator(_node.search(k))); };

			ft::pair<iterator, bool> insert(const value_type& val)
			{
				size_type len = size();
				bool exist;
				_node.insert(val);
				exist = ((len == size()) ? false : true);
				return (ft::pair<iterator, bool>(find(val.first), exist));
			};
			
			iterator insert (iterator position, const value_type& val) {
				(void)position;
				this->insert(val);
				return (iterator(find(val.first)));
			};
			
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				for (; first != last; first++)
					_node.insert(*first);
			};

			void erase (iterator position) {
				erase(position->first);
			};
			size_type erase (const key_type& k) {
				return (_node.remove(k));
			};
			void erase (iterator first, iterator last)
			{
				iterator next = first;
				while (first != last)
				{
					next = first;
					next++;
					erase((first->first));
					first = next;
				}
			};

			void swap (map& x)
			{
				_node.swap(x._node);
			};

			void clear() {
				_node.clear();
			};

			key_compare key_comp() const { return (key_compare()); };

			value_compare value_comp() const
			{ return (value_compare(key_comp())); };

			size_type count (const key_type& k) const 
			{ return (_node.exist(k)); };

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
				map::const_iterator it = this->begin();
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
				map::const_iterator it = this->begin();
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
				return (_node.get_allocator());
			};
	};

template< class Key, class T, class Compare, class Alloc >
bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{
	if (lhs.size() == rhs.size())
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	return (false);
}

template< class Key, class T, class Compare, class Alloc >
bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return (ft::lexicographical_compare(
			lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class Key, class T, class Compare, class Alloc >
bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{ return !(lhs == rhs); }

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{ return (lhs < rhs || rhs == lhs); }

template< class Key, class T, class Compare, class Alloc >
bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs )
{
	if (lhs < rhs || lhs == rhs)
		return (false);
	return (true);
}

template< class Key, class T, class Compare, class Alloc >
bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{
	if (lhs == rhs || lhs > rhs)
		return (true);
	return (false);
}
}