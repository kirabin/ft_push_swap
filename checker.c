/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:19:16 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/04 12:41:32 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

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

int		main(int argc, char **argv)
{
	t_list	*left_list;

	if (argc >= 2)
	{
		left_list = ft_array_to_list(argv + 1);
		ft_lst_put(left_list, ft_puti_endl);
		ft_lstclear(&left_list);
	}

	// read command and execute one by one


	// Notes
	// Stack should be able to do:
		// sa, sb, ss    — swap first 2 elements on the stack
		// pa, pb        — pop from one and push element to other stack, or do nothing if empty (pa - pop from b push to a)
		// ra, rb, rr    — rotate stack (first element becomes last one)
		// rra, rrb, rrr — reverse rotate (last element becomes first one)


	return (0);
}
