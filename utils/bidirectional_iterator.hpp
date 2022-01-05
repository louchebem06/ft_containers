/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:01:20 by bledda            #+#    #+#             */
/*   Updated: 2022/01/05 19:02:40 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

namespace ft
{
	template <class T, bool reverse = false, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
	class bidirectional_iterator
	{
		public:
			typedef T						value_type;
			typedef Pointer 				pointer;
			typedef Reference 				reference;
			typedef Distance 				distance;
			typedef bidirectional_iterator	iterator;
		private:	
			pointer _ptr;
		public:			
			bidirectional_iterator()
			{
				this->_ptr = nullptr;
			};
			
			bidirectional_iterator(pointer ptr)
			{
				this->_ptr = ptr;
			};

			~bidirectional_iterator(){};

			bidirectional_iterator & operator=(const bidirectional_iterator& rhs)
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

			value_type & operator*()
			{
				return (*(this->_ptr));
			}

			value_type & operator->()
			{
				return (*(this->_ptr));
			}
	};
}