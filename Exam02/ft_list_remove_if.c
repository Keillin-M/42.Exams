/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:51:47 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/10 12:03:28 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if ((*cmp)(begin_list->data, data_ref) == 0x0)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
		ft_list_remove_if(&((*begin_list)->next), data_ref, cmp);
}
