/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_insert.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 20:41:51 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class Type >
void	run( T v, std::string s, Type ins, bool B ) {

	std::cout << "▶️  BEFORE INSERT:" << std::endl;
	display(v, s);

	v.insert(v.begin(), ins);
	std::cout << "▶️  AFTER INSERT AN ELEMENT:" << std::endl;
	display(v, s);

	if (B == false) {
		std::cout << "---------------------" << std::endl;
		return;
	}

	v.insert(v.begin() + 2, 5, ins);
	std::cout << "▶️  AFTER INSERT A RANGE OF ELEMENTS:" << std::endl;
	display(v, s);
	std::cout << "--------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing vector.insert()...\033[0m" << std::endl << std::endl;

	run(cont.vs, STR, "attempt to insert elements in an empty vector...", false);
	run(cont.vs2, STR, "attempt to insert elements...", true);
	run(cont.vs3, STR, "elements inserted!!!", true);

	run(cont.vi, INT, 666, false);
	run(cont.vi2, INT, 897689, true);
	run(cont.vi3, INT, 98729809280, true);

	run(cont.vc, CHAR, '!', false);
	run(cont.vc2, CHAR, '@', true);
	run(cont.vc3, CHAR, '$', true);

	return 0;
}
