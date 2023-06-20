/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:18:13 by psuanpro          #+#    #+#             */
/*   Updated: 2023/06/21 01:55:26 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
	std::cout << "BitcoinExchange Created!!" << std::endl;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& cp ) {
	*this = cp;
}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& cp ) {
	if (this != &cp) {
		this->_file_path = cp._file_path;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
	std::cout << "BitcoinExchange Destroy!!" << std::endl;
}

void	BitcoinExchange::setFilePath( const std::string& file_name) {
	this->_file_path = file_name;
	return ;
}

std::string	BitcoinExchange::getFilePath( void ) {
	return (this->_file_path);
}

void	BitcoinExchange::setExchange( const std::string& key, double value) {
	this->_exchange[key] = value;
}

void	BitcoinExchange::getAllExchange( void ) {
	std::map<std::string,double>::iterator	it = this->_exchange.begin();

	if (this->_exchange.empty())
		std::cout << "Exchange is empty!!" << std::endl;
		return ;

	for (it ;it != this->_exchange.end(); it++) {
		std::cout << "Date : " << it->first << "Price : " << it->second << std::endl;
	}
}

std::vector<std::string>	BitcoinExchange::split( const std::string& str, char delim) {
	// std::vector<std::string>	ret;
	// int							i;
	// int							len;

	// if (str.find(delim) != std::string::npos)
	// 	return (ret);
	// len = std::count(str.begin(), str.end(), delim);
	// i = str.find(delim);
	// ret.push_back(str.substr(0, i));
	// ret.push_back(str.substr(i + 1, str.size()));
	// if (ret.empty())
	// 	return (ret);
	// return (ret);
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(str);

	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

void	BitcoinExchange::getCsvData( void ) {
	std::string					tmp;
	std::vector<std::string>	tvec;

	this->_fd.open(this->_file_path);
	if (!this->_fd.is_open())
		return ;
	while (std::getline(this->_fd, tmp)) {
		tvec = this->split(tmp, ',');
		if (this->validateData( tvec )) {
			this->setExchange(tvec[0], std::stod(tvec[1]));
			tvec.clear();
		}
	}
	return ;
}

bool	BitcoinExchange::validateData( const std::vector<std::string>& data) {
	if (data.empty()) {
		return (this->printError("split"));
	} else if (this->validateData(data[0])) {
		return (this->printError("Date"));
	} else if (this->validateData(std::stod(data[1])))
		return (this->printError("Price"));
	else
		return (true);
}

bool	BitcoinExchange::validateData( const std::string& date ) {
	std::vector<string>		tmp;


}

bool	BitcoinExchange::validateData( double price ) {
	if (price < 0)
		return this->printError("price");
	return (true);
}

bool	BitcoinExchange::printError( const std::string& msg ) {
	std::cout << "Error : " << msg << std::endl;
	return (false);
}
