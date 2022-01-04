/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:05:55 by bledda            #+#    #+#             */
/*   Updated: 2022/01/05 00:05:16 by bledda           ###   ########.fr       */
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

	std::cout << real.empty() << std::endl;
	std::cout << fake.empty() << std::endl;
	
	real.push_back("Hello");
	fake.push_back("Hello");

	std::cout << real.max_size() << std::endl;
	std::cout << fake.max_size() << std::endl;

	std::cout << real.size() << std::endl;
	std::cout << fake.size() << std::endl;

	std::cout << real.empty() << std::endl;
	std::cout << fake.empty() << std::endl;

	std::cout << real[0] << std::endl;
	std::cout << fake[0] << std::endl;

	try
	{
		real.at(10);
    }
    catch (const std::exception& oor)
	{
        std::cerr << "Out of Range error: " << oor.what() << std::endl;
    }

	try
	{
    	fake.at(10);
    }
    catch (const std::exception& oor)
	{
        std::cerr << "Out of Range error: " << oor.what() << std::endl;
    }

	std::cout << real.size() << std::endl;
	std::cout << fake.size() << std::endl;

	std::cout << real.empty() << std::endl;
	std::cout << fake.empty() << std::endl;
	
	real.clear();
	fake.clear();	

	real.push_back("start");
	fake.push_back("start");
	real.push_back("end");
	fake.push_back("end");

	std::cout << real.size() << std::endl;
	std::cout << fake.size() << std::endl;

	std::cout << real.front() << std::endl;
	std::cout << fake.front() << std::endl;

	std::cout << real.back() << std::endl;
	std::cout << fake.back() << std::endl;

	std::cout << real.capacity() << std::endl;
	std::cout << fake.capacity() << std::endl;

	try
	{
		real.reserve(100);
    }
    catch (const std::exception& oor)
	{
        std::cerr << "Reserve: " << oor.what() << std::endl;
    }

	try
	{
    	fake.reserve(100);
    }
    catch (const std::exception& oor)
	{
        std::cerr << "Reserve: " << oor.what() << std::endl;
    }

	// for (int i = 0; i < 100; i++)
	// {
	// 	std::cout << "REAL SIZE : " << real.size() << std::endl;
	// 	std::cout << "REAL CAPACITY : " << real.capacity() << std::endl;
	// 	std::cout << "FAKE SIZE : " << real.size() << std::endl;
	// 	std::cout << "FAKE CAPACITY : " << real.capacity() << std::endl;
	// 	real.push_back("Coucou");
	// 	fake.push_back("Coucou");
	// 	std::cout << std::endl;
	// }
}
