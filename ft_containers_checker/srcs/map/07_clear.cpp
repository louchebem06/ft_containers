/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_clear.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/31 14:58:18 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T map, A array, int size, std::string keyType, std::string valueType ) {

	for (int i = 0; i < size; i++)
		map[i] = array[i];

	std::cout << "🔽 Map content BEFORE clear" << std::endl;
	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << "🔽 Map content AFTER clear" << std::endl;
	map.clear();
	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing map.clear()...\033[0m" << std::endl << std::endl;

	std::string arrayS[] = {"zéro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
	int			size = *(&arrayS + 1) - arrayS;

	ft::map<int, std::string>	map;
	run(map, arrayS, size, INT, STR);


	int	arrayI[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size = *(&arrayI + 1) - arrayI;

	ft::map<int, int> const		mapConst;
	run(mapConst, arrayI, size, INT, INT);

	return 0;
}
