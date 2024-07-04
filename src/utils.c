/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <bherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:18:53 by bherranz          #+#    #+#             */
/*   Updated: 2024/06/19 20:18:54 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_map(char **map)
{
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
}

void	free_str_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	count_coins(char **map)
{
	int		coin;
	char	*row;

	coin = 0;
	while (*map)
	{
		row = *map;
		while (*row)
		{
			if (*row == 'C')
				coin++;
			row++;
		}
		map++;
	}
	return (coin);
}

char	**copy_map(char **map)
{
	int		rows;
	char	**new_map;

	rows = 0;
	while (map[rows])
		rows++;
	new_map = malloc((rows + 1) * sizeof(char *));
	new_map[rows] = NULL;
	while (rows > 0)
	{
		new_map[rows - 1] = strdup(map[rows - 1]);
		rows--;
	}
	return (new_map);
}
