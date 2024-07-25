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

void	init_player(t_mlx *mlx)
{
	mlx->player[0][0].img = mlx_xpm_file_to_image(mlx->mlx, DOWN0,
			&mlx->player[0][0].width, &mlx->player[0][0].height);
	mlx->player[0][1].img = mlx_xpm_file_to_image(mlx->mlx, DOWN1,
			&mlx->player[0][1].width, &mlx->player[0][1].height);
	mlx->player[0][2].img = mlx_xpm_file_to_image(mlx->mlx, DOWN2,
			&mlx->player[0][2].width, &mlx->player[0][2].height);
	mlx->player[1][0].img = mlx_xpm_file_to_image(mlx->mlx, LEFT0,
			&mlx->player[1][0].width, &mlx->player[1][0].height);
	mlx->player[1][1].img = mlx_xpm_file_to_image(mlx->mlx, LEFT1,
			&mlx->player[1][1].width, &mlx->player[1][1].height);
	mlx->player[1][2].img = mlx_xpm_file_to_image(mlx->mlx, LEFT2,
			&mlx->player[1][2].width, &mlx->player[1][2].height);
	mlx->player[2][0].img = mlx_xpm_file_to_image(mlx->mlx, RIGHT0,
			&mlx->player[2][0].width, &mlx->player[2][0].height);
	mlx->player[2][1].img = mlx_xpm_file_to_image(mlx->mlx, RIGHT1,
			&mlx->player[2][1].width, &mlx->player[2][1].height);
	mlx->player[2][2].img = mlx_xpm_file_to_image(mlx->mlx, RIGHT2,
			&mlx->player[2][2].width, &mlx->player[2][2].height);
	mlx->player[3][0].img = mlx_xpm_file_to_image(mlx->mlx, UP0,
			&mlx->player[3][0].width, &mlx->player[3][0].height);
	mlx->player[3][1].img = mlx_xpm_file_to_image(mlx->mlx, UP1,
			&mlx->player[3][1].width, &mlx->player[3][1].height);
	mlx->player[3][2].img = mlx_xpm_file_to_image(mlx->mlx, UP2,
			&mlx->player[3][2].width, &mlx->player[3][2].height);
}

void	init_images(t_mlx *mlx, t_game *game)
{
	init_player(mlx);
	mlx->coin.img = mlx_xpm_file_to_image(mlx->mlx, COIN_IMG,
			&mlx->coin.width, &mlx->coin.height);
	mlx->exit.img = mlx_xpm_file_to_image(mlx->mlx, EXIT_IMG,
			&mlx->exit.width, &mlx->exit.height);
	mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx, WALL_IMG,
			&mlx->wall.width, &mlx->wall.height);
	mlx->ground.img = mlx_xpm_file_to_image(mlx->mlx, GROUND_IMG,
			&mlx->ground.width, &mlx->ground.height);
	if (!mlx->coin.img || !mlx->exit.img || !mlx->wall.img || !mlx->ground.img
		|| !mlx->player[0][0].img || !mlx->player[0][1].img ||
		!mlx->player[0][2].img || !mlx->player[1][0].img ||
		!mlx->player[1][1].img || !mlx->player[1][2].img ||
		!mlx->player[2][0].img || !mlx->player[2][1].img ||
		!mlx->player[2][2].img || !mlx->player[3][0].img ||
		!mlx->player[3][1].img || !mlx->player[3][2].img)
	{
		end_game(game, 1);
		write(2, "Error loading images\n", ft_strlen("Error loading images\n"));
		exit (1);
	}
}

void	free_player(t_mlx *mlx, t_image player[4][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			if (player[i][j].img)
				mlx_destroy_image(mlx->mlx, player[i][j].img);
			j++;
		}
		i++;
	}
}

void	free_images(t_mlx *mlx)
{
	free_player(mlx, mlx->player);
	if (mlx->coin.img)
		mlx_destroy_image(mlx->mlx, mlx->coin.img);
	if (mlx->exit.img)
		mlx_destroy_image(mlx->mlx, mlx->exit.img);
	if (mlx->wall.img)
		mlx_destroy_image(mlx->mlx, mlx->wall.img);
	if (mlx->ground.img)
		mlx_destroy_image(mlx->mlx, mlx->ground.img);
}
