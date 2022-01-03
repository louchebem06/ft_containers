/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:36:12 by bledda            #+#    #+#             */
/*   Updated: 2022/01/03 21:27:47 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type 			size_type;
			// typedef typename 								iterator;
			// typedef typename 								const_iterator;
			// typedef typename 								reverse_iterator;
			// typedef typename 								const_reverse_iterator;
		private:
			allocator_type	_alloc;
			pointer			_start;
			pointer 		_end;
		public:	
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				this->_alloc = alloc;
				this->_start = nullptr;
				this->_end = nullptr;
			};
			explicit vector (size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
			{
				this->_alloc = alloc;
				this->_start = nullptr;
				this->_end = nullptr;
			};
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type())
			{
				this->_alloc = alloc;
				this->_start = first;
				this->_end = last;
			};
			vector (const vector& x)
			{
				*this = x;
			};

			~vector();

			vector& operator=(const vector& x);

			iterator begin()
			{
				return (this->_start);
			};
			const_iterator begin() const
			{
				return (this->_start);
			};

			iterator end()
			{
				return (this->_end);
			};
			const_iterator end() const
			{
				return (this->_end);
			};

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;

			reverse_iterator rend();
			const_reverse_iterator rend() const;

			size_type size() const
			{
				iterator 	tmp = this->_start;
				size_type	size = 0;
				
				while(tmp != this->_end)
				{
					tmp++;
					size++;
				}
				return (size);
			};

			size_type max_size() const
			{
				return (this->_alloc.max_size());
			};

			void resize (size_type n, value_type val = value_type());

			size_type capacity() const;

			bool empty() const;

			void reserve (size_type n);

			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;

			reference at (size_type n);
			const_reference at (size_type n) const;

			reference front();
			const_reference front() const;

			reference back();
			const_reference back() const;

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val);

			void push_back (const value_type& val);

			void pop_back();

			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			void swap (vector& x);

			void clear();

			allocator_type get_allocator() const;
	};
}
