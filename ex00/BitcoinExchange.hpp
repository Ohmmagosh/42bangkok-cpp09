/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:18:11 by psuanpro          #+#    #+#             */
/*   Updated: 2023/06/22 17:46:12 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>
# include <map>
# include <string>

struct	Date {
	int	year;
	int	month;
	int	day;
};
class	 BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& cp );
		BitcoinExchange& operator=( const BitcoinExchange& cp );
		~BitcoinExchange();

		void						setExchange( const std::string& key, double value );
		void						setInput( const std::string& key, double value );
		void						getAllExchange( void );
		void						getAllInput( void );
		void						setCsvData( void );
		bool						printError( const std::string& msg );
		bool						printError( const std::string& msg, const std::string& date );
		bool						leabYear( int year );
		bool						thirtyOneMonth( int month);
		void						run(const std::string& input_file);
		bool						validateData(const std::vector<std::string>& tvec);
		bool						validateDate(const std::string& date);
		bool						validatePrice(const std::string& price);
		void						compare(const std::vector<std::string>& tvec);
		bool						validateInput(const std::string& date, double price);
		bool						validInputPrice( const std::string& price );
		void						printCompare(const std::string& date, double price, double rate);
		std::string					trim( const std::string& str );
		std::vector<std::string>	split(const std::string& str, char delim);

	private:
		std::multimap<std::string, double>	_exchange;
		std::multimap<std::string, double>	_input;
};

#endif
