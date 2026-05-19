/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:47:10 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/26 20:37:03 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class vect2 {
	private:
		int x;
		int y;
	public:
		vect2(int x = 0, int y = 0);
		vect2(const vect2 &other);
		vect2 &operator=(const vect2 &other);
		
		vect2 &operator++();
		vect2 operator++(int);
		vect2 &operator--();
		vect2 operator--(int);
		
		vect2 operator+(const vect2 &other)const;
		vect2 &operator+=(const vect2 &other);
		
		vect2 operator-(const vect2 &other)const;
		vect2 &operator-=(const vect2 &other);
		
		vect2 operator*(int scalar)const;
		vect2 &operator*=(int scalar);
		
		vect2 operator-()const;
		
		bool operator==(const vect2 &other)const;
		bool operator!=(const vect2 &other)const;
		
		int operator[](int index)const;
		int &operator[](int index);
};

vect2 operator*(int scalar, const vect2 &other);

std::ostream &operator<<(std::ostream &s, const vect2 &v);
