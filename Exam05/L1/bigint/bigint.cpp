/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:39:31 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/22 16:05:57 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "bigint.hpp"

void bigint::clean() {
	while (num.size() > 1 && num[0] == '0')
		num.erase(0, 1);
}

bigint::bigint(const std::string &s) : num(s) { clean(); }

bigint::bigint(int num) : num(std::to_string(num)) {}
		
bigint bigint::operator+(const bigint &other) const {
	std::string res = "", a = num, b = other.num;
	int i = a.size() - 1, j = b.size() - 1, carry = 0;
	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;
		if (i >= 0)
			sum += a[i--] - '0';
		if (j >= 0)
			sum += b[j--] - '0';
		res = (char)(sum % 10 + '0') + res;
		carry = sum / 10;
	}
	return bigint(res);
}
		
bigint &bigint::operator+=(const bigint &other) {
	*this = *this + other;
	return *this;
}

bigint &bigint::operator++() {
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int) {
	bigint temp = *this;
	++(*this);
	return temp;
}

bigint bigint::operator>>(int shift) const {
	if (shift >= (int)num.size())
		return bigint("0");
	return bigint(num.substr(0, num.size() - shift));
}

bigint bigint::operator>>(const bigint &shift) const {
	return bigint(*this >> shift.toInt());
}

bigint bigint::operator<<(int shift) const {
	return bigint(num + std::string(shift, '0'));
}

bigint bigint::operator<<(const bigint &shift) const {
	return bigint(*this << shift.toInt());
}

bigint &bigint::operator>>=(int shift) {
	*this = *this >> shift;
	return *this;
}

bigint &bigint::operator>>=(const bigint &shift) {
	*this = *this >> shift;
	return *this;
}
bigint &bigint::operator<<=(int shift) {
	*this = *this << shift;
	return *this;
}
bigint &bigint::operator<<=(const bigint &shift) {
	*this = *this << shift;
	return *this;
}
		
bool bigint::operator>(const bigint &other) const {
	if (num.size() != other.num.size())
		return (num.size() > other.num.size());
	return (num > other.num);
}

bool bigint::operator<(const bigint &other) const {
	return other > *this;
}

bool bigint::operator==(const bigint &other) const {
	return num == other.num;
}

bool bigint::operator!=(const bigint &other) const {
	return !(*this == other);
}

bool bigint::operator>=(const bigint &other) const {
	return (*this > other || *this == other);
}

bool bigint::operator<=(const bigint &other) const {
	return (*this < other || *this == other);
}

int bigint::toInt() const { return std::stoi(num); }
std::string bigint::getNum() const { return num; }


std::ostream &operator<<(std::ostream &os, const bigint &b) {
	return (os << b.getNum());
}
