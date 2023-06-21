/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:18:13 by psuanpro          #+#    #+#             */
/*   Updated: 2023/06/22 02:48:00 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
	this->setCsvData();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& cp ) {
	*this = cp;
}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& cp ) {
	if (this != &cp) {

	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
	std::cout << "BitcoinExchange Destroy!!" << std::endl;
}

void	BitcoinExchange::setExchange( const std::string& key, double value) {
	this->_exchange.insert(std::pair<std::string, double>(key, value));
}

void	BitcoinExchange::getAllExchange( void ) {
	if (this->_exchange.empty()){
		std::cout << "Exchange is empty!!" << std::endl;
		return ;
	}
	for (std::multimap<std::string,double>::iterator it = this->_exchange.begin(); it != this->_exchange.end(); it++) {
		std::cout << "Date : " << it->first << " Price : " << it->second << std::endl;
	}
	return ;
}

std::vector<std::string>	BitcoinExchange::split( const std::string& str, char delim) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(str);

	while (std::getline(tokenStream, token, delim)) {
		tokens.push_back(token);
	}
	return tokens;
}

bool	BitcoinExchange::validateDate( const std::string& date ) {
	Date						ds;
	std::vector<std::string>	sdate;

	if(date.compare("date") == 0) {
		return (false);
	}
	sdate = this->split(date, '-');
	if (sdate.size() != 3)
		return (false);
	ds.year = std::stoi(sdate[0]);
	ds.month = std::stoi(sdate[1]);
	ds.day = std::stoi(sdate[2]);
	if (ds.year < 0 || ds.day < 0 || ds.month < 0)
		return (false);
	if (this->leabYear(ds.year) && ds.month == 2 && ds.day > 29)
		return (false);
	if (this->thirtyOneMonth(ds.month) && ds.day > 31)
			return (false);
	else {
		if (ds.day > 31)
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::validatePrice( const std::string& price ) {
	double		iprice;

	if (price.compare("year") == 0)
		return (false);
	iprice = std::stod(price);
	if (iprice < 0)
		return (false);
	return (true);
}

bool	BitcoinExchange::validateData( const std::vector<std::string>& tvec ) {
	if (!this->validateDate(tvec[0]) || !this->validatePrice(tvec[1]))
		return (false);
	return true;
}

void	BitcoinExchange::setCsvData( void ) {
	std::string					tmp;
	std::vector<std::string>	tvec;
	std::ifstream				fd;

	fd.open("data.csv");
	if (!fd.is_open())
		return ;
	while(std::getline(fd, tmp)) {
		tvec = this->split(tmp, ',');
		if (this->validateData(tvec))
			this->setExchange(tvec[0], std::stod(tvec[1]));
		tmp.clear();
		tvec.clear();
	}
	return ;
}

bool	BitcoinExchange::leabYear( int year ) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if ( year % 400 == 0) {
				return (true);
			}else {
				return (false);
			}
		} else {
			return (true);
		}
	} else {
		return (false);
	}
}

bool	BitcoinExchange::thirtyOneMonth( int month ) {
	switch (month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return (true);
		default:
			return (false);
	}
}

bool	BitcoinExchange::printError( const std::string& msg ) {
	std::cout << "Error : " << msg << std::endl;
	return (false);
}

void	BitcoinExchange::setInput( const std::string& key, double value ) {
	this->_input.insert(std::pair<std::string, double>(key, value));
}

void	BitcoinExchange::run(const std::string& input_file) {
	std::ifstream		fd(input_file);
	std::string			tmp;
	std::vector<std::string>	tvec;

	if (!fd.is_open()){
		this->printError("could not open file.");
		return ;
	}
	while(std::getline(fd, tmp)){
		tvec = this->split(tmp, '|');
		std::cout << tmp << std::endl;
		st::cout << "[0] : " << tvec[0]
		tmp.clear();
	}
	return ;
}

std::string	BitcoinExchange::trim( const std::string& str ) {
	std::string ret;
	int en = str.size() - 1;
	int len = 0;
	int st = 0;

	while (str[st] != std::string::npos) {
		if (std::isspace(str[st]))
			st++;
		else
			break;
	}
	while (en < 0) {
		if (std::isspace(str[en])) {
			len++;
			en--;
		}
		else
			break;
	}
	ret = str.substr(st, str.size() - st - len);
	return (ret);
}

// void	BitcoinExchange::compare( const std::string& date, double price ) {
// 	std::string	tdate;
// 	double		tprice;


// }
