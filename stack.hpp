/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:12:54 by bledda            #+#    #+#             */
/*   Updated: 2022/01/11 17:44:34 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"
#include <vector>

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		public:
			typedef T				value_type;
			typedef Container		container_type;
			typedef unsigned int	size_type;
		protected:
			container_type _container;
		public:
			explicit stack (const container_type& ctnr = container_type()) {
				this->_container = ctnr;
			};
			
			bool empty() const { return (this->_container.empty()); };
			size_type size() const { return (this->_container.size()); };
			
			value_type& top() { return (this->_container.back()); };
			const value_type& top() const { return (this->_container.back()); };

			void push (const value_type& val) { this->_container.push_back(val); };

			void pop () { this->_container.pop_back(); };

			template <class T_, class Container_>
			friend bool operator==
			(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);

			template <class T_, class Container_>
			friend bool operator!=
			(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);

			template <class T_, class Container_>
			friend bool operator<
			(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);

			template <class T_, class Container_>
			friend bool operator<=
				(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);

			template <class T_, class Container_>
			friend bool operator>
				(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);

			template <class T_, class Container_>
			friend bool operator>=
				(const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);
	};

	template <class T_, class Container_>
	bool operator== (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) {
		return (lhs._container == rhs._container);
	};

	template <class T_, class Container_>
	bool operator!= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) {
		return (lhs._container != rhs._container);
	};

	template <class T_, class Container_>
	bool operator<  (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) {
		return (lhs._container < rhs._container);
	};

	template <class T_, class Container_>
	bool operator<= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) {
		return (lhs._container <= rhs._container);
	};

	template <class T_, class Container_>
	bool operator>  (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) {
		return (lhs._container > rhs._container);
	};

	template <class T_, class Container_>
	bool operator>= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) {
		return (lhs._container >= rhs._container);
	};
}
