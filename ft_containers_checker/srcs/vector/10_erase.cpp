/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_erase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 20:41:29 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	run( T v, std::string s ) {

	std::cout << "▶️  BEFORE ERASE:" << std::endl;
	display(v, s);

	for (size_t i = 0; i < 5; i++)
		v.erase(v.begin());
	std::cout << "▶️  AFTER ERASE 5 ELEMENTS ONE BY ONE:" << std::endl;
	display(v, s);

	v.erase(v.begin() + 2, v.end() - 1);
	std::cout << "▶️  AFTER ERASE A RANGE OF ELEMENTS (supposed to keep only 3 elements):" << std::endl;
	display(v, s);
	std::cout << "--------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing vector.erase()...\033[0m" << std::endl << std::endl;

	run(cont.vs2, STR);
	run(cont.vs3, STR);

	run(cont.vi2, INT);
	run(cont.vi3, INT);

	run(cont.vc2, CHAR);
	run(cont.vc3, CHAR);

	return 0;
}
