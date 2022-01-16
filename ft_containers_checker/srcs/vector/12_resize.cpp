/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_resize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 20:40:34 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class Type >
void	run( T vec, std::string s, Type content ) {

	size_t	size = vec.size();

	std::cout << "▶️  BEFORE resize:" << std::endl;
	display(vec, s);
	checkSize(vec, s);

	std::cout << "▶️  AFTER resize with content (size *= 2):" << std::endl;
	vec.resize(size * 2, content);
	display(vec, s);
	checkSize(vec, s);

	std::cout << "▶️  AFTER resize to 0:" << std::endl;
	vec.resize(0);
	display(vec, s);
	checkSize(vec, s);

	std::cout << "▶️  AFTER resize with content to size = 10000" << std::endl;
	vec.resize(10000, content);
	display(vec, s);
	checkSize(vec, s);

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing vector.resize()...\033[0m" << std::endl << std::endl;

	run(cont.vs, STR, "unknown element");
	run(cont.vs2, STR, ".........elements added..........");
	run(cont.vs3, STR, "new element");

	run(cont.vi, INT, 666);
	run(cont.vi2, INT, 333);
	run(cont.vi3, INT, 999);

	return 0;
}
