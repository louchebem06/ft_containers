/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:12:54 by bledda            #+#    #+#             */
/*   Updated: 2022/02/26 02:49:29 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"

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
			container_type c;
		public:
			explicit stack (const container_type& ctnr = container_type()) {
				if (!ctnr.empty())
					this->c = ctnr;
			};
			
			bool empty() const { return (this->c.empty()); };
			size_type size() const { return (this->c.size()); };
			
			value_type& top() { return (this->c.back()); };
			const value_type& top() const { return (this->c.back()); };

			void push (const value_type& val) { this->c.push_back(val); };

			void pop () { this->c.pop_back(); };

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
		return (lhs.c == rhs.c);
	};

	template <class T_, class Container_>
	bool operator!= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) {
		return (lhs.c != rhs.c);
	};

	template <class T_, class Container_>
	bool operator<  (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) {
		return (lhs.c < rhs.c);
	};

	template <class T_, class Container_>
	bool operator<= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) {
		return (lhs.c <= rhs.c);
	};

	template <class T_, class Container_>
	bool operator>  (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) {
		return (lhs.c > rhs.c);
	};

	template <class T_, class Container_>
	bool operator>= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) {
		return (lhs.c >= rhs.c);
	};
}
