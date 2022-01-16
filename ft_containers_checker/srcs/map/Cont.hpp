/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cont.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:25:12 by aldubar           #+#    #+#             */
/*   Updated: 2021/11/01 19:52:08 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONT_HPP
# define CONT_HPP

# if STL
	#  include <map>
	namespace ft = std;
# else
	#  include "map.hpp"
# endif

# include <string>
# include <iostream>
# include <unistd.h>

# define STR	"std::string"
# define INT	"int"
# define CHAR	"char"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CLR	"\033[0m"
# define OK		"[ \033[32mOK\033[0m ]"
# define KO		"[ \033[31mKO\033[0m ]"

template< class T >
void	display( T map, std::string keyType, std::string valueType ) {
			
	std::cout << std::endl << "[+] map<" << keyType << "," << valueType << "> content: " << std::endl << std::endl << "{ ";

	typename T::iterator	it, ite = map.end();
	for (it = map.begin(); it != ite; it++)
		std::cout << it->first << ":" << it->second << " ";

	std::cout << "}" << std::endl << std::endl;
}

template< class T >
void	checkSize( T map, std::string keyType, std::string valueType ) {

	std::cout << "[+] Testing size, max_size, empty" << std::endl;
	std::cout << "map<" << keyType << ", " << valueType << "> size: " << map.size() << std::endl;
	std::cout << "map<" << keyType << ", " << valueType << "> max_size: " << (map.max_size() >= map.size() ? OK : KO) << std::endl;
	std::cout << std::boolalpha << "is empty ? " << map.empty() << std::endl;

	std::cout << std::endl;
}

#endif
