/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:39:33 by bledda            #+#    #+#             */
/*   Updated: 2022/01/15 00:01:43 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{	
	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef	Iterator
															iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category
															iterator_category;
			typedef typename iterator_traits<Iterator>::value_type
															value_type;
			typedef typename iterator_traits<Iterator>::difference_type
															difference_type;
			typedef typename iterator_traits<Iterator>::pointer
															pointer;
			typedef typename iterator_traits<Iterator>::reference
															reference;
		private:
			iterator_type _iterator;
		public:
			reverse_iterator() {};
			explicit reverse_iterator (iterator_type it) : _iterator(it){};
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) :
				_iterator(rev_it.base()){};

			iterator_type base() const { return (_iterator); };

			reference operator*() const { return (*_iterator); };

			reverse_iterator operator+ (difference_type n) const {
				return (_iterator - n); };

			reverse_iterator& operator++() { return (_iterator--); };
			reverse_iterator  operator++(int) { return (--_iterator); };

			reverse_iterator& operator+= (difference_type n) {
				return (_iterator -= n); };

			reverse_iterator operator- (difference_type n) const {
				return (_iterator + n); };

			reverse_iterator& operator--() { return (_iterator++); };
			reverse_iterator  operator--(int) { return (++_iterator); };

			reverse_iterator& operator-= (difference_type n) {
				return (_iterator += n); };

			pointer operator->() const { return (_iterator.base()); };

			reference operator[] (difference_type n) const {
				return (*_iterator - n); };

			template <class Iterator_>
			friend reverse_iterator<Iterator_> operator+ (
						typename reverse_iterator<Iterator_>::difference_type n,
						const reverse_iterator<Iterator_>& rev_it);
			
			template <class Iterator_>
			friend typename reverse_iterator<Iterator_>::difference_type
			operator- (
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

	template <class Iterator_>
	class reverse_iterator<const Iterator_> : reverse_iterator<Iterator_> {};
}
