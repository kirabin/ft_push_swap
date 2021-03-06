/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:19:16 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/06 15:46:02 by macbookpro       ###   ########.fr       */
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

bool	is_valid_command(char *command)
{
	if (!ft_strcmp(command, "sa"))
		return (1);
	if (!ft_strcmp(command, "sb"))
		return (1);
	if (!ft_strcmp(command, "ss"))
		return (1);
	if (!ft_strcmp(command, "pa"))
		return (1);
	if (!ft_strcmp(command, "pb"))
		return (1);
	if (!ft_strcmp(command, "ra"))
		return (1);
	if (!ft_strcmp(command, "rb"))
		return (1);
	if (!ft_strcmp(command, "rr"))
		return (1);
	if (!ft_strcmp(command, "rra"))
		return (1);
	if (!ft_strcmp(command, "rrb"))
		return (1);
	if (!ft_strcmp(command, "rrr"))
		return (1);
	return (0);
}

void	execute_command(char *command, t_list **a, t_list **b)
{
	if (!ft_strcmp(command, "sa") || !ft_strcmp(command, "ss"))
		execute_swap(a);
	if (!ft_strcmp(command, "sb") || !ft_strcmp(command, "ss"))
		execute_swap(b);
	if (!ft_strcmp(command, "pa"))
		execute_push(b, a);
	if (!ft_strcmp(command, "pb"))
		execute_push(a, b);
	if (!ft_strcmp(command, "ra") || !ft_strcmp(command, "rr"))
		execute_rotation(a);
	if (!ft_strcmp(command, "rb") || !ft_strcmp(command, "rr"))
		execute_rotation(b);
	if (!ft_strcmp(command, "rra") || !ft_strcmp(command, "rrr"))
		execute_reverse_rotation(a);
	if (!ft_strcmp(command, "rrb") || !ft_strcmp(command, "rrr"))
		execute_reverse_rotation(b);
}

/*
** Is sorted in ascending order
*/

bool	is_sorted(t_list *list)
{
	if (!list || !list->next)
		return (1);
	while (list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*command;
	int		result;

	command = NULL;
	b = NULL;
	a = NULL;
	if (argc >= 2)
	{
		a = ft_array_to_list(argv + 1);

		// should read everything first
		// only then execute
		while ((result = get_next_line(0, &command)) != 0)
		{
			if (result == -1)
				// free before return or break ?
				break; // handle_error("Error: get_next_line failed to read a file\n");
			// if (ft_strcmp(command, "rrb"))
			// {
			// 	ft_put_lists_ab(a, b);
			// }
			else if (is_valid_command(command))
				execute_command(command, &a, &b);
			else
				; // Error: not a valid command

			// if option -v is enabled
			free(command);
		}
		free(command);

		if (b == NULL && is_sorted(a))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		ft_lstclear(&a);
		ft_lstclear(&b);
	}




	// Notes
	// Stack should be able to do:


		// ra, rb, rr    —
		// rra, rrb, rrr — reverse rotate (last element becomes first one)


	return (0);
}
