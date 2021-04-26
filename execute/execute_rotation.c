/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:04:52 by macbookpro        #+#    #+#             */
/*   Updated: 2021/03/05 15:30:27 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

/*
** Rotate stack (first element becomes last one)
*/

void		execute_rotation(t_list **list)
{
	t_list *temp;
	t_list *first;

	put_string("executing rotation\n");
	if (!*list || !(*list)->next)
		return ;
	temp = *list;
	*list = (*list)->next;
	first = temp;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = first;
	first->next = NULL;
}
