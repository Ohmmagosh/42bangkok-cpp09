/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:18:11 by psuanpro          #+#    #+#             */
/*   Updated: 2023/06/21 01:55:39 by psuanpro         ###   ########.fr       */
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

class	 BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& cp );
		BitcoinExchange& operator=( const BitcoinExchange& cp );
		~BitcoinExchange();

		void		setFilePath( const std::string& file_path );
		std::string	getFilePath( void ) ;
		void		setExchange( const std::string& key, double value );
		void		getAllExchange( void );
		std::vector<std::string>	split(const std::string& str, char delim);
		void		getCsvData( void );
		bool		validateData( const std::vector<std::string>& data );
		bool		validateData( const std::string& date );
		bool		validateData( double price );
		bool		printError( const std::string& msg );
	private:
		std::string						_file_path;
		std::map<std::string, double>	_exchange;
		std::ifstream					_fd;

};

#endif
