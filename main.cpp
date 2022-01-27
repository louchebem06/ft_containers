/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:05:55 by bledda            #+#    #+#             */
/*   Updated: 2022/01/27 11:06:55 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <map>
#include <iostream>
#include <string>
#include "utils/node.hpp"
#include "utils/utility.hpp"

int main()
{
	ft::B_tree<int, int> binary;
	ft::pair<int, int> ok[100];
	
	for (int i = 0; i < 100; i++)
		ok[i] = ft::pair<int, int>(i, 11);
	
	std::cout << "pair setup" << std::endl;
	for (int i = 0; i < 100; i++)
		binary.insert(ok[rand() % 100]);
	std::cout << "end insert" << std::endl;

	binary.log(binary.first());
}
