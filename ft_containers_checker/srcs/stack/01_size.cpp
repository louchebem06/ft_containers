/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_size.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/27 18:58:21 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	run( T stack, std::string s ) {

	checkSize(stack, s);

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing stack.size() and stack.empty()...\033[0m" << std::endl << std::endl;

	run(si, INT);
	run(si2, INT);
	run(si3, INT);

	run(ss, STR);
	run(ss2, STR);
	run(ss3, STR);

	run(sc, CHAR);
	run(sc2, CHAR);
	run(sc3, CHAR);

	return 0;
}
