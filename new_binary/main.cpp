/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:40:38 by bledda            #+#    #+#             */
/*   Updated: 2022/03/10 21:40:02 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.hpp"

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

int main(void)
{
	ft::btree<int, int> test;

	for (int i = 0; i < COUNT; i++)
		test.insert(ft::make_pair(rand(), rand()));

	ft::btree<int, int>::iterator begin = test.begin();
	ft::btree<int, int>::iterator end = test.end();
	end++;
	for (; begin != end; begin++)
	{
		std::cout << (*begin).first << std::endl;
	}
}
