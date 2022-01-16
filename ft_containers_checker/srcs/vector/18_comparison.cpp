/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_comparison.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/27 19:31:42 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	run( T vec, T vec2, std::string type, std::string s ) {

	std::cout << std::boolalpha;
	std::cout << "▶️  " << s << " vector<" << type << ">" << std::endl;
	std::cout << "is equal? " << (vec == vec2) << std::endl;
	std::cout << "is not equal? " << (vec != vec2) << std::endl;
	std::cout << "is greater or equal than? " << (vec >= vec2) << std::endl;
	std::cout << "is lower or equal than? " << (vec <= vec2) << std::endl;
	std::cout << "is greater than ? " << (vec > vec2) << std::endl;
	std::cout << "is lower than ? " << (vec < vec2) << std::endl;

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing comparison...\033[0m" << std::endl << std::endl;

	vector<int>	vi;
	for (size_t i = 0; i < 5; i++)
		vi.push_back(i);

	vector<int>	vi2;
	for (size_t i = 0; i < 10; i++)
		vi2.push_back(-i);

	run(vi, vi, INT, "same");
	run(vi, vi2, INT, "different");

	vector<std::string>	vs;
	vs.push_back("hello");

	vector<std::string>	vs2;
	vs2.push_back("heello");

	run(vs, vs, STR, "same");
	run(vs, vs2, STR, "different");

	return 0;
}
