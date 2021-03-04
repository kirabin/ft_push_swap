/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:43:39 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/04 12:38:11 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_put(t_list *list, void (*put)(int content))
{
	if (!list)
	{
		ft_putstr_fd("list is empty\n", 1);
		return ;
	}
	if (!put)
	{
		ft_putstr_fd("function is empty\n", 1);
		return ;
	}
	while (list)
	{
		put(list->content);
		list = list->next;
	}
	ft_putstr_fd("\n", 1);
}
