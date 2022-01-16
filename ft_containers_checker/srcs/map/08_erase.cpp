/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_erase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/31 14:59:07 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T map, A array, int size, std::string keyType, std::string valueType ) {

	for (int i = 0; i < size; i++)
		map[i] = array[i];

	std::cout << "🔽 Map content BEFORE erase" << std::endl;
	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << std::endl << "🔽 Map content AFTER erase the first element" << std::endl;
	map.erase(map.begin());
	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << std::endl << "🔽 Map content AFTER erase the last element" << std::endl;
	map.erase(--map.end());
	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << std::endl << "🔽 Map content AFTER erase a range of elements keeping the first and the last" << std::endl;
	map.erase(++map.begin(), --map.end());
	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << "🔽 Map content AFTER erase all elements remaining" << std::endl;
	for (int i = 0; i < 2; i++)
		map.erase(map.begin());

	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing map.erase()...\033[0m" << std::endl << std::endl;

	std::string arrayS[] = {"zéro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
	int			size = *(&arrayS + 1) - arrayS;

	ft::map<int, std::string>	map;
	run(map, arrayS, size, INT, STR);


	int	arrayI[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size = *(&arrayI + 1) - arrayI;

	ft::map<int, int> const	mapConst;
	run(mapConst, arrayI, size, INT, INT);

	return 0;
}
