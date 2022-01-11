/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:05:55 by bledda            #+#    #+#             */
/*   Updated: 2022/01/11 17:38:44 by bledda           ###   ########.fr       */
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
#include "stack.hpp"
#include <stack>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

int		main(void)
{
	TESTED_NAMESPACE::vector<std::string> test;
	for (int i = 0; i < 50000; i++)
		test.push_back("abcd");
	test.erase(test.end() - 5, test.end());
	return (0);
}
