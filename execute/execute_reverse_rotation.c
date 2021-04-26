/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_reverse_rotation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:04:57 by macbookpro        #+#    #+#             */
/*   Updated: 2021/03/05 15:39:38 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void		execute_reverse_rotation(t_list **list)
{
	t_list *temp;
	t_list *second;

	put_string("executing reverse_rotation\n");
	if (!*list || !(*list)->next)
		return ;
	temp = *list;
	while (temp->next->next)
		temp = temp->next;
	second = temp->next;
	temp->next = NULL;
	second->next = *list;
	*list = second;
}
