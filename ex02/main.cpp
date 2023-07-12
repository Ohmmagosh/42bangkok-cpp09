/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:42:33 by psuanpro          #+#    #+#             */
/*   Updated: 2023/07/12 15:19:19 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	try {
		PmergeMe	pm;
		pm.run(ac, av);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
