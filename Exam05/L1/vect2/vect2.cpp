/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:47:15 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/26 20:36:55 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2(int x, int y) : x(x), y(y) {}

vect2::vect2(const vect2 &other) : x(other.x), y (other.y) {}

vect2 &vect2::operator=(const vect2 &other) {
	if (*this != other) {
		x = other.x;
		y = other.y;
	}
	return *this;
}
		
vect2 &vect2::operator++() {
	++x;
	++y;
	return *this;
}

vect2 vect2::operator++(int) {
	vect2 temp = *this;
	++x;
	++y;
	return temp;
}

vect2 &vect2::operator--() {
	--x;
	--y;
	return *this;
}

vect2 vect2::operator--(int) {
	vect2 temp = *this;
	--x;
	--y;
	return temp;
}

vect2 vect2::operator+(const vect2 &other)const {
	vect2 temp = *this;
	temp.x += other.x;
	temp.y += other.y;
	return temp;
}

vect2 &vect2::operator+=(const vect2 &other) {
	x += other.x;
	y += other.y;
	return *this;
}

vect2 vect2::operator-(const vect2 &other)const {
	vect2 temp = *this;
	temp.x -= other.x;
	temp.y -= other.y;
	return temp;
}
vect2 &vect2::operator-=(const vect2 &other) {
	x -= other.x;
	y -= other.y;
	return *this;
}
		
vect2 vect2::operator*(int scalar)const {
	vect2 temp = *this;
	temp.x *= scalar;
	temp.y *= scalar;
	return temp;
}
vect2 &vect2::operator*=(int scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}
		
vect2 vect2::operator-()const {
	vect2 temp = *this;
	temp.x = -temp.x;
	temp.y = -temp.y;
	return temp;
}
		
bool vect2::operator==(const vect2 &other)const {
	return (x == other.x && y == other.y);
}
bool vect2::operator!=(const vect2 &other)const {
	return (x != other.x || y != other.y);
}
	
int vect2::operator[](int index)const { return index == 0 ? x : y; }

int &vect2::operator[](int index) { return index == 0 ? x : y; }


vect2 operator*(int scalar, const vect2 &other) {
	vect2 temp = other;
	temp *= scalar;
	return temp;
}

std::ostream &operator<<(std::ostream &s, const vect2 &v) {
	return (s << "{" << v[0] << ", " << v[1] << "}" << std::endl);
}
