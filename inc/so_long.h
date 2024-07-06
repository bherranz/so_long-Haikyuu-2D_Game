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

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	t_img	player;
	t_img	coin;
	t_img	exit;
	t_img	wall;
}	t_mlx;

typedef struct s_game
{
	char	**map;
	int		coins;
	size_t	movements;
	t_mlx	mlx;
}	t_game;

//mlx
void	start_mlx(t_mlx *mlx);
void	close_mlx(t_mlx *mlx);

//input control
int		check_map(t_game *game);
void	print_error(char *msg, char function);

//utils
void	free_str_array(char **str);
void	print_map(char **map);
int		count_coins(char **map);
char	**copy_map(char **map);

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
