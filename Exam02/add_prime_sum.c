/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:37:01 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/09 19:06:53 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int n)
{
	int	num;

	num = n;
	if (num > 9)	
		ft_putnbr(num / 10);
	num = num % 10 + '0';
	write(1, &num, 1);
}

int	ft_prime(int n)
{
	int	i;

	i = 2;
	if (n < 2)
		return (0);
	while (i <= n / 2)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	num;
	int	j;
	int	i;
	int	sum;

	num = 0;
	j = 0;
	i = 0;
	sum = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i] >= 9 && argv[1][i] <= 13 || argv[1][i] == ' ' || argv[1][i] == '+')
		i++;
	if (argv[1][i] == '-')
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i] && argv[1][i] >= '0' && argv[1][i] <= '9')
	{
		num = (num * 10) + (argv[1][i] - '0');
		i++;
	}
	while (j <= num)
	{
		if (ft_prime(j))
			sum += j;
		j++;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}

