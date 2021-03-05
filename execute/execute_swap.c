/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:05:03 by macbookpro        #+#    #+#             */
/*   Updated: 2021/03/05 15:18:59 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

/*
** Swap first two elements on top of the stack "list"
*/

void		execute_swap(t_list **list)
{
	ft_putstr("executing swap\n");

	t_list *first;
	t_list *second;

	if (!*list || !(*list)->next)
		return ;
	first = *list;
	second = first->next;
	ft_lst_swap(list, first, second);
}