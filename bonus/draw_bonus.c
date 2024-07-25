/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:07:20 by bherranz          #+#    #+#             */
/*   Updated: 2024/07/25 12:07:21 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	draw_player(t_game *game)
{
	static float	module;

	module += 0.0005;
	if (ft_strcmp(game->dir, "Down") == 0)
		draw_tile(&game->mlx, game->mlx.player[0][(int)module % 3].img,
			game->player_x, game->player_y);
	else if (ft_strcmp(game->dir, "Left") == 0)
		draw_tile(&game->mlx, game->mlx.player[1][(int)module % 3].img,
			game->player_x, game->player_y);
	else if (ft_strcmp(game->dir, "Right") == 0)
		draw_tile(&game->mlx, game->mlx.player[2][(int)module % 3].img,
			game->player_x, game->player_y);
	else if (ft_strcmp(game->dir, "Up") == 0)
		draw_tile(&game->mlx, game->mlx.player[3][(int)module % 3].img,
			game->player_x, game->player_y);
	return (0);
}

void	draw_tile(t_mlx *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, img, x * TILE_S, y * TILE_S);
}

void	draw(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		draw_tile(&game->mlx, game->mlx.wall.img, j, i);
	else if (game->map[i][j] == 'C')
		draw_tile(&game->mlx, game->mlx.coin.img, j, i);
	else if (game->map[i][j] == 'E')
		draw_tile(&game->mlx, game->mlx.exit.img, j, i);
	else if (game->map[i][j] == 'P')
		draw_tile(&game->mlx, game->mlx.player[0][1].img, j, i);
	else if (game->map[i][j] == '0')
		draw_tile(&game->mlx, game->mlx.ground.img, j, i);
}

int	draw_map(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			draw(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
