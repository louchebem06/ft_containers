/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:31:49 by bledda            #+#    #+#             */
/*   Updated: 2022/01/14 15:41:53 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"

namespace ft
{
	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type size = 0;

		while (first != last)
		{
			first++;
			size++;
		}
		return (size);
	};
}
