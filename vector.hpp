/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:30:06 by bledda            #+#    #+#             */
/*   Updated: 2021/11/26 22:00:57 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			/*
			
			_                        _       __ 
			| |_ _   _ _ __   ___  __| | ___ / _|
			| __| | | | '_ \ / _ \/ _` |/ _ \ |_ 
			| |_| |_| | |_) |  __/ (_| |  __/  _|
			\__|\__, | .__/ \___|\__,_|\___|_|  
				|___/|_|                        
			
			*/
			typedef T 											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type 			size_type;
			// typedef typename 								iterator;
			// typedef typename 								const_iterator;
			// typedef typename 								reverse_iterator;
			// typedef typename 								const_reverse_iterator;
			
			/*
			
								_                   _             
				___ ___  _ __  ___| |_ _ __ _   _  ___| |_ ___  _ __ 
			/ __/ _ \| '_ \/ __| __| '__| | | |/ __| __/ _ \| '__|
			| (_| (_) | | | \__ \ |_| |  | |_| | (__| || (_) | |   
			\___\___/|_| |_|___/\__|_|   \__,_|\___|\__\___/|_|   
																	
			
			*/
			explicit vector(allocator_type const & alloc = allocator_type())
			{
				_alloc = alloc;
				_size = 0;
				_ptr = _alloc.allocate(_size);
			};	
			explicit vector(size_type n,
							value_type const & val = value_type(),
							allocator_type const & alloc = allocator_type())
			{
				(void) n;
				(void) val;
				_alloc = alloc;
				_ptr = _alloc.allocate(0);
				_size = 0;
			};
			template <class InputIterator>
         	vector(InputIterator first,
			 		InputIterator last,
					allocator_type const & alloc = allocator_type())
			{
				(void) first;
				(void) last;
				_alloc = alloc;
				_ptr = _alloc.allocate(0);
				_size = 0;
			};
			vector (vector const & x)
			{
				*this = x;
			}
			
			/*
			
										_             
				___  _ __   ___ _ __ __ _| |_ ___  _ __ 
			/ _ \| '_ \ / _ \ '__/ _` | __/ _ \| '__|
			| (_) | |_) |  __/ | | (_| | || (_) | |   
			\___/| .__/ \___|_|  \__,_|\__\___/|_|   
					|_|                                 
			
			*/
			vector & operator=(vector const & x)
			{
				if (this != &x)
				{
					_alloc.deallocate(_ptr, _size);
					_size = x._size;
					_ptr = _alloc.allocate(_size);
					for (size_t i = 0; i < _size; i++)
						_ptr[i] = x._ptr[i];
				}
				return (*this);
			};

			/*
			
				_           _                   _             
				__| | ___  ___| |_ _ __ _   _  ___| |_ ___  _ __ 
			/ _` |/ _ \/ __| __| '__| | | |/ __| __/ _ \| '__|
			| (_| |  __/\__ \ |_| |  | |_| | (__| || (_) | |   
			\__,_|\___||___/\__|_|   \__,_|\___|\__\___/|_|   
																
			
			*/
			~vector()
			{
				_alloc.deallocate(_ptr, _size);
			};

			/*
								_                           _                                     
				___| | ___ _ __ ___   ___ _ __ | |_ ___    __ _  ___ ___ ___  ___ ___ 
			/ _ \ |/ _ \ '_ ` _ \ / _ \ '_ \| __/ __|  / _` |/ __/ __/ _ \/ __/ __|
			|  __/ |  __/ | | | | |  __/ | | | |_\__ \ | (_| | (_| (_|  __/\__ \__ \
			\___|_|\___|_| |_| |_|\___|_| |_|\__|___/  \__,_|\___\___\___||___/___/
																					
			
			*/
			reference	at(size_type n)
			{
				return (_ptr[n]);
			};
			const_reference	at(size_type n) const
			{
				return (_ptr[n]);
			};
			reference	operator[](size_type n)
			{
				return (_ptr[n]);
			};
			const_reference	operator[](size_type n) const
			{
				return (_ptr[n]);
			};
			reference	front()
			{
				return (_ptr[0]);
			};
			const_reference	front() const
			{
				return (_ptr[0]);
			};
			reference	back()
			{
				return (_ptr[_size - 1]);
			};
			const_reference	back() const
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
			void	push_back(value_type const & value)
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
			size_type	size() const
			{
				return (_size);
			};
			
			bool	empty() const
			{
				if (_size)
					return (false);
				return (true);
			};
		private:
			allocator_type	_alloc;
			value_type		*_ptr;
			size_type		_size;
	};
}

#endif
