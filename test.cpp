/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:30:03 by bledda            #+#    #+#             */
/*   Updated: 2021/11/27 11:10:26 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <string>
#include <iostream>
#include <vector>

int main(void)
{
	ft::vector<std::string> ft_test;
	std::vector<std::string> std_test;

	std::cout << ft_test.size() << std::endl;
	std::cout << std_test.size() << std::endl;

	std::cout << ft_test.empty() << std::endl;
	std::cout << std_test.empty() << std::endl;

	std::cout << ft_test.max_size() << std::endl;
	std::cout << std_test.max_size() << std::endl;
}
