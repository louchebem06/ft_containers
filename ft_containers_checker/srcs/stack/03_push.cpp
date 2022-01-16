/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_push.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/27 19:26:34 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T stack, std::string s, A array, size_t size ) {

	checkSize(stack, s);

	for (size_t i = 0; i < size; i++) {
		
		std::cout << "Push an element in the stack (" << array[i] << ")" << std::endl;
		stack.push(array[i]);
		std::cout << "TOP stack after PUSH ==> [" << stack.top() << "]" << std::endl;
	}

	std::cout << std::endl;

	checkSize(stack, s);

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing stack.push()...\033[0m" << std::endl << std::endl;

	run(si, INT, ai, sizeI);
	run(si2, INT, ai, sizeI);
	run(si3, INT, ai, sizeI);

	run(ss, STR, as, sizeS);
	run(ss2, STR, as, sizeS);
	run(ss3, STR, as, sizeS);

	run(sc, CHAR, ac, sizeC);
	run(sc2, CHAR, ac, sizeC);
	run(sc3, CHAR, ac, sizeC);

	return 0;
}
