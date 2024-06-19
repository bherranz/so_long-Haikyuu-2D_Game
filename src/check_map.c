/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <bherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:18:53 by bherranz          #+#    #+#             */
/*   Updated: 2024/06/19 20:18:54 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_rectangular(char **map)
{
	size_t	size;

	size = ft_strlen(*map);
	while (*map)
	{
		if (size != ft_strlen(*map))
			return (0);
		map++;
	}
	return (1);
}

int	check_map(char **map)
{
	if (!is_rectangular(map))
		exit (1);
	return (0);
}
