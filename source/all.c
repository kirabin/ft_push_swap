#include "includes.h"

// if *argv is ingeger, else print Error
			// check each item for errors
			// Some errors
			// some arguments are not integers,
			// some arguments are bigger than an integer,
			//  there are duplicates,
			//  an instruction don’t exist and/or is incorrectly formatted.
bool	is_valid_argument(char *s, t_list *list, t_list *new)
{
	if (!is_number(s) || !is_integer(s))
	{
		put_string("Error: Arguments should be integers!\n");
		return (false);
	}
	else if (find_list(list, new->content, list_compare_int_equal))
	{
		put_string("Error: Duplicate arguments!\n");
		return (false);
	}
	return (true);
}

t_list	*argv_to_stack_a(char **argv)
{
	t_list	*list;
	t_list	*new;

	list = NULL;
	while (argv && *argv)
	{
		new = new_list_int(_atoi((char *)*argv));
		if (is_valid_argument(*argv, list, new))
		{
			list_add_back(&list, new);
		}
		else
		{
			clear_list(&new, free);
			clear_list(&list, free);
			return (NULL);
		}
		argv++;
	}
	return (list);
}

void	free_all(t_all *all)
{
	if (all)
	{
		clear_list(&all->stack_a, free);
		clear_list(&all->stack_b, free);
		clear_list(&all->commands, free);
	}
	free(all);
}

t_all	*init_all(void)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (all)
	{
		all->stack_a = NULL;
		all->stack_b = NULL;
		all->commands = NULL;
	}
	return (all);
}
