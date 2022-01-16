/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_iterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 22:12:26 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class It, class Ite >
void	displayVec( It begin, Ite end ) {

	for (; begin != end; begin++)
		std::cout << "[" << *begin << "] ";

	std::cout << std::endl << std::endl; 
}

template< class T, class A >
void	run( T v, std::string s, A array, size_t size ) {

	T	vec = fillVec(v, array, size);

	std::cout << "vector<" << s << ">::iterator:" << std::endl;
	typename T::iterator it = vec.begin(), ite = vec.end();
	displayVec(it, ite);

	std::cout << "vector<" << s << ">::const_iterator:" << std::endl;
	typename T::const_iterator itc = vec.begin(), itec = vec.end();
	displayVec(itc, itec);

	std::cout << "vector<" << s << ">::reverse_iterator:" << std::endl;
	typename T::reverse_iterator itr = vec.rbegin(), iter = vec.rend();
	displayVec(itr, iter);

	std::cout << "vector<" << s << ">::const_reverse_iterator:" << std::endl;
	typename T::const_reverse_iterator itcr = vec.rbegin(), itecr = vec.rend();
	displayVec(itcr, itecr);
	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing iterators...\033[0m" << std::endl << std::endl;

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
