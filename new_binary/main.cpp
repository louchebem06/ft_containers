/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:40:38 by bledda            #+#    #+#             */
/*   Updated: 2022/03/10 21:31:07 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.hpp"

int main(void)
{
	ft::btree<int, int> test;

	for (int i = 0; i < 100; i++)
		test.insert(ft::make_pair(random() % 100, 12));

	test.tree();

	ft::btree<int, int>::iterator begin = test.begin();
	ft::btree<int, int>::iterator end = test.end();
	end++;
	for (; begin != end; begin++)
	{
		std::cout << (*begin).first << std::endl;
	}
}
