/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:51:04 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/03 12:04:23 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ft_check(char c, char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (c == stash[i])
      			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;
	char	stash[256] = {0};

	i = 0;
	k = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (!ft_check(argv[1][i], stash))
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					write(1, &argv[1][i], 1);
					stash[k] = argv[1][i];
					k++;
					break ;
				}
				j++;
			}
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
