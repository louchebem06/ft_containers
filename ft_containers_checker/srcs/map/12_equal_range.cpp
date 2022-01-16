/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_equal_range.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/11/01 18:52:19 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class T2 >
void	run( T map, std::string keyType, std::string valueType, T2 key ) {

	display(map, keyType, valueType);

	typename T::iterator lower, upper, ite = map.end();
	
	ft::pair<typename T::iterator, typename T::iterator>	range;

	lower = map.lower_bound(key);
	upper = map.upper_bound(key);
	range = map.equal_range(key);

	std::cout << "lower_bound(" << key << ") [";
	if (lower == ite)
		std::cout << "--end--]" << std::endl;
	else
		std::cout << lower->first << ":" << lower->second << "]" << std::endl;

	std::cout << "upper_bound(" << key << ") [";
	if (upper == ite)
		std::cout << "--end--]" << std::endl;
	else
		std::cout << upper->first << ":" << upper->second << "]" << std::endl;
	
	std::cout << "equal_range(" << key << ") " << ((range.first == lower && range.second == upper) ? OK : KO) << std::endl;

	
	std::cout << std::endl << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing map.equal_range()...\033[0m" << std::endl << std::endl;


	ft::map<int, int>	map;
	int		arrayI[] = {2, 5, 0, 10, 15, 16, 19, 20, -100, 1000};

	for (size_t i = 1; i <= 10; i++)
		map[i * 2] = i * 12;

	for (size_t i = 0; i < *(&arrayI + 1) - arrayI; i++)
		run(map, INT, INT, arrayI[i]);


	ft::map<char, std::string>	map2;
	std::string					arrayS[] = {"hello", "holà", "bonjour", "hi", "good morning", "adios"};
	char						arrayC[] = {'a', 'c', 'e', 'g', 'i', 'k'};
	char						arrayTest[] = {'A', 'a', 'b', 'e', 'i', 'j', 'k', 'l'};

	for (size_t i = 0; i < *(&arrayS + 1) - arrayS; i++)
		map2[arrayC[i]] = arrayS[i];

	for (size_t i = 0; i < *(&arrayTest + 1) - arrayTest; i++)
		run(map2, CHAR, STR, arrayTest[i]);


	return 0;
}
