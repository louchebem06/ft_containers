/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_comparison.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/27 19:30:58 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	run( T s1, T s2, std::string type, std::string s ) {

	std::cout << std::boolalpha;
	std::cout << "▶️  " << s << " stack<" << type << ">" << std::endl;
	std::cout << "is equal? " << (s1 == s2) << std::endl;
	std::cout << "is not equal? " << (s1 != s2) << std::endl;
	std::cout << "is greater or equal than? " << (s1 >= s2) << std::endl;
	std::cout << "is lower or equal than? " << (s1 <= s2) << std::endl;
	std::cout << "is greater than ? " << (s1 > s2) << std::endl;
	std::cout << "is lower than ? " << (s1 < s2) << std::endl;

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing comparison...\033[0m" << std::endl << std::endl;

	stack<int>	si;
	for (size_t i = 0; i < 5; i++)
		si.push(i);

	stack<int>	si2;
	for (size_t i = 0; i < 10; i++)
		si2.push(-i);

	run(si, si, INT, "same");
	run(si, si2, INT, "different");

	stack<std::string>	ss;
	ss.push("hello");

	stack<std::string>	ss2;
	ss2.push("heello");

	run(ss, ss, STR, "same");
	run(ss, ss2, STR, "different");

	return 0;
}
