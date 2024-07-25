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

#include "../inc/so_long_bonus.h"

int	show_movements(t_game *game)
{
	char	*movement;
	char	*text;
	char	*str;

	movement = ft_itoa(game->movements);
	text = ft_strdup("Movements: ");
	if (!movement)
		end_game(game, 1);
	str = ft_strjoin(text, movement);
	free(movement);
	if (!str)
		end_game(game, 1);
	mlx_string_put(game->mlx.mlx, game->mlx.window, 10, 10, 0x000000, str);
	free(str);
	return (0);
}

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
	show_movements(game);
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
	else if (game->map[i][j] == '!')
		draw_tile(&game->mlx, game->mlx.enemy.img, j, i);
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
