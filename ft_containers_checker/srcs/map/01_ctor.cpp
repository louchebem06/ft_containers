/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ctor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/31 13:29:10 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing constructors...\033[0m" << std::endl << std::endl;

	ft::map<int, std::string>			map;
	ft::map<std::string, std::string>	map2;
	ft::map<int, int>					map3;
	ft::map<double, float>				map4;
	ft::map<char, int>					map5;
	ft::map<std::string, char>			map6;

	ft::map<std::string, char>			copy = map6;
	ft::map<std::string, char>			copy2(map6);


	return 0;
}
