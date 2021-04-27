/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:59:10 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/05 15:04:23 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "libft/libft.h"

typedef struct s_all
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*commands;
	bool	flag_verbose;
}	t_all;

t_list		*argv_to_stack_a(char **argv);
void		ft_put_stacks_ab(t_list *a, t_list *b);

t_all		*init_all(void);
void		free_all(t_all *all);

bool		is_valid_command(char *command);

void		execute_commands(t_all *all);
void		execute_command(char *command, t_list **a, t_list **b);
void		execute_push(t_list **from, t_list **to);
void		execute_reverse_rotation(t_list **list);
void		execute_rotation(t_list **list);
void		execute_swap(t_list **list);

#endif
