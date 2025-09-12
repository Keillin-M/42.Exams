/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:08:16 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/09 16:12:03 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	int	x;

	x = 1;
	while (x <= n)
	{
		if (x == n)
			return (1);
		x *= 2;
	}
	return (0);
}
/*
int	main()
{
	printf("%d\n", is_power_of_2(64));
	return (0);
}*/
