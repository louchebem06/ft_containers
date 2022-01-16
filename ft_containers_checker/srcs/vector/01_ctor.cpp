/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ctor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 19:50:41 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	run( T vec, std::string s ) {

	display(vec, s);
	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing constructors...\033[0m" << std::endl << std::endl;

	run(cont.vs, STR);
	run(cont.vs2, STR);
	run(cont.vs3, STR);

	run(cont.vi, INT);
	run(cont.vi2, INT);
	run(cont.vi3, INT);

	run(cont.vc, CHAR);
	run(cont.vc2, CHAR);
	run(cont.vc3, CHAR);

	return 0;
}
