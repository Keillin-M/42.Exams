/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:17:45 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/10 12:33:03 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_flood_fill(char **tab, t_point size, int row, int col)
{
	if (begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y)
		return (1);
	if (tab[y][x] == 'F' || tab[y][x] == '1')
		return (0);
	ft_flood_fill(tab, size, row - 1, col);
	ft_flood_fill(tab, size, row + 1, col);
	ft_flood_fill(tab, size, row, col - 1);
	ft_flood_fill(tab, size, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	ft_flood_fill(tab, size, begin.y, begin.x);
}
