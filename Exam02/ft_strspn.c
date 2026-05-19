/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:07:00 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/03 11:10:55 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] != accept[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			return (i);
		i++;
	}
	return (i);
}
