/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:04:51 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/10 12:16:34 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(ft_list *begin_list, void (*f)(void *))
{
	t_list	*temp;

	temp =  begin_list;
	while (temp != NULL)
	{
		(*f)(temp->data);
		temp = temp->next;
	}
}
