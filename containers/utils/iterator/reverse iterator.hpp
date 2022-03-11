/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:39:33 by bledda            #+#    #+#             */
/*   Updated: 2022/03/11 22:44:43 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{	
	template <class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator												iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
            typedef typename iterator_traits<Iterator>::value_type			value_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::pointer				pointer;
            typedef typename iterator_traits<Iterator>::reference			reference;
		private:
            iterator_type     _it;
        public:
            reverse_iterator() : _it() {}
            explicit reverse_iterator (iterator_type it) : _it(it) {}
			
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it)
				: _it(rev_it.base()) {}

            iterator_type base() const { return (_it); }

            reverse_iterator operator+ (difference_type n) const
			{ return (reverse_iterator(_it - n)); }

            reverse_iterator& operator++()
            {
                --_it;
                return (*this);
            }

            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }

            reverse_iterator& operator+= (difference_type n)
            {
                _it -= n;
                return (*this);
            }
	
            reverse_iterator operator- (difference_type n) const
			{ return (reverse_iterator(_it + n)); }

            reverse_iterator& operator--()
            {
                ++_it;
                return (*this);
            }
	
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }
	
            reverse_iterator& operator-= (difference_type n)
            {
                _it += n;
                return (*this);
            }

            pointer operator->() const
			{
				iterator_type tmp = _it;
                --tmp;
				return (tmp.operator->());
			}

			reference operator*() const
            {
                iterator_type tmp = _it;
				--tmp;
				return (tmp.operator*());
            }

            reference operator[] (difference_type n) const
			{ return (this->base()[-n - 1]); }
    };

	template <class Iterator_>
	reverse_iterator<Iterator_> operator+ (
		typename reverse_iterator<Iterator_>::difference_type n,
		const reverse_iterator<Iterator_>& rev_it) 
	{ return (reverse_iterator<Iterator_>(&(*rev_it.base()) - n));};
		
	template <class Iterator_, class Iterator__>
	typename reverse_iterator<Iterator_>::difference_type operator- (
		const reverse_iterator<Iterator_>& lhs,
		const reverse_iterator<Iterator__>& rhs)
	{ return (&(*rhs.base()) - &(*lhs.base())); };

	template <class Iterator_, class Iterator__>
	bool operator== (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{ return (&(*lhs.base()) == &(*rhs.base())); };

	template <class Iterator_, class Iterator__>
	bool operator!= (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{ return (&(*lhs.base()) != &(*rhs.base())); };

	template <class Iterator_, class Iterator__>
	bool operator<  (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{ return (&(*lhs.base()) > &(*rhs.base())); };

	template <class Iterator_, class Iterator__>
	bool operator<= (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{ return (&(*lhs.base()) >= &(*rhs.base())); };

	template <class Iterator_, class Iterator__>
	bool operator>  (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{ return (&(*lhs.base()) < &(*rhs.base())); };

	template <class Iterator_, class Iterator__>
	bool operator>= (const reverse_iterator<Iterator_>& lhs,
					const reverse_iterator<Iterator__>& rhs)
	{ return (&(*lhs.base()) <= &(*rhs.base())); };
}
