/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:20:30 by bherranz          #+#    #+#             */
/*   Updated: 2024/07/17 11:20:32 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	end_game(t_game *game, int error)
{
	free_str_array(game->map);
	free_images(&game->mlx);
	close_mlx(&game->mlx);
	if (error == 0)
		exit (0);
}

void move_player(t_game *game, int x, int y, char *dir)
{
	game->dir = dir;
	if (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'E' && game->coins != 0)
			return ;
		if (game->map[y][x] == 'E' && game->coins == 0)
			end_game(game, 0);
		if (game->map[y][x] == 'C')
			game->coins--;
		game->map[game->player_y][game->player_x] = '0';
		draw(game, game->player_y, game->player_x);
		game->map[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->movements++;
		printf("Movements: %zu\n", game->movements);
	}
}
