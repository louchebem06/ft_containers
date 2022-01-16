/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_front_back.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/29 15:09:54 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	testingFrontBack( T vec ) {

	std::cout << "front => [" << vec.front() << "]" << std::endl;
	std::cout << "back => [" << vec.back() << "]" << std::endl;
}

template< class T, class A >
void	run( T v, std::string s, A array, size_t size ) {

	std::cout << "▶️  BEFORE POP:" << std::endl;
	display(v, s);
	testingFrontBack(v);

	for (size_t i = 0; i < 5; i++)
		v.pop_back();

	std::cout << "▶️  AFTER POP:" << std::endl;
	display(v, s);
	testingFrontBack(v);

	T	vec = fillVec(v, array, size);

	std::cout << "▶️  AFTER PUSH:" << std::endl;
	display(vec, s);
	testingFrontBack(vec);

	std::cout << "--------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing vector.front() and vector.back()...\033[0m" << std::endl << std::endl;

	run(cont.vs2, STR, as, sizeS);
	run(cont.vs3, STR, as, sizeS);

	run(cont.vi2, INT, ai, sizeI);
	run(cont.vi3, INT, ai, sizeI);

	run(cont.vc2, CHAR, ac, sizeC);
	run(cont.vc3, CHAR, ac, sizeC);

	return 0;
}
