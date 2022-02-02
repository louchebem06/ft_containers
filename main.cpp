/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:27:30 by bledda            #+#    #+#             */
/*   Updated: 2022/02/02 13:23:49 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include <utility>
#include "utils/node.hpp"
#include <iostream>

int main(void)
{
	ft::map<int, int> test;

	test.insert(ft::pair<int, int>(5, 11));
	test.insert(test.begin(), ft::pair<int, int>(10, 11));
	ft::map<int, int>::iterator it2 = test.insert(test.begin(), ft::pair<int, int>(3, 11));
	test.insert(test.begin(), ft::pair<int, int>(19, 11));

	test.insert(it2, ft::pair<int, int>(55, 11));

	for (ft::map<int, int>::iterator it = test.begin();
	it != test.end(); it++)
		std::cout << (*it).first << std::endl;
}
