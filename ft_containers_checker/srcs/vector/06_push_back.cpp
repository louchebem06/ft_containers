/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_push_back.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 20:42:39 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T vec, std::string s, A array, size_t size ) {


	std::cout << "▶️  BEFORE PUSH_BACK:" << std::endl;
	display(vec, s);
	checkSize(vec, s, false);

	T	v = fillVec(vec, array, size);
	std::cout << "▶️  AFTER PUSH_BACK:" << std::endl;
	display(v, s);
	checkSize(v, s, false);
	std::cout << "--------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing vector.push_back()...\033[0m" << std::endl << std::endl;

	run(cont.vs, STR, as, sizeS);
	run(cont.vs2, STR, as, sizeS);
	run(cont.vs3, STR, as, sizeS);

	run(cont.vi, INT, ai, sizeI);
	run(cont.vi2, INT, ai, sizeI);
	run(cont.vi3, INT, ai, sizeI);

	run(cont.vc, CHAR, ac, sizeC);
	run(cont.vc2, CHAR, ac, sizeC);
	run(cont.vc3, CHAR, ac, sizeC);

	return 0;
}
