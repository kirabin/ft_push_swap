/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:04:48 by macbookpro        #+#    #+#             */
/*   Updated: 2021/03/11 10:17:12 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

/*
** Pop from and push to, or do nothing if from is empty.
*/

void		execute_push(t_list **from, t_list **to)
{
	t_list *temp;

	ft_putstr("executing push\n");
	if (!*from)
		return;
	temp = *from;
	*from = temp->next;
	ft_lstadd_front(to, temp);
}