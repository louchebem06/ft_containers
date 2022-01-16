/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_assign.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 20:41:09 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class Type >
void	run( T vec, std::string s, Type content ) {

	std::cout << "▶️  BEFORE ASSIGN" << std::endl;
	display(vec, s);

	std::cout << "▶️  AFTER ASSIGN 8 ELEMENTS" << std::endl;
	vec.assign(8, content);
	display(vec, s);

	T	copy = vec;
	std::cout << "▶️  AFTER ASSIGN A RANGE OF ELEMENTS (4 elements)" << std::endl;
	copy.assign(vec.begin() + 1, vec.begin() + 5);
	display(copy, s);

	std::cout << "---------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing vector.assign()...\033[0m" << std::endl << std::endl;

	run(cont.vs, STR, "aaaaaaaaaaaaaaaa");
	run(cont.vs2, STR, "eeeeeeeeeeeeeeeeeeeeeeee");
	run(cont.vs3, STR, "pppppppppp");
	run(cont.vi, INT, 42);
	run(cont.vi2, INT, 43);
	run(cont.vi3, INT, 44);
	run(cont.vc, CHAR, '$');
	run(cont.vc2, CHAR, '&');
	run(cont.vc3, CHAR, '?');

	return 0;
}
