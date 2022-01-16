/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_insert.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/31 12:11:23 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
T	run( T map, A array, int size, std::string keyType, std::string valueType ) {

	std::cout << "Trying to insert Pair key/value..." << std::endl << std::endl;

	ft::pair<typename T::iterator, bool> ret;
	
	for (int i = 0; i < size; i++) {

		ret = map.insert(ft::make_pair(i, array[i]));
		std::cout << "Pair key [" << ret.first->first << "] value: [" << ret.first->second << "]";
		std::cout << (ret.second ? " has been inserted" : " failed to be inserted") << std::endl;
	}

	display(map, keyType, valueType);

	std::cout << "\033[33m[+] Testing insert with a range...\033[0m" << std::endl;
	
	T	range(map.begin(), map.end());
	display(range, keyType, valueType);
	std::cout << "-------------------------" << std::endl;

	return map;
}

template< class T, class A >
T	run( T map, A key, A value, int size, std::string keyType, std::string valueType ) {

	std::cout << "Trying to insert Pair key/value..." << std::endl << std::endl;

	ft::pair<typename T::iterator, bool> ret;
	
	for (int i = 0; i < size; i++) {

		ret = map.insert(ft::make_pair(key[i], value[i]));
		std::cout << "Pair key [" << ret.first->first << "] value: [" << ret.first->second << "]";
		std::cout << (ret.second ? " has been inserted" : " failed to be inserted") << std::endl;
	}

	display(map, keyType, valueType);


	std::cout << "\033[33m[+] Testing insert with a range...\033[0m" << std::endl;
	
	T	range(map.begin(), map.end());
	display(range, keyType, valueType);

	std::cout << "-------------------------" << std::endl;

	return map;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing insert with map<int, std::string>...\033[0m" << std::endl << std::endl;

	std::string arrayS[] = {"zéro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
	int			size = *(&arrayS + 1) - arrayS;

	ft::map<int, std::string>	map;

	map = run(map, arrayS, size, INT, STR);
	run(map, arrayS, size, INT, STR);


	std::cout << "\033[33m[+] Testing insert with map<std::string, std::string>...\033[0m" << std::endl << std::endl;

	ft::map<std::string, std::string>	map2;

	map2 = run(map2, arrayS, arrayS, size, STR, STR);
	run(map2, arrayS, arrayS, size, STR, STR);


	std::cout << "\033[33m[+] Testing insert with map<int, int>...\033[0m" << std::endl << std::endl;

	int	arrayI[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size = *(&arrayI + 1) - arrayI;

	ft::map<int, int>	map3;

	map3 = run(map3, arrayI, size, INT, INT);
	run(map3, arrayI, size, INT, INT);

	
	std::cout << "\033[33m[+] Testing insert values in reverse order with map<int, int>...\033[0m" << std::endl << std::endl;

	int	arrayI2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	ft::map<int, int>	map4;

	map4 = run(map4, arrayI2, arrayI2, size, INT, INT);
	run(map4, arrayI2, arrayI2, size, INT, INT);


	return 0;
}
