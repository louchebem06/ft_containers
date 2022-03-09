/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:30:14 by bledda            #+#    #+#             */
/*   Updated: 2022/03/09 17:32:26 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../utils/utility.hpp"

namespace ft
{
	template <class Key, class T>
	struct node
	{
		typedef ft::pair<Key, T> type_value;

		type_value		value;
		node			*left;
		node			*right;
		node			*parent;
	};
}
