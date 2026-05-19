/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:19:21 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/22 14:40:13 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class bigint {
	private:
		std::string num;
		void clean();
	public:
		bigint(const std::string &s = "0");
		bigint(int num);
		
		bigint operator+(const bigint &other) const;
		bigint &operator+=(const bigint &other);
		bigint &operator++();
		bigint operator++(int);

		bigint operator>>(int shift) const;
		bigint operator>>(const bigint &shift) const;
		bigint operator<<(int shift) const;
		bigint operator<<(const bigint &shift) const;	
		bigint &operator>>=(int shift);
		bigint &operator>>=(const bigint &shift);
		bigint &operator<<=(int shift);
		bigint &operator<<=(const bigint &shift);
		
		bool operator>(const bigint &other) const;
		bool operator<(const bigint &other) const;
		bool operator==(const bigint &other) const;
		bool operator!=(const bigint &other) const;
		bool operator>=(const bigint &other) const;
		bool operator<=(const bigint &other) const;

		int toInt() const;
		std::string getNum() const;
};

std::ostream &operator<<(std::ostream &os, const bigint &b);
