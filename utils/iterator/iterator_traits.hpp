/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:35:36 by bledda            #+#    #+#             */
/*   Updated: 2022/01/14 15:36:05 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template <class Iterator>
	struct iterator_traits
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
