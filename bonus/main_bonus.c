/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:36:56 by bherranz          #+#    #+#             */
/*   Updated: 2024/06/19 11:36:57 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	print_error(char *msg, char function, t_game *game)
{
	if (function == 'p')
		perror(msg);
	else
		write(2, msg, ft_strlen(msg));
	if (game)
		free_str_array(game->map);
	exit (1);
}

int	check_map(t_game *game)
{
	is_rectangular(game->map, game);
	check_walls(game->map, game);
	game->coins = 0;
	check_chars(game, game->map);
	is_playable(game->map, game);
	return (0);
}

void	check_newlines(char *map)
{
	char	current;
	char	prev;
	int		i;

	prev = map[0];
	current = map[1];
	i = 1;
	while (map[i])
	{
		if (current == '\n' && prev == '\n')
		{
			free(map);
			write(2, "Error\nThe map must be surrounded by a wall\n", 44);
			exit (1);
		}
		i++;
		prev = current;
		current = map[i];
	}
}

char	**create_map(char *argv)
{
	char	**map;
	char	*line;
	char	*current;
	int		fd;

	fd = open(argv, O_RDONLY, 0644);
	if (fd < 0)
		print_error(argv, 'p', NULL);
	current = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		current = ft_strjoin(current, line);
		free(line);
	}
	map = ft_split(current, '\n');
	free(current);
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
		print_error("Error\n", 'w', NULL);
	game.map = create_map(argv[1]);
	check_map(&game);
	game.width = ft_strlen(game.map[0]);
	game.height = ft_strlen_array(game.map);
	game.movements = 0;
	game.mlx.mlx = NULL;
	game.dir = "Down";
	start_mlx(&game.mlx, &game);
	init_images(&game.mlx, &game);
	draw_map(&game);
	mlx_loop(game.mlx.mlx);
	end_game(&game, 0);
	return (0);
}
