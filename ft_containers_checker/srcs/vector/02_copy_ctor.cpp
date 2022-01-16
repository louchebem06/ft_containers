/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_operator_arrow.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 23:08:43 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T vec, std::string s, A array, size_t size ) {

	std::cout << "🔽  ORIGINAL VECTOR" << std::endl;
	display(vec, s);

	std::cout << "🔽  COPY CONSTRUCTOR" << std::endl;
	T	v(vec);
	display(v, s);

	std::cout << "🔽  OPERATOR =" << std::endl;
	T	v2 = v;
	T	v3 = fillVec(v2, array, size);
	v2.pop_back();
	v2.pop_back();

	display(v, s);
	display(v2, s);
	display(v3, s);

	std::cout << "---------------------------" << std::endl << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing copy constructors...\033[0m" << std::endl << std::endl;

	run(cont.vs2, STR, as, sizeS);
	run(cont.vs3, STR, as, sizeS);

	run(cont.vi2, INT, ai, sizeI);
	run(cont.vi3, INT, ai, sizeI);

	run(cont.vc2, CHAR, ac, sizeC);
	run(cont.vc3, CHAR, ac, sizeC);

	return 0;
}
