/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:05:55 by bledda            #+#    #+#             */
/*   Updated: 2022/01/08 02:37:49 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "utils/type_traits.hpp"
#include "utils/utility.hpp"
#include "utils/algorithm.hpp"
#include <list>

int main (void)
{
	ft::vector<std::string>::iterator it, end;
	ft::vector<std::string> fake;

	fake.push_back("hello");
	fake.push_back("World");
	fake.push_back("testos");

	for (it = fake.begin(), end = fake.end(); it != end; it++)
	{
		std::cout << "Value : " << *it << std::endl;
	}
}
