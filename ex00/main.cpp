/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:18:05 by psuanpro          #+#    #+#             */
/*   Updated: 2023/06/22 17:41:56 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	BitcoinExchange	exchange;
	if (ac == 2) {
		exchange.run(av[1]);
	}else {
		std::cout << "Error: could not open file." << std::endl;
	}
	return (0);
}
// {
// 	std::multimap<std::string, int>		map;

// 	map.insert(std::pair<std::string, int>("2009-01-02", 1));
// 	map.insert(std::pair<std::string, int>("2009-01-03", 2));
// 	map.insert(std::pair<std::string, int>("2009-01-05", 4));

// 	std::multimap<std::string, int>::iterator it;

// 	for (it = map.begin(); it != map.end(); it++) {
// 		std::cout << "key : " << it->first << "value : " << it->second << std::endl;
// 	}

// 	std::cout << std::endl;
// 	it = map.lower_bound("2008-12-01");
// 	if (it == map.end())
// 		it--;
// 	std::cout << "key : " << it->first << " value : " << it->second << std::endl;
// }
