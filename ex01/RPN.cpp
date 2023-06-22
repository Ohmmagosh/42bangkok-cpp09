/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:42:03 by psuanpro          #+#    #+#             */
/*   Updated: 2023/06/23 00:59:07 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn(void) {
	std::cout << "Rpn created!!" << std::endl;
}

Rpn::Rpn( const Rpn& cp) {
	*this = cp;
}

Rpn::~Rpn() {
	std::cout << "RPN destroy!!" << std::endl;
}

Rpn&	Rpn::operator=( const Rpn& cp ) {
	if (this != &cp) {
		this->stack = cp.stack;
	}
	return (*this);
}


bool	Rpn::isOperator( const std::string& str ) const {
	return ((str.compare("+") == 0) || (str.compare("-") == 0) || (str.compare("*") == 0) || (str.compare("/") == 0));
}

bool	Rpn::isNum( const std::string& str ) const {
	for (unsigned int i = 0; i< str.size(); i++) {
		if (str[i] < 0 && str[i] > 9)
			return (false);
	}
	return ( true );
}

bool	Rpn::validateInput( const std::string& input ) const {
	for (unsigned int i = 0; i< input.size(); i++) {
		if (std::isalpha(input[i]))
			return (false);
	}
	return (true);
}

std::deque<std::string>	Rpn::split( const std::string& str , const char& delim) {
	std::deque<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(str);

	while (std::getline(tokenStream, token, delim)) {
		tokens.push_back(token);
	}
	return tokens;
}

void	Rpn::setAddStack(int num) {
	this->stack.push(num);
}

int	Rpn::setRmStack() {
	int ret = this->stack.top();
	this->stack.pop();
	return (ret);
}

int	Rpn::calculate(int x, int y, int mode) {
	switch (mode)
	{
		case 1:
			return (x + y);
		case 2:
			return (x - y);
		case 3:
			return (x * y);
		case 4:
			return (x / y);
		default:
			break;
	}
	return (x + y);
}

void	Rpn::printError(const std::string& msg, const std::string& input) {
	std::cout << "ERROR : " << msg << " : " << input << std::endl;
}

void	Rpn::printError(const std::string& msg) {
	std::cout << "ERROR : " << msg << std::endl;
}

void	Rpn::run( const std::string& input ) {
	std::deque<std::string>::iterator	it;
	int									result = 0;
	int									x = 0;
	int									y = 0;

	if (this->validateInput(input)) {
		std::deque<std::string> sp = this->split(input, ' ');
		for (it = sp.begin(); it != sp.end(); it++) {
			if (this->isNum(it)) {
				this->setAddStack(std::stoi(it));
			}else if (this->isOperator(it)) {
				x = this->setRmStack();
				y = this->setRmStack();
				if (this->stack.size() >= 2) {
					if (it->compare("+") == 0)
						result = this->calculate(x, y, 1);
					else if (it->compare("-") == 0)
						result = this->calculate(x, y, 2);
					else if (it->compare("*") == 0)
						result = this->calculate(x, y, 3);
					else if (it->compare("/") == 0) {
						if ( y == 0 )
							return (this->printError("can not divide by zero"));
						result = this->calculate(x, y, 4);
					}
				} else
					return (this->printError("stack"));
			}
		}
	} else
		return (this->printError("bad input", input));
	return ;
}

