/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_lists_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:55:23 by macbookpro        #+#    #+#             */
/*   Updated: 2021/03/05 15:01:43 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_lists_ab(t_list *a, t_list *b)
{
	ft_putstr("___\n");
	while (a || b)
	{
		if (a)
		{
			ft_puti(a->content);
			a = a->next;
		}
		else
			ft_putc_fd(' ', 1);
		ft_putc_fd(' ', 1);
		if (b)
		{
			ft_puti(b->content);
			b = b->next;
		}
		else
			ft_putc_fd(' ', 1);

		ft_putc_fd('\n', 1);
	}
	ft_putstr("___\n");
	ft_putstr("a b\n");
}