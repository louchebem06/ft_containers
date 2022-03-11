/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:58:38 by bledda            #+#    #+#             */
/*   Updated: 2022/01/14 14:58:58 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "integral constant.hpp"

namespace ft
{
	// https://www.cplusplus.com/reference/type_traits/is_integral/
	template <class T>
		struct is_integral :
			public integral_constant<T, false>{};
	template <class T>
		struct is_integral<const T> : is_integral<T>{};
	
	template <>
		struct is_integral<bool> :
			public integral_constant<bool, true>{};
	template <>
		struct is_integral<char> :
			public integral_constant<char, true>{};
	template <>
		struct is_integral<wchar_t> :
			public integral_constant<wchar_t, true>{};
	template <>
		struct is_integral<signed char> :
			public integral_constant<signed char, true>{};
	template <>
		struct is_integral<short int> :
			public integral_constant<short int, true>{};
	template <>
		struct is_integral<int> :
			public integral_constant<int, true>{};
	template <>
		struct is_integral<long int> :
			public integral_constant<long int, true>{};
	template <>
		struct is_integral<long long int> :
			public integral_constant<long long int, true>{};
	template <>
		struct is_integral<unsigned char> :
			public integral_constant<unsigned char, true>{};
	template <>
		struct is_integral<unsigned short int> :
			public integral_constant<unsigned short int, true>{};
	template <>
		struct is_integral<unsigned int> :
			public integral_constant<unsigned int, true>{};
	template <>
		struct is_integral<unsigned long int> :
			public integral_constant<unsigned long int, true>{};
	template <>
		struct is_integral<unsigned long long int> :
			public integral_constant<unsigned long long int, true>{};
}
