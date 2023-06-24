/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:42:03 by psuanpro          #+#    #+#             */
/*   Updated: 2023/06/24 21:38:10 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn(void) {

}

Rpn::Rpn( const Rpn& cp) {
	*this = cp;
}

Rpn::~Rpn() {

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
	for (unsigned int i = 0; i < str.size(); i++) {
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return ( true );
}

bool	Rpn::cOperator(const char& c) {
	return (c != '+' || c != '-' || c != '*' || c != '/');
}

bool	Rpn::validateInput( const std::string& input ) const {
	for (unsigned int i = 0; i< input.size(); i++) {
		if ((input[i] < '0' || input[i] > '9') && (cOperator(input[i]) == false)) {
			return (false);
		}
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

int	Rpn::calculate_mode(int x, int y, int mode) {
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

bool	Rpn::calculate(const std::string& opt) {
	int	res = 0;
	int	a = 0;
	int b = 0;

	a = this->setRmStack();
	b = this->setRmStack();
	if (opt.compare("+") == 0) {
		res = this->calculate_mode(b, a , 1);
	} else if (opt.compare("-") == 0) {
		res = this->calculate_mode(b, a, 2);
	} else if (opt.compare("*") == 0) {
		res = this->calculate_mode(b, a ,3);
	} else if (opt.compare("/") == 0) {
		if (b == 0)
			return (false);
		res = this->calculate_mode(b, a, 4);
	}
	this->setAddStack(res);
	return (true);
}

void	Rpn::getStack() const {
	std::stack<int> cp = this->stack;
	while (!cp.empty()){
		std::cout << cp.top() << std::endl;
		cp.pop();
	}
	// std::cout << this->stack.top() << std::endl;
}

void	Rpn::run( const std::string& input ) {
	std::deque<std::string>::iterator	it;

	if (this->validateInput(input)) {
		std::deque<std::string> sp = this->split(input, ' ');
		for (it = sp.begin(); it != sp.end(); it++) {
			if (this->isNum(*it)) {
				this->setAddStack(std::stoi(*it));
			}else if (this->isOperator(*it)) {
				if (this->stack.size() == 0 || this->stack.size() == 1) {
					this->printError("Stack is empty!!");
					return ;
				}
				if (this->calculate(*it) == false) {
					this->printError("bad input ", input);
					return ;
				}
			}
		}
	} else
		return (this->printError("bad input", input));
	this->getStack();
	return ;
}

