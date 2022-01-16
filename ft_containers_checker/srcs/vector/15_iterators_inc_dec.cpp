/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_iterators_inc_dec.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/24 00:13:14 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	run( T vec ) {

	typename T::iterator	it = vec.begin(), tmp;

	std::cout << "🔽 iterator:" << std::endl;
	tmp = ++it;
	std::cout << "Pre increment [" << *tmp << "] [" << *it << "]" << std::endl;
	tmp = it++;
	std::cout << "Post increment [" << *tmp << "] [" << *it << "]" << std::endl;
	tmp = --it;
	std::cout << "Pre decrement [" << *tmp << "] [" << *it << "]" << std::endl;
	tmp = it--;
	std::cout << "Post decrement [" << *tmp << "] [" << *it << "]" << std::endl << std::endl;

	typename T::reverse_iterator ite = vec.rbegin(), rev;
	std::cout << "🔽 reverse_iterator:" << std::endl;
	rev = ++ite;
	std::cout << "Pre increment [" << *rev << "] [" << *ite << "]" << std::endl;
	rev = ite++;
	std::cout << "Post increment [" << *rev << "] [" << *ite << "]" << std::endl;
	rev = --ite;
	std::cout << "Pre decrement [" << *rev << "] [" << *ite << "]" << std::endl;
	rev = ite--;
	std::cout << "Post decrement [" << *rev << "] [" << *ite << "]" << std::endl << std::endl;

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing iterators operators...\033[0m" << std::endl << std::endl;

	vector<int>	vi;
	for (size_t i = 0; i < 10; i++)
		vi.push_back(i + 1);

	run(vi);

	vector<std::string>	vs;
	vs.push_back("1 a");
	vs.push_back("2 b");
	vs.push_back("3 c");
	vs.push_back("4 d");
	vs.push_back("5 e");
	vs.push_back("6 f");
	vs.push_back("7 g");
	vs.push_back("8 h");
	vs.push_back("9 i");
	vs.push_back("10 j");
	vs.push_back("11 k");
	vs.push_back("12 l");
	vs.push_back("13 m");
	vs.push_back("14 n");
	vs.push_back("15 o");
	vs.push_back("16 p");
	vs.push_back("17 q");
	vs.push_back("18 r");
	vs.push_back("19 s");
	vs.push_back("20 t");
	vs.push_back("21 u");
	vs.push_back("22 v");
	vs.push_back("23 w");
	vs.push_back("24 x");
	vs.push_back("25 y");
	vs.push_back("26 z");

	run(vs);

	return 0;
}
