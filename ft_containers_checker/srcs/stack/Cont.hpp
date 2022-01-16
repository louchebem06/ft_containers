/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cont.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:25:12 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/27 19:49:32 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONT_HPP
# define CONT_HPP

# include "stack.hpp"
# include "vector.hpp"

# include <stack>
# include <vector>
# include <string>
# include <iostream>
# include <unistd.h>

# define STR	"std::string"
# define INT	"int"
# define CHAR	"char"
# define KO		"[ \033[31mKO\033[0m ]"
# define OK		"[ \033[32mOK\033[0m ]"

using CONTAINER::vector;
using CONTAINER::stack;

template< class T >
void	checkSize( T stack, std::string s ) {

	std::cout << "[+] Testing size, empty" << std::endl;
	std::cout << "stack<" << s << "> size: " << stack.size() << std::endl;
	std::cout << std::boolalpha << "is empty ? " << stack.empty() << std::endl;

	std::cout << std::endl;
}

const std::string	as[] = {"kkkkkkkkkkk", "likjkufgkhf", "08768LIJHLKlkjhlk", "P%MLKHJGCVB", "khgkjgkj"};
const int			ai[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const char			ac[] = {'a', 'b', 'c', 'd', 'e'};

const size_t	sizeS = 5;
const size_t	sizeI = 10;
const size_t	sizeC = 5;


stack<int>	si;

vector<int>	vi2(5);
stack<int, vector<int> >	si2(vi2);

vector<int>	vi3(3, 42);
stack<int, vector<int> >	si3(vi3);


stack<std::string>	ss;

vector<std::string>	vs2(6);
stack<std::string, vector<std::string> >	ss2(vs2);

vector<std::string>	vs3(3, "Hello");
stack<std::string, vector<std::string> >	ss3(vs3);


stack<char>	sc;

vector<char>	vc2(7);
stack<char, vector<char> >	sc2(vc2);

vector<char>	vc3(3, '*');
stack<char, vector<char> >	sc3(vc3);

#endif
