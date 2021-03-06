/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:38:10 by bledda            #+#    #+#             */
/*   Updated: 2022/03/13 07:40:34 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_class.hpp"

#define RAIT	iterator<random_access_iterator_tag, T>

namespace ft
{
	template <class T>
	class random_access_iterator :
		public iterator<random_access_iterator_tag, T>
	{
		public:
			typedef typename RAIT::value_type			value_type;
			typedef typename RAIT::difference_type		difference_type;
			typedef typename RAIT::iterator_category	iterator_category;
			typedef typename RAIT::reference 			reference;
			typedef typename RAIT::pointer				pointer;
		public:
			pointer base() const { return (this->_ptr); };
		public:
			random_access_iterator () { this->_ptr = 0; };
			random_access_iterator (pointer ptr) { this->_ptr = ptr; };
			random_access_iterator (random_access_iterator const & rhs) {
				*this = rhs; };

			random_access_iterator & operator=(
				random_access_iterator const & rhs)
			{
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

			bool operator==(random_access_iterator const & rhs) const {
				if (this->base() == rhs._ptr)
					return (true);
				return (false);
			};
			bool operator==(random_access_iterator<const T> & rhs) const {
				if (this->base() == rhs.base())
					return (true);
				return (false);
			};

			bool operator!=(random_access_iterator const & rhs) const {
				if (this->base() != rhs._ptr)
					return (true);
				return (false);
			};
			bool operator!=(random_access_iterator<const T> & rhs) const {
				if (this->base() != rhs.base())
					return (true);
				return (false);
			};

			bool operator<(random_access_iterator const & rhs) const {
				if (this->base() < rhs._ptr)
					return (true);
				return (false);
			};
			bool operator<(random_access_iterator<const T> & rhs) const {
				if (this->base() < rhs.base())
					return (true);
				return (false);
			};
			
			bool operator>(random_access_iterator const & rhs) const {
				if (this->base() > rhs._ptr)
					return (true);
				return (false);
			};
			bool operator>(random_access_iterator<const T> & rhs) const {
				if (this->base() > rhs.base())
					return (true);
				return (false);
			};

			bool operator<=(random_access_iterator const & rhs) const {
				if (this->base() <= rhs._ptr)
					return (true);
				return (false);
			};
			bool operator<=(random_access_iterator<const T> & rhs) const {
				if (this->base() <= rhs.base())
					return (true);
				return (false);
			};

			bool operator>=(random_access_iterator const & rhs) const {
				if (this->base() >= rhs._ptr)
					return (true);
				return (false);
			};
			bool operator>=(random_access_iterator<const T> & rhs) const {
				if (this->base() >= rhs.base())
					return (true);
				return (false);
			};
			
			random_access_iterator	operator-(difference_type n) const { return (this->_ptr - n); };
			random_access_iterator	operator+(difference_type n) const { return (this->_ptr + n); };
			
			template <class T_>
			friend random_access_iterator<T_> operator+(
				typename random_access_iterator<T_>::difference_type n,
				random_access_iterator<T_> const & rhs);

			template <class T_>
			friend random_access_iterator<T_> operator-(
				typename random_access_iterator<T_>::difference_type n,
				random_access_iterator<T_> const & rhs);

			reference operator*() const { return (*(this->_ptr)); };
			pointer operator->() { return (this->_ptr); };
			reference operator[](size_t n) const { return (*(this->_ptr + n)); };
	};

	template <class T_>
	random_access_iterator<T_> operator+(
		typename random_access_iterator<T_>::difference_type n,
		random_access_iterator<T_> const & rhs)
	{
		return (rhs._ptr + n);
	};
	template <class T_>
	random_access_iterator<T_> operator-(
		typename random_access_iterator<T_>::difference_type n,
		random_access_iterator<T_> const & rhs)
	{
		random_access_iterator<T_> tmp = rhs._ptr - n;
		return (tmp);
	};

	template <class T_, class T__>
	typename random_access_iterator<T_>::difference_type operator- (
		const random_access_iterator<T_>& lhs,
		const random_access_iterator<T__>& rhs)
	{
		return (lhs.base() - rhs.base());
	};

	template <class T_, class T__>
	bool operator== (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T__>& rhs)
	{
		if (lhs.base() == rhs.base())
			return (true);
		return (false);
	};

	template <class T_, class T__>
	bool operator!= (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T__>& rhs)
	{
		if (lhs.base() != rhs.base())
			return (true);
		return (false);
	};

	template <class T_, class T__>
	bool operator<  (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T__>& rhs)
	{
		if (lhs.base() < rhs.base())
			return (true);
		return (false);
	};

	template <class T_, class T__>
	bool operator<= (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T__>& rhs)
	{
		if (lhs.base() <= rhs.base())
			return (true);
		return (false);
	};
	
	template <class T_, class T__>
	bool operator>  (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T__>& rhs)
	{
		if (lhs.base() > rhs.base())
			return (true);
		return (false);
	};
	
	template <class T_, class T__>
	bool operator>= (const random_access_iterator<T_>& lhs,
					const random_access_iterator<T__>& rhs)
	{
		if (lhs.base() >= rhs.base())
			return (true);
		return (false);
	};
}
