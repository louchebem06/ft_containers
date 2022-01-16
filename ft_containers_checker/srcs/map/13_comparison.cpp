/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_comparison.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/31 19:01:03 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	run( T m1, T m2, std::string keyType, std::string valueType, std::string s ) {

	std::cout << std::boolalpha;
	std::cout << "▶️  " << s << " map<" << keyType << "," << valueType << ">" << std::endl;
	std::cout << "is equal? " << (m1 == m2) << std::endl;
	std::cout << "is not equal? " << (m1 != m2) << std::endl;
	std::cout << "is greater or equal than? " << (m1 >= m2) << std::endl;
	std::cout << "is lower or equal than? " << (m1 <= m2) << std::endl;
	std::cout << "is greater than ? " << (m1 > m2) << std::endl;
	std::cout << "is lower than ? " << (m1 < m2) << std::endl;

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing comparison...\033[0m" << std::endl << std::endl;

	ft::map<int, int>	map;
	for (int i = 0; i < 10; i++)
		map[i] = i;

	ft::map<int, int>	map2;
	for (int i = 0; i < 10; i++)
		map2[-i] = -i;

	ft::map<int, int>	map3;
	for (int i = 0; i < 5; i++)
		map3[i] = i;

	ft::map<int, int>	map4;
	for (int i = 0; i < 10; i++)
		map4[i] = i;

	run(map, map, INT, INT, "same");
	run(map, map2, INT, INT, "different");
	run(map, map3, INT, INT, "different");
	run(map2, map3, INT, INT, "different");
	run(map, map4, INT, INT, "same");


	return 0;
}
