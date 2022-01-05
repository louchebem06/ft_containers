/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:05:55 by bledda            #+#    #+#             */
/*   Updated: 2022/01/05 21:34:43 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

int main(void)
{
	std::vector<std::string> real;
	ft::vector<std::string> fake;
	ft::vector<std::string> fake2;
	
	fake.push_back("coucou1");
	fake.push_back("coucou2");
	fake.push_back("coucou3");
	fake.push_back("coucou4");

	real.push_back("coucou1");
	real.push_back("coucou2");
	real.push_back("coucou3");
	real.push_back("coucou4");
	
	// fake2.assign(fake.begin(), fake.end());
	
	// try
	// {
	// 	fake2.resize(10, "Hello World");
	// }
	// catch(const std::exception& error)
	// {
	// 	std::cerr << "error: " << error.what() << std::endl;
	// }

	// try
	// {
	// 	real.resize(10, "Hello World");
	// }
	// catch(const std::exception& error)
	// {
	// 	std::cerr << "error: " << error.what() << std::endl;
	// }

	fake.erase(fake.begin() + 2);
	real.erase(real.begin() + 2);
	
	for (ft::vector<std::string>::iterator it = fake.begin(); it != fake.end(); it++)
		std::cout << *it << std::endl;
	
	std::cout << std::endl;

	for (std::vector<std::string>::iterator it = real.begin(); it != real.end(); it++)
		std::cout << *it << std::endl;
}
