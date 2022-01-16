/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_swap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/11/01 10:31:35 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	run( T map, T map2, std::string keyType, std::string valueType ) {

	std::cout << "🔽 map BEFORE swap" << std::endl;
	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << "🔽 map2 BEFORE swap" << std::endl;
	display(map2, keyType, valueType);
	checkSize(map2, keyType, valueType);


	map.swap(map2);

	std::cout << "🔽 map AFTER swap" << std::endl;
	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << "🔽 map2 AFTER swap" << std::endl;
	display(map2, keyType, valueType);
	checkSize(map2, keyType, valueType);


	ft::swap(map, map2);

	std::cout << "🔽 map AFTER swap back" << std::endl;
	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << "🔽 map2 AFTER swap back" << std::endl;
	display(map2, keyType, valueType);
	checkSize(map2, keyType, valueType);

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing map.swap()...\033[0m" << std::endl << std::endl;

	std::string arrayS[] = {"zéro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
	int			size = *(&arrayS + 1) - arrayS;

	ft::map<int, std::string>	map;
	ft::map<int, std::string>	map2;

	for (int i = 0; i < size; i++) {

		map[i] = arrayS[i];
		if (i % 2)
			map2[-i] = arrayS[size - i];
	}
	run(map, map2, INT, STR);


	int	arrayI[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size = *(&arrayI + 1) - arrayI;

	ft::map<int, int>	map3;
	ft::map<int, int>	map4;

	for (int i = 0; i < size; i++) {

		map3[i] = arrayI[i];
		if (i % 2)
			map4[-i] = arrayI[size - i];
	}
	run(map3, map4,INT, INT);

	return 0;
}
