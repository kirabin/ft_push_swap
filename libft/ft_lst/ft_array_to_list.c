/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:17:02 by macbookpro        #+#    #+#             */
/*   Updated: 2021/03/07 14:19:18 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_array_to_list(char **argv)
{
	t_list *list;

	list = NULL;
	while (*argv)
	{
		// if *argv is ingeger, else print Error
			// check each item for errors
			// Some errors
			// some arguments are not integers,
			// some arguments are bigger than an integer,
			//  there are duplicates,
			//  an instruction don’t exist and/or is incorrectly formatted.
		ft_lstadd_back(&list, ft_lstnew(ft_atoi((char*)*argv)));
		argv++;
	}
	return (list);
}
