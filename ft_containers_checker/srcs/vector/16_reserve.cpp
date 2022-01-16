/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_reserve.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 23:22:35 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T v, std::string s, A array, size_t size ) {

	T	vec = fillVec(v, array, size);

	std::cout << "▶️  BEFORE RESERVE" << std::endl;
	display(vec, s);
	checkSize(vec, s);

	std::cout << "▶️  AFTER RESERVE TO 100" << std::endl;
	vec.reserve(100);
	display(vec, s);
	checkSize(vec, s);

	std::cout << "▶️  AFTER RESERVE TO 0" << std::endl;
	vec.reserve(0);
	display(vec, s);
	checkSize(vec, s);

	std::cout << "▶️  AFTER RESERVE TO CAPACITY * 2" << std::endl;
	vec.reserve(vec.capacity() * 2);
	display(vec, s);
	checkSize(vec, s);

	std::cout << "--------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing vector.reserve()...\033[0m" << std::endl << std::endl;

	run(cont.vs, STR, as, sizeS);
	run(cont.vs2, STR, as, sizeS);
	run(cont.vs3, STR, as, sizeS);

	run(cont.vi, INT, ai, sizeI);
	run(cont.vi2, INT, ai, sizeI);
	run(cont.vi3, INT, ai, sizeI);

	return 0;
}
