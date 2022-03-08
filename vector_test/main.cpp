/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:40:47 by bledda            #+#    #+#             */
/*   Updated: 2022/03/08 15:27:57 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"

std::ostream	&operator<<(std::ostream &o, foo const &bar) {
	o << bar.getValue();
	return o;
}

int main(void)
{
	assign();
	at_const();
	at();
	bidirect_it();
	copy_construct();
	erase();
	insert();
	insert2();
	ite_arrow();
	ite_eq_ope();
	ite();
	push_pop();
	relational_ope();
	rev_ite_construct();
	rite_arrow();
	rite_eq_ope();
	rite();
	rite2();
	size();
	swap();
	return (0);
}
