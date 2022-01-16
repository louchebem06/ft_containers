/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_pop_back.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 20:42:25 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	run( T v, std::string s ) {

	std::cout << "▶️  BEFORE POP:" << std::endl;
	display(v, s);
	checkSize(v, s, false);

	for (size_t i = 0; i < 10; i++)
		v.pop_back();

	std::cout << "▶️  AFTER POP:" << std::endl;
	display(v, s);
	checkSize(v, s, false);
	
	std::cout << "--------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing vector.pop_back()...\033[0m" << std::endl << std::endl;

	run(cont.vs2, STR);
	run(cont.vs3, STR);

	run(cont.vi2, INT);
	run(cont.vi3, INT);

	run(cont.vc2, CHAR);
	run(cont.vc3, CHAR);

	return 0;
}
