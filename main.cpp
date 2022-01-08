/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:05:55 by bledda            #+#    #+#             */
/*   Updated: 2022/01/08 07:11:11 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "utils/type_traits.hpp"
#include "utils/utility.hpp"
#include "utils/algorithm.hpp"
#include <list>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

class foo {
	public:
		foo(void) { };
		~foo(void) { };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(int src) { this->value = src; return *this; };
		int getValue(void) const { return this->value; };
	private:
		int	value;
};

std::ostream	&operator<<(std::ostream &o, foo const &bar) {
	o << bar.getValue();
	return o;
}

// #define TESTED_TYPE int
#define TESTED_TYPE std::string

void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	printSize(vct);

	checkErase(vct, vct.erase(vct.begin() + 2));

	checkErase(vct, vct.erase(vct.begin()));
	checkErase(vct, vct.erase(vct.end() - 1));

	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

	vct.push_back("Hello");
	vct.push_back("Hi there");
	printSize(vct);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");
	printSize(vct);
	checkErase(vct, vct.erase(vct.begin(), vct.end()));

	return (0);
}
