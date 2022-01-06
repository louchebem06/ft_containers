/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:20:50 by bledda            #+#    #+#             */
/*   Updated: 2022/01/06 17:18:51 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

namespace ft
{
	template <class T, bool reverse = false, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
	class random_access_iterator
	{
		public:
			typedef T						value_type;
			typedef Pointer 				pointer;
			typedef Reference 				reference;
			typedef Distance 				distance;
			typedef random_access_iterator	iterator;
		private:	
			pointer _ptr;
		public:			
			random_access_iterator()
			{
				this->_ptr = 0;
			};

			// template <class _T>
			// random_access_iterator(_T & x)
			// {
			// 	this->_ptr = x.getPointer();
			// };
			
			pointer getPointer(void)
			{
				return (this->_ptr);
			}
			
			random_access_iterator(pointer ptr)
			{
				this->_ptr = ptr;
			};

			~random_access_iterator(){};

			random_access_iterator & operator=(const random_access_iterator& rhs)
			{
				if (this->_ptr != rhs._ptr)
					this->_ptr = rhs._ptr;
				return (*this);
			}

			iterator operator++(int)
			{
				iterator tmp = this->_ptr;
				(!reverse) ? this->_ptr++ : this->_ptr--;
				return (tmp);
			}

			iterator & operator++()
			{
				(!reverse) ? this->_ptr++ : this->_ptr--;
				return (*this);
			};

			iterator operator--(int)
			{
				iterator tmp = this->_ptr;
				(!reverse) ? this->_ptr-- : this->_ptr++;
				return (tmp);
			}

			iterator & operator--()
			{
				(!reverse) ? this->_ptr-- : this->_ptr++;
				return (*this);
			};

			iterator operator+=(size_t n)
			{
				(!reverse) ? this->_ptr += n : this->_ptr -= n;
				return (*this);
			}

			iterator operator-=(size_t n)
			{
				(!reverse) ? this->_ptr -= n : this->_ptr += n;
				return (*this);
			}

			iterator operator+(size_t n)
			{
				iterator tmp = (!reverse) ? this->_ptr + n : this->_ptr - n;
				return (tmp);
			}

			iterator operator-(size_t n)
			{
				iterator tmp = (!reverse) ? this->_ptr - n : this->_ptr + n;
				return (tmp);
			}

			template <class T_, bool reverse_>
			friend random_access_iterator<T_, reverse_> operator+(size_t n, random_access_iterator<T_, reverse_> const & rhs);

			template <class T_, bool reverse_>
			friend random_access_iterator<T_, reverse_> operator-(size_t n, random_access_iterator<T_, reverse_> const & rhs);

			bool operator==(const iterator & rhs)
			{
				if (this->_ptr == rhs._ptr)
					return (true);
				return (false);
			}
			
			bool operator!=(const iterator & rhs)
			{
				if (this->_ptr != rhs._ptr)
					return (true);
				return (false);
			}

			bool operator<(const iterator & rhs)
			{
				if (reverse)
					return (this->_ptr > rhs._ptr);
				else if (this->_ptr < rhs._ptr)
					return (true);
				return (false);
			}
			
			bool operator>(const iterator & rhs)
			{
				if (reverse)
					return (this->_ptr < rhs._ptr);
				else if (this->_ptr > rhs._ptr)
					return (true);
				return (false);
			}

			bool operator<=(const iterator & rhs)
			{
				if (reverse)
					return (this->_ptr >= rhs._ptr);
				else if (this->_ptr <= rhs._ptr)
					return (true);
				return (false);
			}
			
			bool operator>=(const iterator & rhs)
			{
				if (reverse)
					return (this->_ptr <= rhs._ptr);
				else if (this->_ptr >= rhs._ptr)
					return (true);
				return (false);
			}

			value_type & operator*()
			{
				return (*(this->_ptr));
			}

			value_type & operator->()
			{
				return (*(this->_ptr));
			}

			reference operator[](size_t n)
			{
				return (*(this->_ptr + n));
			}
	};

	template <class T_, bool reverse_>
	random_access_iterator<T_, reverse_> operator+(
		size_t n, random_access_iterator<T_, reverse_> const & rhs)
	{
		random_access_iterator<T_, reverse_> tmp = (!reverse_) ? n + rhs._ptr : n - rhs._ptr;
		return (tmp);
	}

	template <class T_, bool reverse_>
	random_access_iterator<T_, reverse_> operator-(
		size_t n, random_access_iterator<T_, reverse_> const & rhs)
	{
		random_access_iterator<T_, reverse_> tmp = (!reverse_) ? n - rhs._ptr : n + rhs._ptr;
		return (tmp);
	}
}
