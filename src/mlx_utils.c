/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:36:56 by bherranz          #+#    #+#             */
/*   Updated: 2024/06/19 11:36:57 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	start_mlx(t_mlx *mlx, int w, int h)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		print_error("Error initializing MLX\n", 'w');
	mlx->window = mlx_new_window(mlx->mlx, w * TILE_S, h * TILE_S, "Haikyuu!");
	if (!mlx->window)
	{
		if (mlx->mlx)
			free(mlx->mlx);
		print_error("Error creating window\n", 'w');
	}
	mlx_hook(mlx->window, KeyPress, KeyPressMask, keypress, mlx);
	mlx_hook(mlx->window, DestroyNotify, NoEventMask, destroy, mlx);
	mlx_loop(mlx->mlx);
	//control errores + iniciar sprites
}

void	close_mlx(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
		free(mlx->mlx);
	exit (0);
}

int	destroy(void *param)
{
	close_mlx((t_mlx *)param);
	return (0);
}

int	keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		close_mlx(mlx);
	return (0);
}
