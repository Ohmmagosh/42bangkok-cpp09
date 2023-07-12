/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:43:05 by psuanpro          #+#    #+#             */
/*   Updated: 2023/07/12 17:29:56 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <queue>
# include <list>
# include <ctime>
# include <cstdlib>
# include <iterator>
# include <exception>
# include <sstream>
# include <unistd.h>
# include <exception>
# include <map>
# include <iomanip>


class PmergeMe {
	public:
		PmergeMe();
		PmergeMe( const PmergeMe& cp );
		PmergeMe& operator=( const PmergeMe& cp );
		~PmergeMe();

		int		strToInt( const std::string& str );
		int		minList(const std::list<int> ls) const;
		int		countListPartition(int size) const;
		int		minMap(const std::map<int, int>& mp);
		int		findKeyMap(const std::map<int, int>& mp, int value);
		void	setTmp( int num );
		void	run( int ac ,char **av );
		void	getInput( int ac, char **av );
		void	validateInput(char *str);
		void	sortQueue(void);
		void	sortList(void);
		void	sortMap(void);
		void	printList( const std::list<int> &ls ) const;
		void	printMap( const std::map<int, int>& mp ) const;
		void	partitionSort(void);
		void	mergeList(void);
		void	mergeMap(void);
		void	moveList(std::list<int>::iterator &it, int pos);
		void	deleteList( std::list<int> &ls, int value );
		void	insertList(void);
		void	insertMap(void);
		void	swapMap(std::map<int, int>::iterator &it1, std::map<int, int>::iterator &it2);
		void	deleteMap(std::map<int, int> &mp, int value);
		void	outBefore(void);
		void	outAfter();
		void	outTime();

	class ArgumentError:public std::exception {
		const char * what () const throw () {
			return "Argument error!!";
		};
	};
	class TypeCastError:public std::exception {
		const char * what () const throw () {
			return "type cast Error!!";
		};
	};
	class IsNegativeNumber:public std::exception {
		const char * what () const throw () {
			return "is negative number!!";
		};
	};
	class NotDigit:public std::exception {
		const char * what () const throw () {
			return "Not a number";
		};
	};

	private:
		std::list<int>		resls;
		std::list<int>		ls;
		std::map<int, int>	mp;
		std::map<int, int>	resmp;
		double				tls;
		double				tmp;

};

#endif
