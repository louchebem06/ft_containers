/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:05:55 by bledda            #+#    #+#             */
/*   Updated: 2022/01/18 14:55:23 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "utils/type_traits.hpp"
#include "utils/utility.hpp"
#include "utils/algorithm.hpp"
#include "utils/functional.hpp"
#include <list>
#include "stack.hpp"
#include <stack>
#include <map>
//#include "map.hpp"


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

#define TESTED_TYPE foo

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(vct.rbegin());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite(vct.rend());

	for (int i = 1; it != ite; ++i)
		*it++ = i;
	printSize(vct, 1);

	// it = vct.rbegin();
	// ite = vct.rbegin();

	// std::cout << *(++ite) << std::endl;
	// std::cout << *(ite++) << std::endl;
	// std::cout << *ite++ << std::endl;
	// std::cout << *++ite << std::endl;

	// it->m();
	// ite->m();

	// std::cout << *(++it) << std::endl;
	// std::cout << *(it++) << std::endl;
	// std::cout << *it++ << std::endl;
	// std::cout << *++it << std::endl;

	// std::cout << *(--ite) << std::endl;
	// std::cout << *(ite--) << std::endl;
	// std::cout << *--ite << std::endl;
	// std::cout << *ite-- << std::endl;

	// (*it).m();
	// (*ite).m();

	// std::cout << *(--it) << std::endl;
	// std::cout << *(it--) << std::endl;
	// std::cout << *it-- << std::endl;
	// std::cout << *--it << std::endl;

	// return (0);
}

