/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:23:07 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/09 17:26:51 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;
	unsigned char	bit;

	i = 8;
	bit = 0;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int	main()
{
	unsigned char	octet = 3;
	print_bits(octet);
	return (0);
}
