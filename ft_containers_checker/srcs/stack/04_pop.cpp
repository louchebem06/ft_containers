/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_pop.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/27 19:24:58 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
T   fillStack( T stack, A array, size_t size ) {

    for (size_t i = 0; i < size; i++)
        stack.push(array[i]);
    return stack;
}

template< class T, class A >
void	run( T st, std::string s, A array, size_t size ) {

	T	stack = fillStack(st, array, size);

	checkSize(stack, s);

	size_t	len = stack.size();

	for (size_t i = 0; i < len; i++) {
		
		std::cout << "Pop an element out of the stack" << std::endl;
		stack.pop();
		if (i < len - 1)
			std::cout << "TOP stack after POP ==> [" << stack.top() << "]" << std::endl;
		checkSize(stack, s);
	}

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
