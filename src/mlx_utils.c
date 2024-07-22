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

void	start_mlx(t_mlx *mlx, t_game *game)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		print_error("Error initializing MLX\n", 'w', game);
	mlx->width = game->width * TILE_S;
	mlx->height = game->height * TILE_S;
	mlx->window = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "Haikyuu!");
	if (!mlx->window)
	{
		if (mlx->mlx)
			free(mlx->mlx);
		print_error("Error creating window\n", 'w', game);
	}
	mlx_hook(mlx->window, KeyPress, KeyPressMask, keypress, game);
	mlx_hook(mlx->window, DestroyNotify, NoEventMask, destroy, game);
	//mlx_loop_hook(mlx->mlx, draw_player, game);
}

void	close_mlx(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

int	destroy(void *param)
{
	end_game((t_game *)param, 0);
	return (0);
}

int	keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		end_game(game, 0);
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		move_player(game, game->player_x, game->player_y - 1, "Up");
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		move_player(game, game->player_x, game->player_y + 1, "Down");
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		move_player(game, game->player_x - 1, game->player_y, "Left");
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		move_player(game, game->player_x + 1, game->player_y, "Right");
	return (0);
}
