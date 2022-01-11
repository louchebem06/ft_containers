/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:52:54 by bledda            #+#    #+#             */
/*   Updated: 2022/01/11 02:33:06 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

// Iterator tags
namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};
}

// Iterator traits
namespace ft
{
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
}

// Iterator
namespace ft
{
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
}

// Reverse iterator
namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef	Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
		private:
			iterator_type _iterator;
		public:
			reverse_iterator() {};
			explicit reverse_iterator (iterator_type it) { this->_iterator = it; };
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) { this->_iterator = rev_it; };

			iterator_type base() const { return (this->_iterator); };

			reference operator*() const { return (this->*_iterator); };

			reverse_iterator operator+ (difference_type n) const { return (this->_iterator - n); };

			reverse_iterator& operator++() { return (this->_iterator--); };
			reverse_iterator  operator++(int) { return (--this->_iterator); };

			reverse_iterator& operator+= (difference_type n) {return (this->_iterator -= n); };

			reverse_iterator operator- (difference_type n) const { return (this->_iterator + n); };

			reverse_iterator& operator--() { return (this->_iterator++); };
			reverse_iterator  operator--(int) { return (++this->_iterator); };

			reverse_iterator& operator-= (difference_type n) {return (this->_iterator += n); };

			pointer operator->() const { return (this->*_iterator); };

			reference operator[] (difference_type n) const { return (this->*_iterator - n); };

			template <class Iterator_>
			friend reverse_iterator<Iterator_> operator+ (
						typename reverse_iterator<Iterator_>::difference_type n,
						const reverse_iterator<Iterator_>& rev_it);
			
			template <class Iterator_>
			friend typename reverse_iterator<Iterator_>::difference_type operator- (
				const reverse_iterator<Iterator_>& lhs,
				const reverse_iterator<Iterator_>& rhs);

			template <class Iterator_>
			friend bool operator== (const reverse_iterator<Iterator_>& lhs,
							const reverse_iterator<Iterator_>& rhs);
							
			template <class Iterator_>
			friend bool operator!= (const reverse_iterator<Iterator_>& lhs,
							const reverse_iterator<Iterator_>& rhs);
							
			template <class Iterator_>
			friend bool operator<  (const reverse_iterator<Iterator_>& lhs,
							const reverse_iterator<Iterator_>& rhs);
							
			template <class Iterator_>
			friend bool operator<= (const reverse_iterator<Iterator_>& lhs,
							const reverse_iterator<Iterator_>& rhs);
							
			template <class Iterator_>
			friend bool operator>  (const reverse_iterator<Iterator_>& lhs,
							const reverse_iterator<Iterator_>& rhs);
							
			template <class Iterator_>
			friend bool operator>= (const reverse_iterator<Iterator_>& lhs,
							const reverse_iterator<Iterator_>& rhs);
	};
	template <class Iterator_>
	reverse_iterator<Iterator_> operator+ (
				typename reverse_iterator<Iterator_>::difference_type n,
				const reverse_iterator<Iterator_>& rev_it) 
	{
		return (rev_it._iterator - n);
	};
	template <class Iterator_>
	typename reverse_iterator<Iterator_>::difference_type operator- (
		const reverse_iterator<Iterator_>& lhs,
		const reverse_iterator<Iterator_>& rhs)
	{
		return (lhs.base() - rhs.base());
	};
	template <class Iterator_>
	bool operator== (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator_>& rhs)
	{
		if (lhs == rhs)
			return (true);
		return (false);
	};			
	template <class Iterator_>
	bool operator!= (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator_>& rhs)
	{
		if (lhs != rhs)
			return (true);
		return (false);
	};					
	template <class Iterator_>
	bool operator<  (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator_>& rhs)
	{
		if (lhs < rhs)
			return (true);
		return (false);
	};					
	template <class Iterator_>
	bool operator<= (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator_>& rhs)
	{
		if (lhs <= rhs)
			return (true);
		return (false);
	};					
	template <class Iterator_>
	bool operator>  (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator_>& rhs)
	{
		if (lhs > rhs)
			return (true);
		return (false);
	};						
	template <class Iterator_>
	bool operator>= (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator_>& rhs)
	{
		if (lhs >= rhs)
			return (true);
		return (false);
	};
}

// Random access iterator
namespace ft
{
	template <class T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		protected:
			typedef iterator<random_access_iterator_tag, T>	iterator;
		public:
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename iterator::reference 			reference;
			typedef typename iterator::pointer				pointer;
		public:
			pointer base() const { return (this->_ptr); };
		public:
			random_access_iterator () { this->_ptr = 0; };
			random_access_iterator (pointer ptr) { this->_ptr = ptr; };
			random_access_iterator (random_access_iterator const & rhs) { *this = rhs; };
			random_access_iterator & operator=(random_access_iterator const & rhs) {
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
			
			// https://stackoverflow.com/questions/57718018/how-do-i-convert-iterator-to-const-iterator-in-my-custom-list-iterator-class
			operator random_access_iterator<const T> () {
				return (random_access_iterator<const T> (this->_ptr));
			};
		public:
			random_access_iterator & operator++() {
				this->_ptr++;
				return (*this);
			};

			random_access_iterator operator++(int) {
				random_access_iterator tmp = this->_ptr;
				this->_ptr++;
				return (tmp);
			};

			random_access_iterator & operator--() {
				this->_ptr--;
				return (*this);
			};

			random_access_iterator operator--(int) {
				random_access_iterator tmp = this->_ptr;
				this->_ptr--;
				return (tmp);
			};

			random_access_iterator operator+=(difference_type n) {
				this->_ptr += n;
				return (*this);
			};

			random_access_iterator operator-=(difference_type n) {
				this->_ptr -= n;
				return (*this);
			};

			bool operator==(random_access_iterator const & rhs) {
				if (this->base() == rhs._ptr)
					return (true);
				return (false);
			};
			bool operator==(random_access_iterator<const T> & rhs) {
				if (this->base() == rhs.base())
					return (true);
				return (false);
			};

			bool operator!=(random_access_iterator const & rhs) {
				if (this->base() != rhs._ptr)
					return (true);
				return (false);
			};
			bool operator!=(random_access_iterator<const T> & rhs) {
				if (this->base() != rhs.base())
					return (true);
				return (false);
			};

			bool operator<(random_access_iterator const & rhs) {
				if (this->base() < rhs._ptr)
					return (true);
				return (false);
			};
			bool operator<(random_access_iterator<const T> & rhs) {
				if (this->base() < rhs.base())
					return (true);
				return (false);
			};
			
			bool operator>(random_access_iterator const & rhs) {
				if (this->base() > rhs._ptr)
					return (true);
				return (false);
			};
			bool operator>(random_access_iterator<const T> & rhs) {
				if (this->base() > rhs.base())
					return (true);
				return (false);
			};

			bool operator<=(random_access_iterator const & rhs) {
				if (this->base() <= rhs._ptr)
					return (true);
				return (false);
			};
			bool operator<=(random_access_iterator<const T> & rhs) {
				if (this->base() <= rhs.base())
					return (true);
				return (false);
			};

			bool operator>=(random_access_iterator const & rhs) {
				if (this->base() >= rhs._ptr)
					return (true);
				return (false);
			};
			bool operator>=(random_access_iterator<const T> & rhs) {
				if (this->base() >= rhs.base())
					return (true);
				return (false);
			};
			
			random_access_iterator	operator-(size_t n) { return (this->_ptr - n); };
			random_access_iterator	operator+(size_t n) { return (this->_ptr + n); };
			
			template <class T_>
			friend random_access_iterator<T_> operator+(
				size_t n, random_access_iterator<T_> const & rhs);

			template <class T_>
			friend random_access_iterator<T_> operator-(
				size_t n, random_access_iterator<T_> const & rhs);

			reference operator*() { return (*(this->_ptr)); };
			reference operator->() { return (*(this->_ptr)); };
			reference operator[](size_t n) { return (*(this->_ptr + n)); };
	};

	template <class T_>
	random_access_iterator<T_> operator+(
		typename iterator<random_access_iterator_tag, T_>::difference_type n,
		random_access_iterator<T_> const & rhs)
	{
		random_access_iterator<T_> tmp = rhs._ptr + n;
		return (tmp);
	};
	template <class T_>
	random_access_iterator<T_> operator-(
		typename iterator<random_access_iterator_tag, T_>::difference_type n,
		random_access_iterator<T_> const & rhs)
	{
		random_access_iterator<T_> tmp = rhs._ptr - n;
		return (tmp);
	};
	template <class T_>
	typename random_access_iterator<T_>::difference_type operator- (
		const random_access_iterator<T_>& lhs,
		const random_access_iterator<T_>& rhs)
	{
		return (lhs.base() - rhs.base());
	};
	template <class T_>
	bool operator== (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T_>& rhs)
	{
		if (lhs.base() == rhs.base())
			return (true);
		return (false);
	};					
	template <class T_>
	bool operator!= (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T_>& rhs)
	{
		if (lhs.base() != rhs.base())
			return (true);
		return (false);
	};					
	template <class T_>
	bool operator<  (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T_>& rhs)
	{
		if (lhs.base() < rhs.base())
			return (true);
		return (false);
	};					
	template <class T_>
	bool operator<= (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T_>& rhs)
	{
		if (lhs.base() <= rhs.base())
			return (true);
		return (false);
	};					
	template <class T_>
	bool operator>  (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T_>& rhs)
	{
		if (lhs.base() > rhs.base())
			return (true);
		return (false);
	};					
	template <class T_>
	bool operator>= (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T_>& rhs)
	{
		if (lhs.base() >= rhs.base())
			return (true);
		return (false);
	};
}
