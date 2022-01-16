/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_top.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/27 19:01:17 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	run( T stack, std::string s ) {

	std::cout << "TOP stack<" << s << "> ==> [" << stack.top() << "]" << std::endl;

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing stack.top()...\033[0m" << std::endl << std::endl;

	run(si2, INT);
	run(si3, INT);

	run(ss2, STR);
	run(ss3, STR);

	run(sc2, CHAR);
	run(sc3, CHAR);

	return 0;
}
