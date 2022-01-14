/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enable if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:58:38 by bledda            #+#    #+#             */
/*   Updated: 2022/01/14 14:57:34 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	// https://www.cplusplus.com/reference/type_traits/enable_if/
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> {typedef T type;};
}
