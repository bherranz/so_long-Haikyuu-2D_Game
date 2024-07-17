/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:07:34 by bherranz          #+#    #+#             */
/*   Updated: 2024/06/19 12:07:36 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define TILE_S 32

//Images paths
# define PLAYER_IMG "sprites/player.xpm"
# define COIN_IMG "sprites/coin.xpm"
# define EXIT_IMG "sprites/exit.xpm"
# define WALL_IMG "sprites/wall.xpm"
# define GROUND_IMG "sprites/ground.xpm"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_image
{
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	size_t	width;
	size_t	height;
	t_image	player;
	t_image	coin;
	t_image	exit;
	t_image	wall;
	t_image	ground;
}	t_mlx;

typedef struct s_game
{
	char	**map;
	int		coins;
	size_t	movements;
	t_mlx	mlx;
	size_t	width;
	size_t	height;
	size_t	player_x;
	size_t	player_y;
}	t_game;

//mlx
void	start_mlx(t_mlx *mlx, t_game *game);
void	close_mlx(t_mlx *mlx);
int		keypress(int keysym, t_game *game);
int		destroy(void *param);

//image utils
void	init_images(t_mlx *mlx);
void	draw_map(t_game *game);

//move
void	move_player(t_game *game, int new_x, int new_y);

//input control
int		check_map(t_game *game);
void	print_error(char *msg, char function);

//utils
void	free_str_array(char **str);
void	print_map(char **map);
int		count_coins(char **map);
char	**copy_map(char **map);
size_t	ft_strlen_array(char **str);

//gnl
char	*read_buffer(int fd, char *buffer);
char	*new_line(char *buffer);
char	*to_be_continued(char *buffer, char *line);
char	*get_next_line(int fd);
size_t	ft_strleng(const char *s);
void	*ft_callocg(size_t count, size_t size);
char	*ft_strchrg(const char *s, int c);
char	*ft_strjoing(char *s1, char *s2);
char	*ft_substrg(char *s, unsigned int start, size_t sub_len);

#endif
