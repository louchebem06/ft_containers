/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:20:50 by bledda            #+#    #+#             */
/*   Updated: 2022/01/06 21:21:30 by bledda           ###   ########.fr       */
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
			
			random_access_iterator(pointer ptr)
			{
				this->_ptr = ptr;
			};

			~random_access_iterator(){};

			// https://stackoverflow.com/questions/57718018/how-do-i-convert-iterator-to-const-iterator-in-my-custom-list-iterator-class
			operator random_access_iterator<const T, reverse>()
			{
				return (random_access_iterator<const T, reverse>(this->_ptr));
			};

			random_access_iterator<T> & operator=(const random_access_iterator & rhs)
			{
				if (this->_ptr != rhs._ptr)
					this->_ptr = rhs._ptr;
				return (*this);
			};

			iterator operator++(int)
			{
				iterator tmp = this->_ptr;
				(!reverse) ? this->_ptr++ : this->_ptr--;
				return (tmp);
			};

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
			};

			iterator & operator--()
			{
				(!reverse) ? this->_ptr-- : this->_ptr++;
				return (*this);
			};

			iterator operator+=(size_t n)
			{
				(!reverse) ? this->_ptr += n : this->_ptr -= n;
				return (*this);
			};

			iterator operator-=(size_t n)
			{
				(!reverse) ? this->_ptr -= n : this->_ptr += n;
				return (*this);
			};

			iterator operator+(size_t n)
			{
				iterator tmp = (!reverse) ? this->_ptr + n : this->_ptr - n;
				return (tmp);
			};

			iterator operator-(size_t n)
			{
				iterator tmp = (!reverse) ? this->_ptr - n : this->_ptr + n;
				return (tmp);
			};

			template <class T_, bool reverse_>
			friend random_access_iterator<T_, reverse_> operator+(
				size_t n, random_access_iterator<T_, reverse_> const & rhs);

			template <class T_, bool reverse_>
			friend random_access_iterator<T_, reverse_> operator-(
				size_t n, random_access_iterator<T_, reverse_> const & rhs);

			bool operator==(random_access_iterator<const T, reverse> & rhs)
			{
				if (this->getPointer() == rhs.getPointer())
					return (true);
				return (false);
			};
			
			bool operator!=(random_access_iterator<const T, reverse> & rhs)
			{
				if (this->getPointer() - 1 != rhs.getPointer())
					return (true);
				return (false);
			};

			bool operator<(random_access_iterator<const T, reverse> & rhs)
			{
				if (reverse)
					return (this->getPointer() > rhs.getPointer());
				else if (this->getPointer() < rhs.getPointer())
					return (true);
				return (false);
			};
			
			bool operator>(random_access_iterator<const T, reverse> & rhs)
			{
				if (reverse)
					return (this->getPointer() < rhs.getPointer());
				else if (this->getPointer() > rhs.getPointer())
					return (true);
				return (false);
			};

			bool operator<=(random_access_iterator<const T, reverse> & rhs)
			{
				if (reverse)
					return (this->getPointer() >= rhs.getPointer());
				else if (this->getPointer() <= rhs.getPointer())
					return (true);
				return (false);
			};
			
			bool operator>=(random_access_iterator<const T, reverse> & rhs)
			{
				if (reverse)
					return (this->getPointer() <= rhs.getPointer());
				else if (this->getPointer() >= rhs.getPointer())
					return (true);
				return (false);
			};

			reference operator*()
			{
				return (*(this->_ptr));
			};

			reference operator->()
			{
				return (*(this->_ptr));
			};

			reference operator[](size_t n)
			{
				return (*(this->_ptr + n));
			};

			pointer getPointer()
			{
				return (this->_ptr);
			}
	};

	template <class T_, bool reverse_>
	random_access_iterator<T_, reverse_> operator+(
		size_t n, random_access_iterator<T_, reverse_> const & rhs)
	{
		random_access_iterator<T_, reverse_> tmp = 
			(!reverse_) ? n + rhs._ptr : n - rhs._ptr;
		return (tmp);
	}

	template <class T_, bool reverse_>
	random_access_iterator<T_, reverse_> operator-(
		size_t n, random_access_iterator<T_, reverse_> const & rhs)
	{
		random_access_iterator<T_, reverse_> tmp =
			(!reverse_) ? n - rhs._ptr : n + rhs._ptr;
		return (tmp);
	}
}
