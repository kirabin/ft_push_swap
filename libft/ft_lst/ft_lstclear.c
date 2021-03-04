/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:13:04 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/04 12:27:43 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*node;
	t_list	*temp;

	node = *lst;
	if (!*lst)
		return ;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	*lst = NULL;
}
