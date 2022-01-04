/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:35:44 by bledda            #+#    #+#             */
/*   Updated: 2022/01/04 15:45:11 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// https://www.cplusplus.com/reference/iterator/

#include <cstddef>

namespace ft
{
	// Base
	template <class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class iterator
	{
		public:
			typedef iterator<T, Distance, Pointer, Reference> Iterator;
	
			iterator(Pointer ptr)
			{
				Pointer _ptr = ptr;
			};

			virtual ~iterator(){};

			iterator operator=(Iterator rhs)
			{
				this = rhs;
				return (this);
			}

			Iterator operator++()
			{
				this->_ptr++;
				return (this);
			}
			// Iterator operator++(T)
			// {
			// 	Iterator tmp = this;
			// 	++this->_ptr;
			// 	return (tmp);
			// }
		protected:	
			Pointer _ptr;	
	};

	// Input
	template <class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class input_iterator_tag : public iterator<T,
		Distance, Pointer, Reference>
	{
		public:
			typedef iterator<T, Distance, Pointer, Reference> Iterator;
			
			input_iterator_tag(Pointer ptr)
			{
				Pointer _ptr = ptr;
			};

			virtual ~input_iterator_tag(){};
			
			bool operator==(Iterator rhs)
			{
				if (this == rhs)
					return (true);
				return (false);
			};
			bool operator!=(Iterator rhs)
			{
				if (this != rhs)
					return (true);
				return (false);
			};
			Reference operator*()
			{
				return (*this);
			}
			Reference operator->()
			{
				return (*this);
			}
	};

	// Output
	template <class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class output_iterator_tag : public iterator<T,
		Distance, Pointer, Reference>
	{
		public:
			typedef iterator<T, Distance, Pointer, Reference> Iterator;
			
			output_iterator_tag(Pointer ptr)
			{
				Pointer _ptr = ptr;
			};

			virtual ~output_iterator_tag(){};
			
			Reference operator=(Iterator const & rhs)
			{
				if (*this != rhs)
				{
					this->_ptr = rhs._ptr;
				}
				return (*this);
			};
			Reference operator++()
			{
				this->_ptr++;
				return (*this);
			};
	};

	// Forward
	template <class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class forward_iterator_tag :
			virtual public input_iterator_tag<T, Distance, Pointer, Reference>,
			virtual public output_iterator_tag<T, Distance, Pointer, Reference>
	{
		public:
			forward_iterator_tag()
			{
				Pointer _ptr = nullptr;
			};

			forward_iterator_tag(Pointer ptr)
			{
				Pointer _ptr = ptr;
			};

			virtual ~forward_iterator_tag(){};
	};

	// Bidirectional
	template <class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class bidirectional_iterator_tag :
			public forward_iterator_tag<T, Distance, Pointer, Reference>
	{
		public:
			typedef iterator<T, Distance, Pointer, Reference> Iterator;
			
			bidirectional_iterator_tag(Pointer ptr)
			{
				Pointer _ptr = ptr;
			};

			virtual ~bidirectional_iterator_tag(){};
			
			Iterator operator--()
			{
				this->_ptr--;
				return (this);
			}
			Iterator operator--(T)
			{
				Iterator tmp = this;
				--this->_ptr;
				return (tmp);
			}
			// Reference operator--()
			// {
			// 	*this->_ptr--;
			// 	return (*this);
			// }
	};

	// Random access
	template <class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T& >
	class random_access_iterator_tag :
			public bidirectional_iterator_tag<T, Distance, Pointer, Reference>
	{
		public:
			typedef iterator<T, Distance, Pointer, Reference> Iterator;
			
			random_access_iterator_tag(Pointer ptr)
			{
				Pointer _ptr = ptr;
			};

			virtual ~random_access_iterator_tag(){};
			
			Iterator operator+(Iterator rhs)
			{
				this->_ptr + rhs->_ptr;
				return (this);
			};
			// Iterator operator+(Iterator lhs,
			// 					Iterator rhs)
			// {
			// 	Iterator tmp = lhs->_ptr + rhs->_ptr;
			// 	return (tmp);
			// };
			Iterator operator-(Iterator rhs)
			{
				this->_ptr - rhs->_ptr;
				return (this);
			};
			// Iterator operator-(Iterator lhs,
			// 					Iterator rhs)
			// {
			// 	Iterator tmp = lhs->_ptr - rhs->_ptr;
			// 	return (tmp);
			// };

			bool operator<(Iterator rhs)
			{
				if (this->_ptr < rhs->_ptr)
					return (true);
				return (false);
			};
			bool operator>(Iterator rhs)
			{
				if (this->_ptr > rhs->_ptr)
					return (true);
				return (false);
			};
			bool operator<=(Iterator rhs)
			{
				if (this->_ptr <= rhs->_ptr)
					return (true);
				return (false);
			};
			bool operator>=(Iterator rhs)
			{
				if (this->_ptr >= rhs->_ptr)
					return (true);
				return (false);
			};

			Iterator operator+=(Iterator rhs)
			{
				this->_ptr += rhs->_ptr;
				return (this);
			};
			Iterator operator-=(Iterator rhs)
			{
				this->_ptr -= rhs->_ptr;
				return (this);
			};

			Pointer operator[](size_t i)
			{
				return (this->_ptr + i);
			}
	};
}
