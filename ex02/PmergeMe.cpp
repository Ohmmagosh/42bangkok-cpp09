/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:43:03 by psuanpro          #+#    #+#             */
/*   Updated: 2023/07/12 17:53:25 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	// std::cout << "PmergeMe created!!" << std::endl;
}

PmergeMe::PmergeMe( const PmergeMe& cp ) {
	*this = cp;
}

PmergeMe&	PmergeMe::operator=( const PmergeMe& cp ) {
	if (this != &cp) {
		this->ls = cp.ls;
		this->resls = cp.resls;
		this->mp = cp.mp;
		this->resmp = cp.resmp;
		this->tls = cp.tls;
		this->tmp = cp.tmp;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {
	// std::cout << "PmergeMe destroy!!" << std::endl;
}

void	PmergeMe::outBefore(void) {
	std::cout << "Before:  ";
	this->printList(this->ls);
}

void	PmergeMe::outAfter(void) {
	std::cout << "After:   ";
	this->printList(this->resls);
}

void	PmergeMe::outTime(void) {
	std::cout << "Time to process a range of "  << this->resls.size() << " elements with std::list : " << std::fixed << this->tls << " us" << std::endl;
	std::cout << "Time to process a range of "  << this->resmp.size() << " elements with std::map :  " << std::fixed << this->tmp << " us" << std::endl;
}

void	PmergeMe::run( int ac, char **av ) {
	if (ac > 1) {
		this->getInput( ac - 1 , av + 1);
		this->outBefore();
		this->sortList();
		this->sortMap();
		this->outAfter();
		this->outTime();
	} else
		std::cout << "Error" << std::endl;
	return ;
}

int	PmergeMe::strToInt( const std::string& str ) {
	std::stringstream	ss(str);
	int					ret;
	if (ss >> ret) {
		throw TypeCastError();
	}
	if (ret < 0)
		throw IsNegativeNumber();
	return (ret);
}

void	PmergeMe::getInput( int ac , char **av) {
	int	tmp = 0;
	for (int i = 0; i < ac; i++) {
		tmp = atoi(av[i]);
		if (tmp < 0)
			throw IsNegativeNumber();
		this->validateInput(av[i]);
		this->ls.push_back(tmp);
		this->mp.insert(std::make_pair(i, tmp));
	}
	return ;
}

void	PmergeMe::validateInput( char *str ) {
	std::string	s(str);

	for (size_t i = 0; i < s.size(); i++) {
		if (!isdigit(s[i]))
			throw NotDigit();
	}
	return ;
}

void	PmergeMe::printList(const std::list<int> &ls) const {
	std::list<int>::const_iterator	it;

	for (it = ls.begin(); it != ls.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return ;
}


void	PmergeMe::sortList( void ) {
	clock_t	start = clock();
	this->mergeList();
	this->insertList();
	std::clock_t	end = clock();
	this->tls = double(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::moveList( std::list<int>::iterator &it, int pos) {
	for (int i = 0; i < pos; i++) {
		++it;
	}
	return;
}

int	PmergeMe::minList(const std::list<int> ls) const {
	std::list<int>::const_iterator it = ls.begin();
	int min = *it;

	it++;
	for (; it != ls.end(); it++) {
		if (*it < min)
			min = *it;
	}
	return (min);
}

void	PmergeMe::deleteList( std::list<int> &ls, int value ) {
	std::list<int>::iterator it = ls.begin();

	while (it != ls.end()) {
		if (*it == value) {
			it = ls.erase(it);
			break;
		} else {
			++it;
		}
	}
	return ;
}

int	PmergeMe::countListPartition( int size ) const {
	int ret = 0;
	int leni = size / 2;

	while (leni >= 2) {
		ret++;
		leni /= 2;
	}
	return (ret);
}

void	PmergeMe::mergeList( void ) {
	std::list<int>::iterator	left;
	std::list<int>::iterator	right;
	std::list<int>::iterator	tmpl;
	std::list<int>::iterator	tmpr;

	int count = this->countListPartition( this->ls.size() );
	left = tmpl = right = tmpr = this->ls.begin();
	this->moveList(tmpl, 1);
	this->moveList(right, (ls.size() / 2));
	this->moveList(tmpr, (ls.size() / 2) + 1);

	for (int i = 0; i < count; i++) {
		if (*left > *tmpl || *right > *tmpr) {
			if (*left > *tmpl)
				iter_swap(left, tmpl);
			if (*right > *tmpr)
				iter_swap(right, tmpr);
			this->moveList(left, 2);
			this->moveList(tmpl, 2);
			this->moveList(right, 2);
			this->moveList(tmpr, 2);
		}
	}
	return ;
}

void	PmergeMe::insertList(void) {
	int min = 0;
	while (!this->ls.empty()) {
		min = this->minList(this->ls);
		this->resls.push_back(min);
		this->deleteList(this->ls, min);
	}
}

void	PmergeMe::mergeMap(void) {
	int count = this->countListPartition(this->mp.size());
	int leni = this->mp.size() / 2;

	int j = 0;
	for (int i = 0; i < count ; i++) {
		std::map<int, int>::iterator left = this->mp.find(j);
		std::map<int, int>::iterator tmpl = this->mp.find(1 + j);
		std::map<int, int>::iterator right = this->mp.find(leni + j);
		std::map<int, int>::iterator tmpr = this->mp.find(leni + 1 + j);
		if (left->second > tmpl->second || right->second > tmpr->second) {
			if (left->second > tmpl->second)
				this->swapMap(left, tmpl);
			if (right->second > tmpr->second)
				this->swapMap(right, tmpr);
			j += 2;
		}
	}
	return ;
}

void	PmergeMe::swapMap(std::map<int, int>::iterator &it1, std::map<int, int>::iterator &it2) {
	int tmp = it1->second;

	it1->second = it2->second;
	it2->second = tmp;
}

void	PmergeMe::printMap(const std::map<int, int>& mp) const{
	std::map<int, int>::const_iterator	it = mp.begin();

	for (; it != mp.end(); it++) {
		std::cout << it->second << " ";
	}
	std::cout << std::endl;
	return ;
}

int	PmergeMe::minMap(const std::map<int, int>& mp) {
	std::map<int, int>::const_iterator it = mp.begin();
	int min = -99;

	if (min == -99) {
		for (;it != mp.end(); it++) {
			if (it->second != -99)
				break ;
		}
		min = it->second;
	}
	it = mp.begin();
	for (; it != mp.end(); it++) {
		if (it->second < min && it->second > -99)
			min = it->second;
	}
	return (min);
}

int		PmergeMe::findKeyMap(const std::map<int, int>& mp, int value) {
	std::map<int, int>::const_iterator	it = mp.begin();
	int key = -1;

	for (; it != mp.end(); it++) {
		if (it->second == value)
			break;
	}
	key = it->first;
	return (key);
}

void	PmergeMe::deleteMap(std::map<int, int> &mp, int value) {
	std::map<int, int>::iterator it = mp.find(value);
	it->second = -99;
	return ;
}

void	PmergeMe::insertMap(void) {
	int	min = 0;
	int del_key = 0;
	int size = static_cast<int>(this->mp.size());

	for (int i = 0; i < size; i++) {
		min = this->minMap(this->mp);
		del_key = findKeyMap(this->mp, min);
		this->deleteMap(this->mp, del_key);
		this->resmp.insert(std::make_pair(i, min));
	}
	return ;
}

void	PmergeMe::sortMap(void) {
	clock_t	start = clock();
	this->mergeMap();
	this->insertMap();
	clock_t	end = clock();
	this->tmp =  (double)(end - start) / CLOCKS_PER_SEC;
}
