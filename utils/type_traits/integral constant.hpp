/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:58:38 by bledda            #+#    #+#             */
/*   Updated: 2022/01/14 14:57:49 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	// https://www.cplusplus.com/reference/type_traits/integral_constant/
	template <class T, bool v>
	struct integral_constant
	{
		static const	bool 									value = v;
		typedef 		T										value_type;
		typedef 		integral_constant<value_type, value>	type;

		operator value_type() { return (value); }
	};
}
