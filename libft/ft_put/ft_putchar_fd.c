/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:22:14 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/04 12:33:52 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putc_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putuc_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl()
{
	write(1, "\n", 1);
}
