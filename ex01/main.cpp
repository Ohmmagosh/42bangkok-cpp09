/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:41:56 by psuanpro          #+#    #+#             */
/*   Updated: 2023/06/23 00:48:47 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	Rpn		rpn;

	if (ac == 2) {
		rpn.run(av[1]);
	} else
		std::cout << "Error : bad input" << std::endl;
}
