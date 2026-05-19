/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:20:14 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/27 12:52:44 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "searchable_bag.hpp"

class set {
private:
	searchable_bag &bag;
public:
	set(searchable_bag &bag) : bag(bag) {}

	bool has(int value);
	void insert(int value);
	void insert(int *arr, int size);
	void print() const;
	void clear();
	const searchable_bag &get_bag() const;
};
