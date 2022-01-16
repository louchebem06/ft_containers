/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_iterator.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/31 13:22:35 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T map, A array, int size ) {

	for (int i = 0; i < size; i++)
		map[i] = array[i];

	std::cout << "Display with iterators..." << std::endl;
	for (typename T::iterator it = map.begin(); it != map.end(); ++it)
        std::cout << "[" << it->first << " : " << it->second << "] ";

	std::cout << std::endl << std::endl << "Display with const_iterators..." << std::endl;
	for (typename T::const_iterator it = map.begin(); it != map.end(); ++it)
        std::cout << "[" << it->first << " : " << it->second << "] ";

	std::cout << std::endl << std::endl << "Display with reverse_iterators..." << std::endl;
	for (typename T::reverse_iterator it = map.rbegin(); it != map.rend(); ++it)
        std::cout << "[" << it->first << " : " << it->second << "] ";

	std::cout << std::endl << std::endl << "Display with const_reverse_iterators..." << std::endl;
	for (typename T::const_reverse_iterator it = map.rbegin(); it != map.rend(); ++it)
        std::cout << "[" << it->first << " : " << it->second << "] ";

	std::cout << std::endl << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing iterators...\033[0m" << std::endl << std::endl;

	std::string arrayS[] = {"zéro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
	int			size = *(&arrayS + 1) - arrayS;

	ft::map<int, std::string>	map;
	run(map, arrayS, size);


	int	arrayI[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size = *(&arrayI + 1) - arrayI;

	ft::map<int, int>	map2;
	run(map2, arrayI, size);

	return 0;
}
