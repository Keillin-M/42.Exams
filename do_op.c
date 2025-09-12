/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:33:09 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/03 10:41:15 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	n1;
	int	n2;

	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argv[1] && argv[3])
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[3]);
	}
	if (argv[2][0] == '+')
		printf("%d\n", n1 + n2);
	else if (argv[2][0] == '-')
		printf("%d\n", n1 - n2);
	else if (argv[2][0] == '/')
		printf("%d\n", n1 / n2);
	else if (argv[2][0] == '*')
		printf("%d\n", n1 * n2);
	else
		write(1, "\n", 1);
	return (0);
}
