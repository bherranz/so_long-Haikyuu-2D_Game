/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:44:48 by bherranz          #+#    #+#             */
/*   Updated: 2024/07/16 10:44:51 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_images(t_mlx *mlx, t_game *game)
{
	mlx->player.img = mlx_xpm_file_to_image(mlx->mlx, PLAYER_IMG,
			&mlx->player.width, &mlx->player.height);
	mlx->coin.img = mlx_xpm_file_to_image(mlx->mlx, COIN_IMG,
			&mlx->coin.width, &mlx->coin.height);
	mlx->exit.img = mlx_xpm_file_to_image(mlx->mlx, EXIT_IMG,
			&mlx->exit.width, &mlx->exit.height);
	mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx, WALL_IMG,
			&mlx->wall.width, &mlx->wall.height);
	mlx->ground.img = mlx_xpm_file_to_image(mlx->mlx, GROUND_IMG,
			&mlx->ground.width, &mlx->ground.height);
	if (!mlx->player.img || !mlx->coin.img || !mlx->exit.img
		|| !mlx->wall.img || !mlx->ground.img)
	{
		free_images(&game->mlx);
		close_mlx(&game->mlx);
		print_error("Error loading images\n", 'w', game);
	}
}

void	draw_tile(t_mlx *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, img, x * TILE_S, y * TILE_S);
}

void	draw_map(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
				draw_tile(&game->mlx, game->mlx.wall.img, j, i);
			else if (game->map[i][j] == 'C')
				draw_tile(&game->mlx, game->mlx.coin.img, j, i);
			else if (game->map[i][j] == 'E')
				draw_tile(&game->mlx, game->mlx.exit.img, j, i);
			else if (game->map[i][j] == 'P')
				draw_tile(&game->mlx, game->mlx.player.img, j, i);
			else
				draw_tile(&game->mlx, game->mlx.ground.img, j, i);
			j++;
		}
		i++;
	}
}

void	free_images(t_mlx *mlx)
{
	if (mlx->player.img)
		mlx_destroy_image(mlx->mlx, mlx->player.img);
	if (mlx->coin.img)
		mlx_destroy_image(mlx->mlx, mlx->coin.img);
	if (mlx->exit.img)
		mlx_destroy_image(mlx->mlx, mlx->exit.img);
	if (mlx->wall.img)
		mlx_destroy_image(mlx->mlx, mlx->wall.img);
	if (mlx->ground.img)
		mlx_destroy_image(mlx->mlx, mlx->ground.img);
}
