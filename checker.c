/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:19:16 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/07 14:19:59 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

bool	is_valid_command(char *command)
{
	if (!_strcmp(command, "sa"))
		return (1);
	if (!_strcmp(command, "sb"))
		return (1);
	if (!_strcmp(command, "ss"))
		return (1);
	if (!_strcmp(command, "pa"))
		return (1);
	if (!_strcmp(command, "pb"))
		return (1);
	if (!_strcmp(command, "ra"))
		return (1);
	if (!_strcmp(command, "rb"))
		return (1);
	if (!_strcmp(command, "rr"))
		return (1);
	if (!_strcmp(command, "rra"))
		return (1);
	if (!_strcmp(command, "rrb"))
		return (1);
	if (!_strcmp(command, "rrr"))
		return (1);
	return (0);
}

void	execute_command(char *command, t_list **a, t_list **b)
{
	if (!_strcmp(command, "sa") || !_strcmp(command, "ss"))
		execute_swap(a);
	if (!_strcmp(command, "sb") || !_strcmp(command, "ss"))
		execute_swap(b);
	if (!_strcmp(command, "pa"))
		execute_push(b, a);
	if (!_strcmp(command, "pb"))
		execute_push(a, b);
	if (!_strcmp(command, "ra") || !_strcmp(command, "rr"))
		execute_rotation(a);
	if (!_strcmp(command, "rb") || !_strcmp(command, "rr"))
		execute_rotation(b);
	if (!_strcmp(command, "rra") || !_strcmp(command, "rrr"))
		execute_reverse_rotation(a);
	if (!_strcmp(command, "rrb") || !_strcmp(command, "rrr"))
		execute_reverse_rotation(b);
}

/*
** Is sorted in ascending order
** // TODO: sort by function as a second argument
*/
bool	is_list_sorted(t_list *list)
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

t_list	*cpp_to_list(char **argv)
{
	t_list	*list;
	int		*pint;

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
		pint = malloc(sizeof(int));
		*pint = _atoi((char*)*argv);
		list_add_back(&list, new_list(pint));
		argv++;
	}
	return (list);
}

void	ft_put_lists_ab(t_list *a, t_list *b)
{
	put_string("___\n");
	while (a || b)
	{
		if (a)
		{
			put_int(*(int *)a->content);
			a = a->next;
		}
		else
			putchar(' ');
		putchar(' ');
		if (b)
		{
			put_int(*(int *)b->content);
			b = b->next;
		}
		else
			putchar(' ');

		putchar('\n');
	}
	put_string("___\n");
	put_string("a b\n");
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
		a = cpp_to_list(argv + 1);

		// should read everything first
		// only then execute
		while ((result = get_next_line(0, &command)) != 0)
		{
			if (result == -1)
				// free before return or break ?
				break; // handle_error("Error: get_next_line failed to read a file\n");
			// if (_strcmp(command, "rrb"))
			// {
			// 	ft_put_lists_ab(a, b);
			// }
			else if (is_valid_command(command))
				execute_command(command, &a, &b);
			else
				; // Error: not a valid command

			ft_put_lists_ab(a, b);
			// if option -v is enabled
			free(command);
		}
		free(command);

		if (b == NULL && is_list_sorted(a))
			put_string("OK\n");
		else
			put_string("KO\n");
		clear_list(&a, free);
		clear_list(&b, free);
	}

	// Notes
	// Stack should be able to do:
		// ra, rb, rr    —
		// rra, rrb, rrr — reverse rotate (last element becomes first one)

	return (0);
}
