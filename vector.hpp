/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:36:12 by bledda            #+#    #+#             */
/*   Updated: 2022/01/17 23:29:17 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>
#include "utils/type_traits.hpp"
#include "utils/iterator.hpp"
#include "utils/algorithm.hpp"

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
			typedef ft::random_access_iterator<T>				iterator;
			typedef ft::random_access_iterator<const T>			const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		private:
			allocator_type		_alloc;
			pointer 			_ptr;
			pointer				_start;
			pointer 			_end;
			size_type			_size;
			size_type			_capacity;
		public:
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				this->_alloc = alloc;
				this->_size = 0;
				this->_start = 0;
				this->_end = 0;
				this->_capacity = 0;
				this->_ptr = 0;
			};
			explicit vector (size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
			{
				this->_alloc = alloc;
				this->_size = n;
				this->_capacity = n;
				this->_ptr = this->_alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
       				this->_alloc.construct(this->_ptr + i, val);
				this->_start = this->_ptr;
				this->_end = this->_ptr + n - 1;
			};
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename enable_if<!is_integral<InputIterator>::value, bool>::type = false)
			{
				difference_type n = ft::distance<InputIterator>(first, last);
				
				this->_alloc = alloc;
				this->_ptr = this->_alloc.allocate(n);
				this->_size = n;
				this->_capacity = n;
				size_t i = 0;
				while (first != last)
       				this->_alloc.construct(this->_ptr + i++, *first++);
				this->_start = this->_ptr;
				this->_end = this->_ptr + (this->size() - 1);
			};
			vector (const vector& x)
			{
				*this = x;
			};

			~vector()
			{
				this->clear();
				this->_alloc.deallocate(this->_ptr, this->capacity());
			};

			vector& operator=(const vector& x)
			{
				if (this->_ptr != x._ptr)
				{
					allocator_type	new_alloc;
					pointer 		new_pointer;
					size_type		size = x.size();
					size_type		capacity = x.capacity();

					new_pointer = new_alloc.allocate(capacity);
					if (!new_pointer)
						throw std::bad_alloc();
					for (size_type i = 0; i < x.size(); i++)
						new_alloc.construct(new_pointer + i, x[i]);
					this->_ptr = new_pointer;
					this->_start = new_pointer;
					this->_end = new_pointer + (size - 1);
					this->_size = size;
					this->_capacity = capacity;
				}
				return (*this);
			};

			iterator begin()
			{
				return (iterator(this->_start));
			};
			const_iterator begin() const
			{
				return (const_iterator(this->_start));
			};

			iterator end()
			{
				return (iterator(this->_end + 1));
			};
			const_iterator end() const
			{
				return (const_iterator(this->_end + 1));
			};

			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->end() - 1));
			};
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->end() - 1));
			};

			reverse_iterator rend()
			{
				return (reverse_iterator(this->begin() - 1));
			};
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->begin() - 1));
			};

			size_type size() const
			{
				return (this->_size);
			};

			size_type max_size() const
			{
				return (this->_alloc.max_size());
			};

			void resize (size_type n, value_type val = value_type())
			{
				size_type diff_size;
				size_type size = this->size(); 

				if (n > this->capacity())
				{
					allocator_type new_alloc;
					pointer new_pointer;

					new_pointer = new_alloc.allocate(n);
					if (!new_pointer)
						throw std::bad_alloc();
					for (size_type i = 0; i < size; i++)
       					new_alloc.construct(new_pointer + i, (*this)[i]);
					this->clear();
					this->_alloc.deallocate(this->_ptr, this->capacity());
					this->_size = n;
					this->_capacity = n;
					this->_ptr = new_pointer;
					this->_start = this->_ptr;
					this->_end = this->_ptr + (n - 1);
				}
				if (n < size)
				{
					diff_size = size - n;
					for (size_type i = diff_size; i < size; i++)
						this->_alloc.destroy(this->_start + i);
					this->_size -= diff_size;
					this->_end = this->_ptr + (this->size() - 1);
				}
				else if (n > size)
					while (size < this->size())
						this->_alloc.construct(this->_ptr + size++, val);
			};

			size_type capacity() const
			{
				return (this->_capacity);
			};

			bool empty() const
			{
				if (this->_size == 0)
					return (true);
				return (false);
			};

			void reserve (size_type n)
			{
				size_type 		capacity = this->_capacity;

				if (n > capacity)
				{
					size_type 		size = this->size();
					allocator_type 	new_alloc;
					pointer			new_pointer;
				
					this->_capacity = n;
					new_pointer = new_alloc.allocate(n);
					if (!new_pointer)
						throw std::bad_alloc();
					for (size_type i = 0; i < size; i++)
       					new_alloc.construct(new_pointer + i, (*this)[i]);
					this->clear();
					this->_alloc.deallocate(this->_ptr, this->capacity());
					this->_ptr = new_pointer;
					this->_start = this->_ptr;
					this->_end = this->_ptr + (size - 1);
					this->_size = size;
					this->_capacity = n;
				}
				else if (n > this->max_size())
					throw std::length_error("vector::reserve");
			};

			reference operator[] (size_type n)
			{
				return (*(this->_start + n));
			};
			const_reference operator[] (size_type n) const
			{
				return (*(this->_start + n));
			};

			reference at (size_type n)
			{
				if (n >= this->size())
					throw (std::out_of_range("vector"));
				return ((*this)[n]);
			};
			const_reference at (size_type n) const
			{
				if (n >= this->size())
					throw (std::out_of_range("vector"));
				return ((*this)[n]);
			};

			reference front()
			{
				return ((*this)[0]);
			};
			const_reference front() const
			{
				return ((*this)[0]);
			};

			reference back()
			{
				return ((*this)[this->size()-1]);
			};
			const_reference back() const
			{
				return ((*this)[this->size()-1]);
			};

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
						typename enable_if<!is_integral<InputIterator>::value,bool>::type = false)
			{
				difference_type new_size = ft::distance<InputIterator>(first, last);
				size_type capacity = this->capacity();
				
				this->clear();
				
				this->_size = new_size;
				if (static_cast<long long>(capacity) < static_cast<long long>(new_size))
				{
					this->_ptr = this->_alloc.allocate(new_size);
					this->_capacity = new_size;
				}
				for (size_type i = 0; first != last; first++, i++)
					this->_alloc.construct(this->_ptr + i, *first);
				this->_start = this->_ptr;
				this->_end = this->_ptr + (new_size - 1);
			}

			void assign (size_type n, const value_type& val)
			{
				this->clear();
				if (n > this->capacity())
				{
					allocator_type 	new_alloc;
					pointer			new_pointer;

					this->_capacity = n;
					new_pointer = new_alloc.allocate(n);
					if (!new_pointer)
						throw std::bad_alloc();
					this->_ptr = new_pointer;
					this->_alloc = new_alloc;
					this->_start = this->_ptr;
				}
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.construct(this->_ptr + i, val);
					this->_size++;
				}
				this->_end = this->_start + (this->size() - 1);
			};

			void push_back (const value_type& val)
			{
				size_type 		size = this->size();

				if (size + 1 > this->capacity())
				{
					allocator_type 	new_alloc;
					pointer			new_pointer;
				
					_updateCapacity(size + 1);
					new_pointer = new_alloc.allocate(this->capacity());
					for (size_type i = 0; i < size; i++)
       					new_alloc.construct(new_pointer + i, (*this)[i]);
					new_alloc.construct(new_pointer + size, val);
					this->clear();
					this->_alloc.deallocate(this->_ptr, this->capacity());
					this->_ptr = new_pointer;
					this->_start = this->_ptr;
				}
				else
					this->_alloc.construct(this->_ptr + size, val);
				this->_end = this->_ptr + size;
				this->_size = size + 1;
			}

			void pop_back()
			{
				if (!this->_end)
					return ;
				this->_alloc.destroy(this->_end);
				this->_size--;
				this->_end = this->_ptr + this->size() - 1;
			};

			iterator insert (iterator position, const value_type& val)
			{
				difference_type pos = distance(this->begin(), position);

				if (this->size() + 1 > this->capacity())
				{
					size_type 		size = this->size();
					size_type 		capacity;
					allocator_type 	new_alloc;
					pointer			new_pointer;
				
					_updateCapacity(size + 1);
					capacity = this->capacity();
					new_pointer = new_alloc.allocate(this->capacity());
					if (!new_pointer)
						throw std::bad_alloc();
					for (size_type i = 0; i < size; i++)
       					new_alloc.construct(new_pointer + i, (*this)[i]);
					new_alloc.construct(new_pointer + size, val);
					this->clear();
					this->_alloc.deallocate(this->_ptr, this->capacity());
					this->_ptr = new_pointer;
					this->_start = this->_ptr;
					this->_end = this->_ptr + (size - 1);
					this->_size = size;
					this->_capacity = capacity;
				}

				this->_alloc.construct(this->_ptr + this->size(), val);
				this->_size++;
				
				this->_end = this->_start + (this->size() - 1);
				
				for (iterator it = this->end() - 1; it != this->begin() + pos - 1; it--)
					if (it - 1 != this->begin() - 1)
						*it = *(it - 1);
				*(this->begin() + pos) = val;
			
				return (iterator(this->_start + pos));
			};
			void insert (iterator position, size_type n, const value_type& val)
			{
				for (size_type i = 0; i < n; i++)
					position = this->insert(position, val);
			};
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
						typename enable_if<!is_integral<InputIterator>::value,bool>::type = false)
			{
				vector<value_type> tmp;

				for (InputIterator it = first; it != last; it++)
					tmp.push_back(*it);
				
				while (tmp.size() != 0)
				{
					position = this->insert(position, tmp[tmp.size() - 1]);
					tmp.pop_back();
				}
			};

			iterator erase (iterator position)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (it > position)
						*(it - 1)= *it;
				this->_size--;
				this->_alloc.destroy(this->_ptr + this->size());
				this->_end = this->_start + (this->size() - 1);
				return (position);
			};
			iterator erase (iterator first, iterator last)
			{
				for (iterator it = first; it != last; it++)
					this->erase(first);
				return (first);
			};

			void swap (vector& x)
			{
				this->_switch(x._alloc, this->_alloc);
				this->_switch(x._ptr, this->_ptr);
				this->_switch(x._start, this->_start);
				this->_switch(x._end, this->_end);
				this->_switch(x._size, this->_size);
				this->_switch(x._capacity, this->_capacity);
			};

			void clear()
			{
				size_type size = this->size();

				if (this->empty())
					return ;
				for (size_type i = 0; i < size; i++)
        			this->_alloc.destroy(this->_ptr + i);
				this->_start = this->_ptr;
				this->_end = this->_ptr - 1;
				this->_size = 0;
			};

			allocator_type get_allocator() const
			{
				return (this->_alloc);
			};
		private:
			void _updateCapacity(size_type size)
			{
				if (size > this->capacity())
				{
					this->_capacity *= 2;
					if (this->_capacity <= 0)
						this->_capacity = 1;
					while (size > this->capacity())
						this->_capacity *= 2;
				}
			};
			template <typename V>
			void _switch(V & first, V & second) {
				V tmp = first;
				first = second;
				second = tmp;
			};
	};

	template <class T_, class Alloc_>
  	void swap (vector<T_,Alloc_>& x, vector<T_,Alloc_>& y)
	{
		x.swap(y);
	};

	template <class T_, class Alloc_>
	bool operator==(
		const vector<T_,Alloc_>& lhs, const vector<T_,Alloc_>& rhs)
	{
		if (lhs.size() == rhs.size())
			return (equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	};
	
	template <class T_, class Alloc_>
	bool operator!=(
		const vector<T_,Alloc_>& lhs, const vector<T_,Alloc_>& rhs)
	{
		return (!(lhs == rhs));
	};
	
	template <class T_, class Alloc_>
	bool operator<(
		const vector<T_,Alloc_>& lhs, const vector<T_,Alloc_>& rhs)
	{
		return (lexicographical_compare(
				lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class T_, class Alloc_>
	bool operator<=(
		const vector<T_,Alloc_>& lhs, const vector<T_,Alloc_>& rhs)
	{
		return (lhs < rhs || lhs == rhs);
	};
	
	template <class T_, class Alloc_>
	bool operator>(
		const vector<T_,Alloc_>& lhs, const vector<T_,Alloc_>& rhs)
	{
		if (lhs < rhs || lhs == rhs)
			return (false);
		return (true);
	};
	
	template <class T_, class Alloc_>
	bool operator>=(
		const vector<T_,Alloc_>& lhs, const vector<T_,Alloc_>& rhs)
	{
		if (lhs == rhs || lhs > rhs)
			return (true);
		return (false);
	};
}
