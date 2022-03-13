/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:10:59 by bledda            #+#    #+#             */
/*   Updated: 2022/03/13 08:14:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "pair.hpp"

namespace ft
{
	// https://www.cplusplus.com/reference/utility/make_pair/
	template <class T1,class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}
}
