/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:56:14 by kmaeda            #+#    #+#             */
/*   Updated: 2025/08/21 11:14:33 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1] || !argv[1][0])
		return (perror("Error"), 1);
	char	*result = NULL;
	char	*buffer = NULL;
	int	total_size = 0;
	int	capacity = 1024;
	char	*s = argv[1];
	int	s_len = strlen(s);
	int	bytes_read = 1;

	buffer = malloc(capacity);
	if (!buffer)
		return (perror("Error"), 1);
	while (bytes_read > 0)
	{
		bytes_read = read(0, buffer, capacity - total_size);
		total_size += bytes_read;
		if (total_size >= capacity - 1)
		{
			capacity *= 2;
			buffer = realloc(buffer, capacity);
			if (!buffer)
				return (perror("Error"), 1);
		}
	}
	if (bytes_read < 0)
		return (free(buffer), perror("Error"), 1);
	result = malloc(total_size + 1);
	if (!result)
		return (perror("Error"), 1);
	int	j;
	int	i = 0;
	int	res_pos = 0;

	while (i < total_size)
	{
		char	*found = memmem(buffer + i, total_size - i, s, s_len);
		if (found && found == buffer + i)
		{
			j = 0;
			while (j < s_len)
			{
				result[res_pos] = '*';
				res_pos++;
				j++;
			}
			i += s_len;
		}
		else
			result[res_pos++] = buffer[i++];
	}
	write(1, result, res_pos);
	free(buffer);
	free(result);
	return (0);
}
