/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:39:33 by bledda            #+#    #+#             */
/*   Updated: 2022/01/18 15:12:04 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
		protected:
			pointer _ptr;
		public:
			reverse_iterator() {};
			explicit reverse_iterator (iterator_type it) : _ptr(&(*it) - 1) {};
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) :
				_ptr(&(*rev_it.base()) - 1) {};

			iterator_type base() const { return (iterator_type(_ptr + 1)); };

			reference operator*() const { return (*_ptr); };

			reverse_iterator operator+ (difference_type n) const {
				pointer tmp;

				tmp = _ptr - n + 1;
				return (reverse_iterator(tmp));
			};

			reverse_iterator& operator++() {
				_ptr--;
				return (*this);
			};
			reverse_iterator  operator++(int) {
				pointer tmp = _ptr + 1;
				--_ptr;
				return (reverse_iterator(tmp));
			};

			reverse_iterator& operator+= (difference_type n) {
				_ptr -= n;
				return (*this);
			};

			reverse_iterator operator- (difference_type n) const {
				iterator_type tmp;

				tmp = _ptr + n + 1;
				return (reverse_iterator(tmp));
			};

			reverse_iterator& operator--() {
				_ptr++;
				return (*this);
			};
			reverse_iterator  operator--(int) {
				pointer tmp = _ptr + 1;
				++_ptr;
				return (reverse_iterator(tmp));
			};

			reverse_iterator& operator-= (difference_type n) {
				_ptr += n;
				return (*this);
			};

			pointer operator->() const { return (_ptr); };

			reference operator[] (difference_type n) const {
				return (*(_ptr - n));
			};
	};
	template <class Iterator_>
	reverse_iterator<Iterator_> operator+ (
		typename reverse_iterator<Iterator_>::difference_type n,
		const reverse_iterator<Iterator_>& rev_it) 
	{
		return (reverse_iterator<Iterator_>(&(*rev_it.base()) - n));
	};
	template <class Iterator_, class Iterator__>
	typename reverse_iterator<Iterator_>::difference_type operator- (
		const reverse_iterator<Iterator_>& lhs,
		const reverse_iterator<Iterator__>& rhs)
	{
		return (&(*rhs.base()) - &(*lhs.base()));
	};

	template <class Iterator_, class Iterator__>
	bool operator== (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{
		return (&(*lhs.base()) == &(*rhs.base()));
	};

	template <class Iterator_, class Iterator__>
	bool operator!= (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{
		return (&(*lhs.base()) != &(*rhs.base()));
	};

	template <class Iterator_, class Iterator__>
	bool operator<  (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{
		return (&(*lhs.base()) > &(*rhs.base()));
	};

	template <class Iterator_, class Iterator__>
	bool operator<= (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{
		return (&(*lhs.base()) >= &(*rhs.base()));
	};

	template <class Iterator_, class Iterator__>
	bool operator>  (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{
		return (&(*lhs.base()) < &(*rhs.base()));
	};

	template <class Iterator_, class Iterator__>
	bool operator>= (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{
		return (&(*lhs.base()) <= &(*rhs.base()));
	};
}
