/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:20:18 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/27 12:52:48 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

bool set::has(int value) { return (bag.has(value)); }

void set::insert(int value) { bag.insert(value); }

void set::insert(int *arr, int size) { bag.insert(arr, size); }

void set::print() const { bag.print(); }

void set::clear() { bag.clear(); }

const searchable_bag &set::get_bag() const { return bag; }
