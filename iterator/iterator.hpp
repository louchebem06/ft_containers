/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:35:44 by bledda            #+#    #+#             */
/*   Updated: 2022/01/04 14:38:26 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// https://www.cplusplus.com/reference/iterator/

#include <cstddef>

namespace ft
{
	// Base
	template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class iterator
	{
		protected:
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;

			virtual iterator(pointer ptr)
			{
				pointer _ptr = ptr;
			};

			virtual ~iterator(){};

			iterator operator=(iterator rhs)
			{
				this = rhs;
				return (this);
			}

			iterator operator++()
			{
				this->_ptr++;
				return (this);
			}
			iterator operator++(T)
			{
				iterator tmp = this;
				++this->_ptr;
				return (tmp);
			}
			
			pointer _ptr;	
	};

	// Input
	template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class input_iterator_tag : public iterator<input_iterator_tag, T,
		Distance, Pointer, Reference>
	{
		public:
			bool operator==(iterator rhs)
			{
				if (this == rhs)
					return (true);
				return (false);
			};
			bool operator!=(iterator rhs)
			{
				if (this != rhs)
					return (true);
				return (false);
			};
			reference operator*()
			{
				return (*this);
			}
			reference operator->()
			{
				return (*this);
			}
	};

	// Output
	template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class output_iterator_tag : public iterator<output_iterator_tag, T,
		Distance, Pointer, Reference>
	{
		public:
			reference operator=(iterator const & rhs)
			{
				if (*this != rhs)
				{
					this->_ptr = rhs._ptr;
				}
				return (*this);
			};
			reference operator++()
			{
				this->_ptr++:
				return (*this);
			};
	};

	// Forward
	template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class forward_iterator_tag : virtual public input_iterator_tag,
										virtual public output_iterator_tag
	{
		public:
			forward_iterator_tag(){};
	};

	// Bidirectional
	template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class bidirectional_iterator_tag : public forward_iterator_tag
	{
		public:
			iterator operator--()
			{
				this->_ptr--;
				return (this);
			}
			iterator operator--(T)
			{
				iterator tmp = this;
				--this->_ptr;
				return (tmp);
			}
			reference operator--()
			{
				*this->_ptr--;
				return (*this);
			}
	};

	// Random access
	template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class random_access_iterator_tag : public bidirectional_iterator_tag
	{
		public:
			iterator operator+(iterator rhs)
			{
				this->_ptr + rhs->_ptr;
				return (this);
			};
			iterator operator+(iterator lhs, iterator rhs)
			{
				iterator tmp = lhs->_ptr + rhs->_ptr;
				return (tmp);
			};
			iterator operator-(iterator rhs)
			{
				this->_ptr - rhs->_ptr;
				return (this);
			};
			iterator operator-(iterator lhs, iterator rhs)
			{
				iterator tmp = lhs->_ptr - rhs->_ptr;
				return (tmp);
			};

			bool operator<(iterator rhs)
			{
				if (this->_ptr < rhs->_ptr)
					return (true);
				return (false);
			};
			bool operator>(iterator rhs)
			{
				if (this->_ptr > rhs->_ptr)
					return (true);
				return (false);
			};
			bool operator<=(iterator rhs)
			{
				if (this->_ptr <= rhs->_ptr)
					return (true);
				return (false);
			};
			bool operator>=(iterator rhs)
			{
				if (this->_ptr >= rhs->_ptr)
					return (true);
				return (false);
			};

			iterator operator+=(iterator rhs)
			{
				this->_ptr += rhs->_ptr;
				return (this);
			};
			iterator operator-=(iterator rhs)
			{
				this->_ptr -= rhs->_ptr;
				return (this);
			};

			pointer operator[](size_t i)
			{
				return (this->_ptr + i);
			}
	};
}
