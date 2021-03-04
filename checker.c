/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:19:16 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/04 11:49:34 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		main(int argc, char **argv)
{
	


	// create stack from argv
	// check each item for errors
		// Some errors
		// some arguments are not integers,
		// some arguments are bigger than an integer,
		//  there are duplicates,
		//  an instruction don’t exist and/or is incorrectly formatted.
	// read command and execute one by one


	// Notes
	// Stack should be able to do:
		// sa, sb, ss    — swap first 2 elements on the stack
		// pa, pb        — pop from one and push element to other stack, or do nothing if empty (pa - pop from b push to a)
		// ra, rb, rr    — rotate stack (first element becomes last one)
		// rra, rrb, rrr — reverse rotate (last element becomes first one)


	return (0);
}
