/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_operator_bracket.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 19:49:04 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T vec, std::string s, A array, size_t size ) {

	T	v = fillVec(vec, array, size);

	std::cout << "vector<" << s << "> Content: ";

	for (size_t i = 0; i < v.size(); i++)
		std::cout << "[" << i << " = " << v[i] << "] ";

	std::cout << "---------------------------" << std::endl << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing vector[]...\033[0m" << std::endl << std::endl;

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
