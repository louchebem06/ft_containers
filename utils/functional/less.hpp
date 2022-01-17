/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:08:24 by bledda            #+#    #+#             */
/*   Updated: 2022/01/17 18:54:46 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "binary_function.hpp"

namespace ft
{
	// http://cplusplus.com/reference/functional/less/?kw=less
	template <class T>
	struct less : ft::binary_function <T, T, bool> {
		bool operator() (const T& x, const T& y) const {return x<y;}
	};
}
