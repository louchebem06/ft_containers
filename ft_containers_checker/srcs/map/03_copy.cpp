/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_copy.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/31 15:10:16 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T map, A array, int size, std::string keyType, std::string valueType ) {

	for (int i = 0; i < size; i++)
		map[i] = array[i];

	std::cout << std::endl << "🔽 Original container" << std::endl;
	display(map, keyType, valueType);

	T	copy = map;
	T	copy2(map);

	std::cout << "🔽 Copy container" << std::endl;
	display(copy, keyType, valueType);

	std::cout << "🔽 Copy2 container" << std::endl;
	display(copy2, keyType, valueType);

	std::cout << "Adding " << size - 1 << " elements in the copy container..." << std::endl;
	for (int i = 0; i < size; i++)
		copy[-i] = array[i];

	std::cout << std::endl << "Adding " << size / 2 - 1 << " elements in the copy2 container..." << std::endl;
	for (int i = 0; i < size / 2; i++)
		copy2[-i] = array[i];

	std::cout << std::endl << "🔽 Original container AFTER" << std::endl;
	display(map, keyType, valueType);

	std::cout << "🔽 Copy container AFTER" << std::endl;
	display(copy, keyType, valueType);

	std::cout << "🔽 Copy2 container AFTER" << std::endl;
	display(copy2, keyType, valueType);
	
	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing copy not changing original with map<int, std::string>...\033[0m" << std::endl << std::endl;

	ft::map<int, std::string>	map;
	std::string 				arrayS[] = {"zéro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
	int							size = *(&arrayS + 1) - arrayS;

	run(map, arrayS, size, INT, STR);


	std::cout << "\033[33m[+] Testing copy not changing original with map<int, int>...\033[0m" << std::endl << std::endl;

	ft::map<int, int>	map2;
	int					arrayI[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size = *(&arrayI + 1) - arrayI;

	run(map2, arrayI, size, INT, INT);

	return 0;
}
