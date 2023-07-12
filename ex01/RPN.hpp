/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:42:06 by psuanpro          #+#    #+#             */
/*   Updated: 2023/06/28 01:30:59 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <deque>
#include <string>

class Rpn
{
	public:
		Rpn(void);
		Rpn( const Rpn& cp);
		Rpn& operator=(const Rpn& cp);
		~Rpn();
		void						setAddStack(int num );
		void						getStack() const;
		int							setRmStack();
		int							calculate_mode(int x, int y, int mode);
		bool						calculate(const std::string& opt);
		void						run( const std::string& input);
		bool						isOperator( const std::string& str ) const;
		bool						isNum( const std::string& str ) const;
		bool						validateInput( const std::string& input ) const;
		void						printError( const std::string& msg, const std::string& input);
		void						printError( const std::string& msg);
		static bool					cOperator(const char& c);
		std::deque<std::string>		split(const std::string& str, const char& delim) const;
	private:
		std::stack<int>		stack;
};

#endif
