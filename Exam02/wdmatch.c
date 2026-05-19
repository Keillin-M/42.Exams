/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:55:48 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/09 18:02:09 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = 0;
	j = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][len])
		len++;
	while (argv[2][j])
	{
		if (argv[1][i] == argv[2][j])
			i++;
		if (i == len)
		{
			write(1, argv[1], len);
			break ;
		}
		j++;
	}
	write (1, "\n", 1);
	return (0);
}
