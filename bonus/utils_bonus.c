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

#include "../inc/so_long_bonus.h"

void	fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == '!')
		return ;
	if (map[x][y] == 'E')
	{
		map[x][y] = '1';
		return ;
	}
	map[x][y] = '1';
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
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

size_t	ft_strlen_array(char **str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
