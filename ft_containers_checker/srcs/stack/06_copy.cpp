/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_copy.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/27 19:58:54 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T >
void	run( T stack, T copy ) {

	std::cout << std::boolalpha;
	std::cout << "size: " << stack.size() << " vs " << copy.size() << " " << (stack.size() == copy.size() ? OK : KO) << std::endl;
	std::cout << "is empty? " << stack.empty() << " vs " << copy.empty() << " " << (stack.empty() == copy.empty() ? OK : KO) << std::endl << std::endl;

	std::cout << "Pop 2 elements in the copy stack..." << std::endl;
	copy.pop();
	copy.pop();

	std::cout << "stack top ==> [" << stack.top() << "] vs [" << copy.top() << "] " << (stack.top() != copy.top() ? OK : KO) << std::endl;

	std::cout << "size: " << stack.size() << " vs " << copy.size() << " " << (stack.size() != copy.size() ? OK : KO) << std::endl;
	std::cout << "is empty? " << stack.empty() << " vs " << copy.empty() << " " << (stack.empty() == copy.empty() ? OK : KO) << std::endl << std::endl;


	std::cout << "Pop the last element in the copy stack..." << std::endl;
	copy.pop();

	std::cout << "size: " << stack.size() << " vs " << copy.size() << " " << (stack.size() != copy.size() ? OK : KO) << std::endl;
	std::cout << "is empty? " << stack.empty() << " vs " << copy.empty() << " " << (stack.empty() != copy.empty() ? OK : KO) << std::endl;

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing copy constructors not modyfing originals...\033[0m" << std::endl << std::endl;
	
	stack<std::string>	orig;
	orig.push("holà");
	orig.push("hellooooooooo");
	orig.push("bonjour");

	stack<std::string>	copy(orig);
	stack<std::string>	copy2 = orig;

	run(orig, copy);
	run(orig, copy2);


	stack<int>	origI;
	origI.push(42);
	origI.push(4242);
	origI.push(424242);

	stack<int>	copyI(origI);
	stack<int>	copyI2 = origI;

	run(origI, copyI);
	run(origI, copyI2);

	return 0;
}
