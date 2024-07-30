/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:02:31 by bherranz          #+#    #+#             */
/*   Updated: 2023/10/25 11:02:37 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_integer(int num, int i)
{
	char	c;

	if (num == -2147483648)
	{
		write(1, "-214748364", 10);
		i = i + 10;
		num = 8;
	}
	else if (num < 0)
	{
		write(1, "-", 1);
		i++;
		num = -num;
	}
	c = num % 10 + '0';
	if (num >= 10)
		i = ft_integer((num / 10), i);
	write(1, &c, 1);
	return (i + 1);
}

int	ft_unsign(unsigned int num, int i)
{
	char	c;

	c = num % 10 + '0';
	if (num >= 10)
		i = ft_integer((num / 10), i);
	write(1, &c, 1);
	return (i + 1);
}
