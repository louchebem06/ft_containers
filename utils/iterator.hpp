/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:52:54 by bledda            #+#    #+#             */
/*   Updated: 2022/01/08 02:44:08 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};
	
	template <class Iterator>
	class iterator_traits
	{
        typedef typename Iterator::difference_type		difference_type;
        typedef typename Iterator::value_type			value_type;
        typedef typename Iterator::pointer				pointer;
        typedef typename Iterator::reference			reference;
        typedef typename Iterator::iterator_category	iterator_category;
	};
	
	template <class T>
	struct iterator_traits<T*>
	{
        typedef ptrdiff_t					difference_type;
        typedef T							value_type;
        typedef T*							pointer;
        typedef T&							reference;
        typedef random_access_iterator_tag	iterator_category;
	};
	
	template <class T>
	struct iterator_traits<const T*>
	{
        typedef ptrdiff_t					difference_type;
        typedef T							value_type;
        typedef const T*					pointer;
        typedef const T&					reference;
        typedef random_access_iterator_tag	iterator_category;
	};

	template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	class iterator
	{
		public:
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
		protected:
			pointer _ptr;
	};

	template <class T>
	class input_iterator : virtual public iterator<input_iterator_tag, T>
	{
		protected:
			typedef iterator<input_iterator_tag, T> 		iterator;
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename iterator::reference 			reference;
			typedef typename iterator::pointer				pointer;
		protected:
			input_iterator() {};
		public:
			input_iterator (pointer ptr) { this->_ptr = ptr; };
			input_iterator (input_iterator const & rhs) { *this = rhs; };
			input_iterator & operator=(input_iterator const & rhs)
			{
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
			virtual ~input_iterator() {};

			input_iterator operator++(int)
			{
				input_iterator tmp = this->_ptr;
				this->_ptr++;
				return (tmp);
			};

			input_iterator & operator++()
			{
				this->_ptr++;
				return (*this);
			};

			bool operator==(input_iterator const & rhs)
			{
				if (this->_ptr == rhs._ptr)
					return (true);
				return (false);
			};
			bool operator!=(input_iterator const & rhs)
			{
				if (this->_ptr != rhs._ptr)
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
	};

	template <class T>
	class output_iterator : virtual public iterator<output_iterator_tag, T>,
								virtual public input_iterator<T>
	{
		protected:
			typedef iterator<output_iterator_tag, T> 		iterator;
			typedef input_iterator<T>						input_iterator;
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename iterator::reference 			reference;
			typedef typename iterator::pointer				pointer;
		protected:
			output_iterator() : input_iterator() {};
		public:
			using input_iterator::_ptr;
			output_iterator (pointer ptr) : input_iterator(ptr) {};
			output_iterator (output_iterator const & rhs) { *this = rhs; };
			output_iterator & operator=(output_iterator const & rhs)
			{
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
			virtual ~output_iterator() {};
	};

	/*
		forward doit etre input output
		input output doit etre seul
	*/

	template <class T>
	class forward_iterator : virtual public iterator<forward_iterator_tag, T>,
								virtual public output_iterator<T>
	{
		protected:
			typedef iterator<forward_iterator_tag, T>			iterator;
			typedef output_iterator<T>							output_iterator;
			typedef typename output_iterator::input_iterator	input_iterator;
			typedef typename iterator::value_type				value_type;
			typedef typename iterator::difference_type			difference_type;
			typedef typename iterator::iterator_category		iterator_category;
			typedef typename iterator::reference 				reference;
			typedef typename iterator::pointer					pointer;
		public:
			using output_iterator::_ptr;
			forward_iterator () : output_iterator() { this->_ptr = 0; };
			forward_iterator (pointer ptr) : output_iterator(ptr) {};
			forward_iterator (forward_iterator const & rhs) { *this = rhs; };
			forward_iterator & operator=(forward_iterator const & rhs)
			{
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
			virtual ~forward_iterator() {};
	};

	template <class T>
	class bidirectional_iterator : virtual public iterator<bidirectional_iterator_tag, T>,
									virtual public forward_iterator<T>
	{
		protected:
			typedef iterator<bidirectional_iterator_tag, T>		iterator;
			typedef forward_iterator<T>							forward_iterator;
			typedef typename forward_iterator::input_iterator	input_iterator;
			typedef typename forward_iterator::output_iterator	output_iterator;
			typedef typename iterator::value_type				value_type;
			typedef typename iterator::difference_type			difference_type;
			typedef typename iterator::iterator_category		iterator_category;
			typedef typename iterator::reference 				reference;
			typedef typename iterator::pointer					pointer;
		public:
			using forward_iterator::_ptr;
			bidirectional_iterator () : forward_iterator() {};
			bidirectional_iterator (pointer ptr) : forward_iterator(ptr) {};
			bidirectional_iterator (bidirectional_iterator const & rhs) { *this = rhs; };
			bidirectional_iterator & operator=(bidirectional_iterator const & rhs)
			{
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
			virtual ~bidirectional_iterator() {};
	};

	template <class T>
	class random_access_iterator : virtual public iterator<random_access_iterator_tag, T>,
									virtual public bidirectional_iterator<T>
	{
		protected:
			typedef iterator<random_access_iterator_tag, T> 			iterator;
			typedef bidirectional_iterator<T>							bidirectional_iterator;
			typedef typename bidirectional_iterator::forward_iterator	forward_iterator;
			typedef typename bidirectional_iterator::input_iterator		input_iterator;
			typedef typename bidirectional_iterator::output_iterator	output_iterator;
			typedef typename iterator::value_type						value_type;
			typedef typename iterator::difference_type					difference_type;
			typedef typename iterator::iterator_category				iterator_category;
			typedef typename iterator::reference 						reference;
			typedef typename iterator::pointer							pointer;
		public:
			using bidirectional_iterator::_ptr;
			random_access_iterator () : bidirectional_iterator() {};
			random_access_iterator (pointer ptr) : bidirectional_iterator(ptr) {};
			random_access_iterator (random_access_iterator const & rhs) { *this = rhs; };
			random_access_iterator & operator=(random_access_iterator const & rhs)
			{
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
			virtual ~random_access_iterator() {};
	};
}
