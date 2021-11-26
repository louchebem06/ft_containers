/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:30:03 by bledda            #+#    #+#             */
/*   Updated: 2021/11/26 11:25:56 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <string>
#include <iostream>

using namespace ft;

int main(void)
{
	vector<int> test;

	std::cout << test.size() << std::endl;
	test.push_back(44);
	std::cout << test.size() << " " << test[0] << std::endl;
	test.push_back(42);
	std::cout << test.size() << " " << test.at(1) << std::endl;
}
