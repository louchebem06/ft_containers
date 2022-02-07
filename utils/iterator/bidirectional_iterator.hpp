/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:38:10 by bledda            #+#    #+#             */
/*   Updated: 2022/02/07 11:09:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_class.hpp"

namespace ft
{
	template <class T>
	class bidirectional_iterator :
		public iterator<bidirectional_iterator_tag, T>
	{
		protected:
			typedef iterator<bidirectional_iterator_tag, T>	iterator;
		public:
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference 			reference;
		public:
			pointer base() const { return (this->_ptr); };
		public:
			bidirectional_iterator () { this->_ptr = 0; };
			bidirectional_iterator (pointer ptr) { this->_ptr = ptr; };
			bidirectional_iterator (bidirectional_iterator const & rhs) {
				*this = rhs; };

			bidirectional_iterator & operator=(
				bidirectional_iterator const & rhs)
			{
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};
			
			// https://stackoverflow.com/questions/57718018/how-do-i-convert-iterator-to-const-iterator-in-my-custom-list-iterator-class
			operator bidirectional_iterator<const T> () {
				return (bidirectional_iterator<const T> (this->_ptr));
			};
		public:
			bidirectional_iterator & operator++() {
				this->_ptr++;
				return (*this);
			};

			bidirectional_iterator operator++(int) {
				bidirectional_iterator tmp = this->_ptr;
				this->_ptr++;
				return (tmp);
			};

			bidirectional_iterator & operator--() {
				this->_ptr--;
				return (*this);
			};

			bidirectional_iterator operator--(int) {
				bidirectional_iterator tmp = this->_ptr;
				this->_ptr--;
				return (tmp);
			};

			bool operator==(bidirectional_iterator const & rhs) const {
				if (this->base() == rhs._ptr)
					return (true);
				return (false);
			};
			bool operator==(bidirectional_iterator<const T> & rhs) const {
				if (this->base() == rhs.base())
					return (true);
				return (false);
			};

			bool operator!=(bidirectional_iterator const & rhs) const {
				if (this->base() != rhs._ptr)
					return (true);
				return (false);
			};
			bool operator!=(bidirectional_iterator<const T> & rhs) const {
				if (this->base() != rhs.base())
					return (true);
				return (false);
			};

			reference operator*() const { return (*(this->_ptr)); };
			pointer operator->() { return (this->_ptr); };
	};

	template <class T_, class T__>
	bool operator== (const bidirectional_iterator<T_>& lhs,
					const bidirectional_iterator<T__>& rhs)
	{
		if (lhs.base() == rhs.base())
			return (true);
		return (false);
	};

	template <class T_, class T__>
	bool operator!= (const bidirectional_iterator<T_>& lhs,
					const bidirectional_iterator<T__>& rhs)
	{
		if (lhs.base() != rhs.base())
			return (true);
		return (false);
	};
}
