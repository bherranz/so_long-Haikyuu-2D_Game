/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:02:53 by bherranz          #+#    #+#             */
/*   Updated: 2023/10/25 11:03:01 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_character(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_string(const char *str)
{
	int	count;

	count = 0;
	if (str == (char *) NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}
