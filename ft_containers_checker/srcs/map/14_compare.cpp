/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_compare.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:07:15 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/31 20:27:16 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

struct ModuloComp {

	bool operator()(const int lhs, const int rhs) const { return (lhs % 97) < (rhs % 97); }
};

template< class T >
struct Comp {

	bool operator()(T lhs, T rhs) const { return (lhs < rhs); }
};

template< class T, class It >
void	compare( T map, It it, It it2) {

	bool	keyRes = map.key_comp()(it->first, it2->first);
	bool	valueRes = map.value_comp()(*it, *it2);

	std::cout << "key [" << it->first << "] vs [" << it2->first << "] ==> " << keyRes << " | " << valueRes << std::endl;
}

template< class T >
void	run( T map ) {

	std::cout << std::boolalpha;

	for (typename T::const_iterator it = map.begin(); it != map.end(); it++)
		for (typename T::const_iterator it2 = map.begin(); it2 != map.end(); it2++)
			compare(map, it, it2);
}

template< class T >
void	run2( T map ) {

	ft::map<int, char, ModuloComp>::key_compare	comp_func = map.key_comp();

	for (typename T::iterator it = map.begin(); it != map.end(); it++) {

        bool	before = comp_func(it->first, 100);
        bool	after = comp_func(100, it->first);

        std::cout << '[' << it->first << ':' << it->second;

        if (!before && !after)
            std::cout << "] equivalent to key 100\n";
        else if (before)
            std::cout << "] goes before key 100\n";
        else if (after)
            std::cout << "] goes after key 100\n";
    }
}

template< class T, class T2, class T3 >
void	checkLower( T map, T2 content, T3 cmp ) {

	for (typename T::const_iterator it = map.begin(); it != map.end(); it++) {

        bool	lower = cmp(it->second, content);

        std::cout << "value of pair [" << it->first << ":" << it->second;

        if (lower)
            std::cout << "] is lower than value " << content << std::endl;
        else
            std::cout << "] is greater or equal to value " << content << std::endl;
    }
}

int		main( void ) {

    ft::map<int, char>	map;
    map[1] = 'a';
	map[2] = 'b';
	map[3] = 'c';
	map[4] = 'd';
	map[5] = 'e';
	run(map);

	std::cout << "------------------------" << std::endl;

	ft::map<int, char, ModuloComp> map2;
    map2[1] = 'a';
	map2[2] = 'b';
	map2[3] = 'c';
	map2[4] = 'd';
	map2[5] = 'e';
	run2(map2);

	std::cout << "------------------------" << std::endl;

	ft::map<int, char, Comp<char> >	map3;
    map3[1] = 'a';
	map3[2] = 'b';
	map3[3] = 'c';
	map3[4] = 'd';
	map3[5] = 'e';

	ft::map<int, char, Comp<char> >::key_compare	compChar = map3.key_comp();
	checkLower(map3, 'c', compChar);

	std::cout << "------------------------" << std::endl;

	ft::map<char, int, Comp<int> >	map4;
    map4['z'] = 39;
	map4['y'] = 40;
	map4['x'] = 41;
	map4['w'] = 42;
	map4['v'] = 43;
	map4['u'] = 44;
	
	ft::map<char, int, Comp<int> >::key_compare		compInt = map4.key_comp();
	checkLower(map4, 42, compInt);

	return 0;
}
