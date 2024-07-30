/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:15:43 by bherranz          #+#    #+#             */
/*   Updated: 2023/11/14 11:15:44 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowerhex(size_t num, int i)
{
	char	*digits;
	char	c;

	digits = "0123456789abcdef";
	if (num >= 16)
	{
		i = ft_lowerhex((num / 16), i);
	}
	c = digits[num % 16];
	write(1, &c, 1);
	return (i + 1);
}

int	ft_upperhex(size_t num, int i)
{
	char	*digits;
	char	c;

	digits = "0123456789ABCDEF";
	if (num >= 16)
	{
		i = ft_upperhex((num / 16), i);
	}
	c = digits[num % 16];
	write(1, &c, 1);
	return (i + 1);
}

int	ft_pointers(unsigned long num, int i)
{
	char	*digits;
	char	c;

	digits = "0123456789abcdef";
	if (num >= 16)
	{
		i = ft_lowerhex((num / 16), i);
	}
	c = digits[num % 16];
	write(1, &c, 1);
	return (i + 1);
}
