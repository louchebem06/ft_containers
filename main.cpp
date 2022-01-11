/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:05:55 by bledda            #+#    #+#             */
/*   Updated: 2022/01/11 15:58:57 by bledda           ###   ########.fr       */
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
#include "stack.hpp"
#include <stack>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

template <typename T_STACK>
void	printSize(T_STACK &stck, bool print_content = 1)
{
	std::cout << "size: " << stck.size() << std::endl;
	if (print_content)
	{
		std::cout << std::endl << "Content was:" << std::endl;
		while (stck.size() != 0) {
			std::cout << "- " << stck.top() << std::endl;
			stck.pop();
		}
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}

#define TESTED_TYPE foo<int>
#define t_stack_ TESTED_NAMESPACE::stack<TESTED_TYPE>
typedef t_stack_::container_type container_type;

void	prepost_incdec(TESTED_NAMESPACE::vector<TESTED_TYPE> &vct)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_tmp;

	std::cout << "Pre inc" << std::endl;
	it_tmp = ++it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Pre dec" << std::endl;
	it_tmp = --it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post inc" << std::endl;
	it_tmp = it++;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post dec" << std::endl;
	it_tmp = it--;
	std::cout << *it_tmp << " | " << *it << std::endl;
	std::cout << "###############################################" << std::endl;
}

int		main(void)
{
	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_stack_		stck(ctnr);

	std::cout << "empty: " << stck.empty() << std::endl;
	std::cout << "size: " << stck.size() << std::endl;

	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.push(4);
	stck.push(5);
	stck.push(6);

	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << stck.empty() << std::endl;
	printSize(stck);

	return (0);
}