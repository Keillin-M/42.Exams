/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:20:00 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/27 12:16:04 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public searchable_bag, public tree_bag {
public:
	searchable_tree_bag() {}
	searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {}
	searchable_tree_bag &operator=(const searchable_tree_bag &other);
	bool has(int value) const;
};

