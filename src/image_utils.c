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

void	init_images(t_game *game, t_mlx *mlx)
{
	mlx->player.img = mlx_xpm_file_to_image(mlx->mlx, PLAYER_IMG, &mlx->player.width, &mlx->player.height);
	mlx->coin.img = mlx_xpm_file_to_image(mlx->mlx, COIN_IMG, &mlx->coin.width, &mlx->coin.height);
	mlx->exit.img = mlx_xpm_file_to_image(mlx->mlx, EXIT_IMG, &mlx->exit.width, &mlx->exit.height);
	mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx, WALL_IMG, &mlx->wall.width, &mlx->wall.height);
	mlx->ground.img = mlx_xpm_file_to_image(mlx->mlx, GROUND_IMG, &mlx->ground.width, &mlx->ground.height);

	if (!mlx->player.img || !mlx->coin.img || !mlx->exit.img || !mlx->wall.img || !mlx->ground.img)
		print_error("Error loading images\n", 'w');
}

void draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
                draw_tile(&game->mlx, game->mlx.wall.img, x, y);
            else if (game->map[i][j] == 'C')
                draw_tile(&game->mlx, game->mlx.coin.img, x, y);
            else if (game->map[i][j] == 'E')
                draw_tile(&game->mlx, game->mlx.exit.img, x, y);
            else if (game->map[i][j] == 'P')
                draw_tile(&game->mlx, game->mlx.player.img, x, y);
            else
                draw_tile(&game->mlx, game->mlx.ground.img, x, y);
			j++;
		}
		i++;
	}
}
