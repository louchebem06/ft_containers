/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:36:12 by bledda            #+#    #+#             */
/*   Updated: 2022/01/05 00:09:47 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iterator>
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
			// typedef typename std::iterator_traits<value_type>		iterator;
			// typedef typename std::iterator_traits<const value_type>	const_iterator;
			// typedef typename std::reverse_iterator<iterator>		reverse_iterator;
			// typedef typename std::reverse_iterator<const_iterator>	const_reverse_iterator;
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
				updateCapacity(n);
				this->_ptr = this->_alloc.allocate(this->capacity());
				for (size_type i = 0; i < n; i++)
       				this->_alloc.construct(this->_ptr + i, val);
				this->start = this->_ptr;
				this->end = this->_ptr + n - 1;
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
				this->clear();
			};

			vector& operator=(const vector& x)
			{
				if (*this != x)
				{
					this->clear();
					this->_alloc = x._alloc;
					this->_ptr = x._ptr;
					this->start = x._start;
					this->end = x._end;
					this->_size = x._size;
					this->_capacity = x._capacity;
				}
				return (*this);
			};

			// iterator begin()
			// {
			// 	return (iterator(this->_start));
			// };
			// const_iterator begin() const
			// {
			// 	return (const_iterator(this->_start));
			// };

			// iterator end()
			// {
			// 	return (iterator(this->_end));
			// };
			// const_iterator end() const
			// {
			// 	return (const_iterator(this->_end));
			// };

			// reverse_iterator rbegin()
			// {
			// 	return (reverse_iterator(this->_end));
			// };
			// const_reverse_iterator rbegin() const
			// {
			// 	return (const_reverse_iterator(this->_end));
			// };

			// reverse_iterator rend()
			// {
			// 	return (reverse_iterator(this->_start));
			// };
			// const_reverse_iterator rend() const
			// {
			// 	return (const_reverse_iterator(this->_start));
			// };

			size_type size() const
			{
				return (this->_size);
			};

			size_type max_size() const
			{
				return (this->_alloc.max_size());
			};

			// void resize (size_type n, value_type val = value_type());

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
					throw (std::out_of_range(this->getErrorAT(n)));
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

			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last);
			// void assign (size_type n, const value_type& val);

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

			// void pop_back();

			// iterator insert (iterator position, const value_type& val);
			// void insert (iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);

			// iterator erase (iterator position);
			// iterator erase (iterator first, iterator last);

			// void swap (vector& x);

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

			// allocator_type get_allocator() const;
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
	};
}
