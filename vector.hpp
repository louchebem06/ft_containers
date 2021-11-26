/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:30:06 by bledda            #+#    #+#             */
/*   Updated: 2021/11/26 10:36:39 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{
	template <typename type>
	class vector
	{
		public:
			vector()
			{
				_size = 0;
				_ptr = _alloc.allocate(_size);
			};
			~vector()
			{
				_alloc.deallocate(_ptr, _size);
			};
			vector(vector const & src)
			{
				*this = src;
			};
			vector & operator=(vector const & rhs)
			{
				if (this != &rhs)
				{
					_alloc.deallocate(_ptr, _size);
					_size	= rhs._size;
					_ptr = _alloc.allocate(_size);
					for (size_t i = 0; i < _size; i++)
						_ptr[i] = rhs._ptr[i];
				}
				return (*this);
			};

			/*
			
					_                           _                                     
				___| | ___ _ __ ___   ___ _ __ | |_ ___    __ _  ___ ___ ___  ___ ___ 
			/ _ \ |/ _ \ '_ ` _ \ / _ \ '_ \| __/ __|  / _` |/ __/ __/ _ \/ __/ __|
			|  __/ |  __/ | | | | |  __/ | | | |_\__ \ | (_| | (_| (_|  __/\__ \__ \
			\___|_|\___|_| |_| |_|\___|_| |_|\__|___/  \__,_|\___\___\___||___/___/
																					
			
			*/
			type	& at(size_t index)
			{
				return (_ptr[index]);
			};
			type	const & at(size_t index) const
			{
				return (_ptr[index]);
			};
			type	& operator[](size_t index)
			{
				return (_ptr[index]);
			};
			type	const & operator[](size_t index) const
			{
				return (_ptr[index]);
			};
			type 	& front()
			{
				return (_ptr[0]);
			};
			type	const & front() const
			{
				return (_ptr[0]);
			};
			type 	& back()
			{
				return (_ptr[_size - 1]);
			};
			type	const & back() const
			{
				return (_ptr[_size - 1]);
			};

			/*
			
								_ _  __ _               
			_ __ ___   ___   __| (_)/ _(_) ___ _ __ ___ 
			| '_ ` _ \ / _ \ / _` | | |_| |/ _ \ '__/ __|
			| | | | | | (_) | (_| | |  _| |  __/ |  \__ \
			|_| |_| |_|\___/ \__,_|_|_| |_|\___|_|  |___/
														
			
			*/
			void	push_back(type const & value)
			{
				_size++;
				_ptr = _alloc.allocate(_size);
				_ptr[_size - 1] = value;
			};

			/*
			
										_ _         
				___ __ _ _ __   __ _  ___(_) |_ _   _ 
			/ __/ _` | '_ \ / _` |/ __| | __| | | |
			| (_| (_| | |_) | (_| | (__| | |_| |_| |
			\___\__,_| .__/ \__,_|\___|_|\__|\__, |
						|_|                     |___/ 
			
			*/	
			size_t	size() const
			{
				return (_size);
			};
			
			bool	empty() const
			{
				if (_size)
					return (true);
				return (false);
			}

			/*
			
			_ _                 _             
			(_) |_ ___ _ __ __ _| |_ ___  _ __ 
			| | __/ _ \ '__/ _` | __/ _ \| '__|
			| | ||  __/ | | (_| | || (_) | |   
			|_|\__\___|_|  \__,_|\__\___/|_|   
												
			
			*/
			typedef typename type::iterator iterator;
			typedef typename type::const_iterator const_iterator;
			typedef typename type::reverse_iterator reverse_iterator;
			typedef typename type::const_reverse_iterator const_reverse_iterator;
			iterator begin()
			{
				return (_ptr);
			};
			const_iterator begin() const
			{
				return (_ptr);
			};
			iterator end()
			{
				return (_ptr + _size);
			};
			const_iterator end() const
			{
				return (_ptr + _size);
			};
			reverse_iterator rbegin()
			{
				return (_ptr + _size);
			};
			const_reverse_iterator rbegin() const
			{
				return (_ptr + _size);
			};
			reverse_iterator rend()
			{
				return (_ptr);
			};
			const_reverse_iterator rend() const
			{
				return (_ptr);
			};
		private:
			std::allocator<type>	_alloc;
			type					* _ptr;
			size_t					_size;
	};
}

#endif
