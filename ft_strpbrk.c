/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:54:18 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/03 11:00:30 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j
	char	*copy;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	copy = s1;
	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return (copy);
			j++;
		}
		i++;
		copy++;
	}
	return (NULL);
}
