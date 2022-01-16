/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_at.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/31 14:57:31 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T map, A array, int size ) {

	for (int i = 0; i < size; i++)
		map[i] = array[i];

	for (int i = 0; i < size; i++)
		std::cout << "map[" << i << "] => [" << map.at(i) << "]" << std::endl;

	try {
		
		std::cout << std::endl << "Attempt to access an element out of range at key " << size << "..." << std::endl;
		std::cout << "map[" << size << "] => " << map.at(size) << "]" << std::endl;
	}
	catch (std::exception &e) {

		std::cout << RED << "Exception catched" << CLR << std::endl;
	}	

	std::cout << std::endl << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing map.at()...\033[0m" << std::endl << std::endl;

	std::string arrayS[] = {"zéro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
	int			size = *(&arrayS + 1) - arrayS;

	ft::map<int, std::string>	map;
	run(map, arrayS, size);


	int	arrayI[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size = *(&arrayI + 1) - arrayI;

	ft::map<int, int>	map2;
	run(map2, arrayI, size);

	ft::map<int, int> const	mapConst;
	run(mapConst, arrayI, size);

	return 0;
}
