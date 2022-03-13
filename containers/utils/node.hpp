/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:30:14 by bledda            #+#    #+#             */
/*   Updated: 2022/03/13 08:30:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utility.hpp"

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

		node(type_value const & value, node *left, node *right, node *parent)
		{
			this->value = value;
			this->left = left;
			this->right = right;
			this->parent = parent;
		}
	};
}
