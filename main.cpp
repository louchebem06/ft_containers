/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:27:30 by bledda            #+#    #+#             */
/*   Updated: 2022/03/10 21:47:02 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/btree.hpp"

int main(void)
{
	ft::btree<int, int> test;

	for (int i = 0; i < 100; i++)
		test.insert(ft::make_pair(rand(), rand()));

	ft::btree<int, int>::iterator end = test.end();
	end++;
	for (ft::btree<int, int>::iterator it = test.begin(); it != end; it++)
		std::cout << (*it).first << std::endl;
}
