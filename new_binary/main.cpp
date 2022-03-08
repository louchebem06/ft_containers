/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:40:38 by bledda            #+#    #+#             */
/*   Updated: 2022/03/08 19:46:48 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.hpp"

void printValue(ft::node *node, std::string msg)
{
	std::cout << msg << " : ";
	if (node != NULL)
		std::cout << node->key_value << std::endl;
	else
		std::cout << "(NULL)" << std::endl;
}

void printValue(ft::node *node)
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
	ft::btree<> test;

	test.insert(5);
	test.insert(3);
	test.insert(2);
	test.insert(10);
	test.insert(6);
	test.insert(0);
	test.insert(1);
	test.insert(11);

	std::cout << "Size : " << test.size() << std::endl;

	test.tree();

	std::cout << std::endl;
	test.remove(3);
	test.remove(11);
	test.tree();

	std::cout << "Size : " << test.size() << std::endl;

	std::cout << std::endl;
	ft::node * tmp;
	if (test.exist(10))
	{
		tmp = test.search(10);
		printValue(tmp);
		std::cout << std::endl;
	}

	std::cout << "Size : " << test.size() << std::endl;

	return (0);
}
