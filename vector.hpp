/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:36:12 by bledda            #+#    #+#             */
/*   Updated: 2022/01/05 22:22:41 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>
#include "utils/random_access_iterator.hpp"
#ifdef __linux__
	# include <sstream>
	# include <string>
#endif

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference 		const_reference;
			typedef typename allocator_type::pointer 				pointer;
			typedef typename allocator_type::const_pointer 			const_pointer;
			typedef typename allocator_type::difference_type		difference_type;
			typedef typename allocator_type::size_type 				size_type;
			typedef random_access_iterator<value_type>				iterator;
			typedef random_access_iterator<const value_type>		const_iterator;
			typedef random_access_iterator<value_type, true>		reverse_iterator;
			typedef random_access_iterator<const value_type, true>	const_reverse_iterator;
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

			~vector()
			{
				// size_type capacity = this->capacity();

				this->clear();
				// this->_alloc.deallocate(this->_ptr, capacity);
			};

			vector& operator=(const vector& x)
			{
				if (this->_ptr != x._ptr)
				{
					//size_type capacity = this->capacity();

					this->clear();
					//this->_alloc.deallocate(this->_ptr, capacity);
					this->_alloc = x._alloc;
					this->_ptr = x._ptr;
					this->_start = x._start;
					this->_end = x._end;
					this->_size = x._size;
					this->_capacity = x._capacity;
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
				return (const_iterator(this->_end));
			};

			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->_end));
			};
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->_end));
			};

			reverse_iterator rend()
			{
				return (reverse_iterator(this->_start - 1));
			};
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->_start - 1));
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
					this->_size = n;
					this->_capacity = n;
					this->_ptr = new_pointer;
					this->_alloc = new_alloc;
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
					this->_ptr = new_pointer;
					this->_alloc = new_alloc;
					this->_start = this->_ptr;
					this->_end = this->_ptr + size;
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
					#ifdef __APPLE__
						throw (std::out_of_range("vector"));
					#elif __linux__
						throw (std::out_of_range(this->getErrorAT(n)));
					#endif
				return ((*this)[n]);
			};
			const_reference at (size_type n) const
			{
				if (n >= this->size())
					#ifdef __APPLE__
						throw (std::out_of_range("vector"));
					#elif __linux__
						throw (std::out_of_range(this->getErrorAT(n)));
					#endif
				return ((*this)[n]);
			};

			reference front()
			{
				std::cout << &this->_start << std::endl;
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
			void assign (InputIterator first, InputIterator last)
			{
				size_type new_size = this->countIterator(first, last);
				size_type capacity = this->capacity();
				
				this->clear();
				this->_size = new_size;
				if (capacity < new_size)
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
				size_type size 	= this->size();
				bool update 	= false;
				allocator_type 	new_alloc;
				pointer			new_pointer;

				for (size_type i = 0; i < size; i++)
					this->_alloc.destroy(this->_ptr + i);
				for (size_type i = 0; i < n; i++)
				{
					if (i == size)
						update = true;
					if (update)
					{
						this->_size++;
						if (this->size() > this->capacity())
						{
							this->_capacity++;
							new_pointer = new_alloc.allocate(this->capacity());
							for (size_type i = 0; i < this->size(); i++)
       							new_alloc.construct(new_pointer + i, val);
							this->_ptr = new_pointer;
							this->_alloc = new_alloc;
							this->_start = this->_ptr;
							this->_end = this->_ptr + size;
						}
					}
					this->_alloc.construct(this->_ptr + i, val);
				}
			};

			void push_back (const value_type& val)
			{
				size_type 		size = this->size();

				if (size + 1 > this->capacity())
				{
					allocator_type 	new_alloc;
					pointer			new_pointer;
				
					updateCapacity(size + 1);
					new_pointer = new_alloc.allocate(this->capacity());
					for (size_type i = 0; i < size; i++)
       					new_alloc.construct(new_pointer + i, (*this)[i]);
					new_alloc.construct(new_pointer + size, val);
					this->clear();
					this->_ptr = new_pointer;
					this->_alloc = new_alloc;
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

			// iterator insert (iterator position, const value_type& val) {};
			// void insert (iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);

			iterator erase (iterator position)
			{
				iterator		begin = this->begin();
				size_type		size = this->size();
				size_type		capacity = this->capacity();
				size_type		i = 0;
				allocator_type 	new_alloc;
				pointer			new_pointer;
				size_type		save;
				
				new_pointer = new_alloc.allocate(capacity);
				while (begin != position)
				{
					new_alloc.construct(new_pointer + i, (*this)[i]);
					begin++;
					i++;
				}
				save = i;
				for (size_type i = save + 1; i < this->size(); i++)
					new_alloc.construct(new_pointer + i - 1, (*this)[i]);
				this->clear();
				this->_size = size - 1;
				this->_capacity = capacity;
				this->_alloc = new_alloc;
				this->_ptr = new_pointer;
				this->_start = this->_ptr;
				this->_end = this->_ptr + (this->size() - 1);
				return (iterator(this->_ptr + save + 1));
			};
			iterator erase (iterator first, iterator last)
			{
				iterator tmp;

				while (first != last)
				{
					tmp = this->erase(first);
					first++;
				}
				return (tmp);
			};

			void swap (vector& x)
			{
				vector tmp;

				tmp._alloc 		= x._alloc;
				tmp._ptr 		= x._ptr;
				tmp._start 		= x._start;
				tmp._end 		= x._start;
				tmp._size	 	= x._size;
				tmp._capacity 	= x._capacity;

				x._alloc 		= this->_alloc;
				x._ptr 			= this->_ptr;
				x._start 		= this->_start;
				x._end 			= this->_start;
				x._size 		= this->_size;
				x._capacity 	= this->_capacity;

				this->_alloc 	= tmp._alloc;
				this->_ptr 		= tmp._ptr;
				this->_start 	= tmp._start;
				this->_end 		= tmp._start;
				this->_size 	= tmp._size;
				this->_capacity = tmp._capacity;
			};

			void clear()
			{
				size_type size = this->size();

				if (this->empty())
					return ;
				for (size_type i = 0; i < size; i++)
        			this->_alloc.destroy(this->_ptr + i);
				this->_start = this->_ptr;
				this->_end = this->_ptr;
				this->_size = 0;
			};

			allocator_type get_allocator() const
			{
				return (this->_alloc);
			};
		private:
			#ifdef __linux__
				std::string getErrorAT(size_type n)
				{
					std::stringstream error;

					error << "vector::_M_range_check: __n (which is " << n \
							<< ") >= this->size() (which is " << this->size() << ")";
					return (error.str());
				}
			#endif
			void updateCapacity(size_type size)
			{
				if (size > this->capacity())
				{
					this->_capacity *= 2;
					if (this->_capacity <= 0)
						this->_capacity = 1;
				}
			}
			template <class InputIterator>
			size_type countIterator(InputIterator begin, InputIterator end)
			{
				size_type size = 0;

				while (begin != end)
				{
					begin++;
					size++;
				}
				return (size);
			}
	};
}
