/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:19:47 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/27 12:33:50 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &other) {
	if (this != &other)
		array_bag::operator=(other);
	return *this;
}

bool searchable_array_bag::has(int value) const {
	for (int i = 0; i < size; ++i) {
		if (data[i] == value)
			return true;
	}
	return false;
}
