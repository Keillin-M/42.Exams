/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:19:55 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/27 12:15:58 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other) {
	if (this != &other)
		tree_bag::operator=(other);
	return *this;
}

bool searchable_tree_bag::has(int value) const {
	node *tmp = tree;
	while (tmp) {
		if (value == tmp->value)
			return true;
		else if (value < tmp->value)
			tmp = tmp->l;
		else
			tmp = tmp->r;
	}
	return false;
}

