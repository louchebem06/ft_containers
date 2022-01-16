/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_count.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/31 16:37:02 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A, class T2 >
void	run( T map, A array, size_t size, std::string keyType, std::string valueType, T2 notAKey ) {

	display(map, keyType, valueType);

	for (size_t i = 0; i < size; i++)
		std::cout << "existing key [" << array[i] << "] => " << map.count(array[i]) << std::endl;

	std::cout << "not existing key [" << notAKey << "] => " << map.count(notAKey) << std::endl;

	std::cout << std::endl << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing map.count()...\033[0m" << std::endl << std::endl;


	ft::map<std::string, std::string>	map;
	std::string							arrayS[] = { "key", "key2", "key3", "key5", "key5" };
	size_t								size = *(&arrayS + 1) - arrayS;

	for (size_t i = 0; i < size; i++)
		map[arrayS[i]] = "random_useless_value";

	run(map, arrayS, size, STR, STR, "unknown key");



	ft::map<char, char>	map2;
	char				arrayC[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
	size = *(&arrayC + 1) - arrayC;

	for (size_t i = 0; i < size; i++)
		map2[arrayC[i]] = arrayC[i] + 32;

	run(map2, arrayC, size, CHAR, CHAR, '*');

	return 0;
}
