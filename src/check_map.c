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

void	is_rectangular(char **map)
{
	size_t	size;

	size = ft_strlen(*map);
	while (*map)
	{
		if (size != ft_strlen(*map))
			print_error("Error\nThe map must be rectangular\n", 'w');
		map++;
	}
}

void	check_walls(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			print_error("Error\nThe map must be surrounded by wall\n", 'w');
		j++;
	}
	i = 1;
	while (map[i + 1])
	{
		if ((map[i][0] != '1') || (map[i][ft_strlen(map[i]) - 1] != '1'))
			print_error("Error\nThe map must be surrounded by wall\n", 'w');
		i++;
	}
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			print_error("Error\nThe map must be surrounded by wall\n", 'w');
		j++;
	}
}

void	check_chars(t_game *game, char **map)
{
	int		exit;
	int		start;
	char	*row;

	exit = 0;
	start = 0;
	while (*map)
	{
		row = *map;
		while (*row)
		{
			if (*row == 'C')
				game->coins++;
			else if (*row == 'E')
				exit++;
			else if (*row == 'P')
				start++;
			else if (*row != '1' && *row != '0')
				print_error("Error\nCharacters not allowed\n", 'w');
			row++;
		}
		map++;
	}
	if (exit != 1 || start != 1 || game->coins == 0)
		print_error("Error\nWrong map\n", 'w');
}

// int	is_playable(t_game *game)
// {
// 	//chequear si posición actual es 'E' y game->coins == 0
// 		//devolver 1
// 	//recursividad moviendo en todas las direcciones posibles	
// 	return (0);
// }

int	check_map(t_game *game)
{
	is_rectangular(game->map);
	check_walls(game->map);
	game->coins = 0;
	check_chars(game, game->map); //también cuenta las monedas
	//is_playable(game);
	print_map(game->map);
	return (0);
}
