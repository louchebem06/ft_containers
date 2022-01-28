/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:05:55 by bledda            #+#    #+#             */
/*   Updated: 2022/01/28 16:26:50 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <map>
#include <iostream>
#include <string>
#include "utils/node.hpp"
#include "utils/utility.hpp"

#define INT_TEST 7

int main()
{
	ft::B_tree<int, int> binary;
	ft::pair<int, int> ok[10];
	
	for (int i = 0; i < 10; i++)
		ok[i] = ft::pair<int, int>(i, 11);

	for (int i = 0; i < 10; i++)
		binary.insert(ok[rand() % 10]);

	binary.log(binary.master());
	
	std::cout << std::endl;

	std::cout << binary.begin()->data.first << std::endl;
	std::cout << binary.end()->data.first << std::endl;

	std::cout << std::endl;

	binary.testos();
}
