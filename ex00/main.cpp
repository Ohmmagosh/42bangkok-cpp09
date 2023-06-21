/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:18:05 by psuanpro          #+#    #+#             */
/*   Updated: 2023/06/22 02:48:43 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
// #include <iostream>
// #include <string>
// #include <vector>

int	main(int ac, char **av) {
	BitcoinExchange	exchange;
	if (ac == 2) {
		exchange.run(av[1]);
	}else {
		std::cout << "Error: could not open file." << std::endl;
	}
	return (0);
}
