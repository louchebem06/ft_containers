/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cont.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:25:12 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/25 14:17:49 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONT_HPP
# define CONT_HPP

# include "vector.hpp"

# include <vector>
# include <string>
# include <iostream>
# include <unistd.h>

# define STR	"std::string"
# define INT	"int"
# define CHAR	"char"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CLR	"\033[0m"

using CONTAINER::vector;

template< class T >
void	display( T vec, std::string s ) {
			
	std::cout << "vector<" << s << "> content: " ;

	typename T::iterator	it, ite = vec.end();
	for (it = vec.begin(); it != ite; it++)
		std::cout << "[" << *it << "] ";

	std::cout << std::endl << std::endl;
}

template< class T >
void	checkSize( T vec, std::string s ) {

	std::cout << "Testing size, capacity, max_size" << std::endl;
	std::cout << "vector<" << s << "> size: " << vec.size() << std::endl;
	std::cout << "vector<" << s << "> capacity: " << (vec.capacity() >= vec.size() ? "\033[32m[ OK ]\033[0m" : "\033[31m[ KO ]\033[0m") << std::endl;
	std::cout << "vector<" << s << "> max_size: " << vec.max_size() << std::endl;
	std::cout << std::boolalpha << "is empty ? " << vec.empty() << std::endl;

	std::cout << std::endl;
}

template< class T >
void	checkSize( T vec, std::string s, bool B ) {

	(void)B;

	std::cout << "Testing size" << std::endl;
	std::cout << "vector<" << s << "> size: " << vec.size() << std::endl;
	std::cout << std::boolalpha << "is empty ? " << vec.empty() << std::endl;

	std::cout << std::endl;
}

template< class T, class A >
T 	fillVec( T vec, A array, size_t size ) {
	
	for (size_t i = 0; i < size; i++)
		vec.push_back(array[i]);
	return vec;
}

class	Cont {

	public:
		Cont( void ): vs(), vs2(42), vs3(10, "hello"), vi(), vi2(42), vi3(10, 42), vc(), vc2(42), vc3(10, '*') {}
		~Cont( void ){}
	
		vector<std::string>	vs;
		vector<std::string>	vs2;
		vector<std::string>	vs3;
		
		vector<int>			vi;
		vector<int>			vi2;
		vector<int>			vi3;
		
		vector<char>		vc;
		vector<char>		vc2;
		vector<char>		vc3;
};

const std::string	as[] = {"kkkkkkkkkkk", "likjkufgkhf", "08768LIJHLKlkjhlk", "P%MLKHJGCVB", "khgkjgkj"};
const int			ai[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const char			ac[] = {'a', 'b', 'c', 'd', 'e'};

const size_t	sizeS = 5;
const size_t	sizeI = 10;
const size_t	sizeC = 5;

#endif
