/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17_swap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/11/01 10:46:45 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T>
void	run( T v1, T v2, std::string s ) {

	std::cout << "🔽  BEFORE SWAP..." << std::endl;
	std::cout << "Vector 1: " << std::endl;
	display(v1, s);
	std::cout << "Vector 2: " << std::endl;
	display(v2, s);

	std::cout << "🔽  AFTER SWAP..." << std::endl;
	v1.swap(v2);
	std::cout << "Vector 1: " << std::endl;
	display(v1, s);
	std::cout << "Vector 2: " << std::endl;
	display(v2, s);

	std::cout << "🔽  AFTER SWAP BACK..." << std::endl;
	swap(v1, v2);
	std::cout << "Vector 1: " << std::endl;
	display(v1, s);
	std::cout << "Vector 2: " << std::endl;
	display(v2, s);

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	Cont	cont;

	alarm(3);

	std::cout << "\033[33m[+] Testing iterators...\033[0m" << std::endl << std::endl;

	run(cont.vs2, cont.vs3, STR);

	run(cont.vi2, cont.vi3, INT);

	run(cont.vc2, cont.vc3, CHAR);

	return 0;
}
