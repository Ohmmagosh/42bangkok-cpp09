/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:18:05 by psuanpro          #+#    #+#             */
/*   Updated: 2023/06/21 01:53:42 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(const std::string &str, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream	tokenStream(str);

	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

int	main(void) {
	std::map<std::string, int>	exchange;
	std::map<std::string, int>::iterator	it;
	std::ifstream	file("data.csv");
	std::string		buff;
	std::vector<std::string> tmp;
	int			i;
	exchange["hello"] = 10;
	std::cout << std::getline(file, buff) << std::endl;
	std::cout << buff << std::endl;
	std::cout << exchange.empty() << std::endl;
	std::cout << std::endl;
	i = buff.find(',');

	tmp.push_back(buff.substr(0, i));
	tmp.push_back(buff.substr(i + 1, buff.size()));


	std::cout << tmp[0] << std::endl;
	std::cout << tmp[1] << std::endl;
	std::cout << tmp.empty() << std::endl;
	tmp.clear();
	std::cout << tmp.empty() << std::endl;

	// std::find(buff, buff.end(),)

	// for (it = exchange.begin(); it != exchange.end(); it++) {
	// 	std::cout << "key : "<< it->first << "values : " << it->second << std::endl;
	// }
	std::string str = "";
	std::vector<std::string> words = split(str, ' ');

	for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it) {
		std::cout << *it << std::endl;
	}
}
