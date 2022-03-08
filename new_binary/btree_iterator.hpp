/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:32:55 by bledda            #+#    #+#             */
/*   Updated: 2022/03/08 22:42:57 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../utils/iterator.hpp"

namespace ft
{
	template <class T>
	class btree_iterator :
		public iterator<bidirectional_iterator_tag, T>
	{
		protected:
			typedef iterator<bidirectional_iterator_tag, T>	iterator;
		public:
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference 			reference;
		public:
			btree_iterator() {};
			~btree_iterator() {};
	};
}