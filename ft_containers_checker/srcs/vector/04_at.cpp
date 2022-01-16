/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_at.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 23:28:05 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T vec, std::string s, A array, size_t size ) {

	T	v = fillVec(vec, array, size);

	std::cout << "vector<" << s << "> Content: ";

	for (size_t i = 0; i < v.size(); i++)
		std::cout << "[" << i << " = " << v.at(i) << "] ";
	std::cout << std::endl;

	try {

		std::cout << v.at(v.size()) << std::endl;
	}
	catch (std::exception & e) {
		
		std::cout << RED << "Exception catched at index [" << v.size() << "]" << CLR << std::endl << std::endl;
	}

	std::cout << "------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing vector.at()...\033[0m" << std::endl << std::endl;

	run(cont.vs, STR, as, sizeS);
	run(cont.vs2, STR, as, sizeS);
	run(cont.vs3, STR, as, sizeS);

	run(cont.vi, INT, ai, sizeI);
	run(cont.vi2, INT, ai, sizeI);
	run(cont.vi3, INT, ai, sizeI);

	vector<int> const	vconst(15, 15);
	run(vconst, INT, ai, sizeC);

	run(cont.vc, CHAR, ac, sizeC);
	run(cont.vc2, CHAR, ac, sizeC);
	run(cont.vc3, CHAR, ac, sizeC);

	return 0;
}
