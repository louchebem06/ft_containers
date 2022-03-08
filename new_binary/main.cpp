/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:40:38 by bledda            #+#    #+#             */
/*   Updated: 2022/03/08 21:47:12 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.hpp"

void printValue(ft::node<int, int> *node, std::string msg)
{
	std::cout << msg << " =>" << std::endl;
	if (node != NULL)
	{
		std::cout << "\tKEYS : " << node->value.first << std::endl;
		std::cout << "\tVALUE : " << node->value.second << std::endl;
		std::cout << std::endl;
	}
	else
		std::cout << "(NULL)" << std::endl;
}

void printValue(ft::node<int, int> *node)
{
	if (node == NULL)
	{
		std::cout << "NULL MASTER" << std::endl;
		return ;
	}
	printValue(node, "Me");
	printValue(node->parent, "Parent");
	printValue(node->left, "Left");
	printValue(node->right, "Right");
}

int main(void)
{
	ft::btree<int, int> test;

	test.insert(ft::make_pair(1, 2));
	test.insert(ft::make_pair(3, 4));
	test.insert(ft::make_pair(2, 3));
	test.insert(ft::make_pair(10, 11));
	test.insert(ft::make_pair(6, 7));
	test.insert(ft::make_pair(0, 1));
	test.insert(ft::make_pair(1, 2));
	test.insert(ft::make_pair(11, 12));

	std::cout << "Size : " << test.size() << std::endl;

	test.tree();

	std::cout << std::endl;
	test.remove(2);
	test.tree();

	std::cout << std::endl;
	test.remove(3);
	test.tree();

	std::cout << "Size : " << test.size() << std::endl;

	std::cout << std::endl;
	ft::node<int, int> * tmp;
	if (test.exist(10))
	{
		tmp = test.search(10);
		printValue(tmp);
		std::cout << std::endl;
	}

	std::cout << "Size : " << test.size() << std::endl;

	return (0);
}
