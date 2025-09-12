/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:35:53 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/09 17:43:31 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char	bit;

	i = 8;
	bit = 0;
	while (i--)
	{
		bit = (bit << 1) | (octet & 1)
		octet = octet >> 1;
	}
	return (bit);
}
