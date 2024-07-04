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

#include "../inc/so_long.h"

void	print_error(char *msg, char function)
{
	size_t	w;

	if (function == 'p')
		perror(msg);
	else
		w = write(2, msg, ft_strlen(msg));
	(void)w;
	exit (1);
}

char	**create_map(char *argv)
{
	char	**map;
	char	*line;
	char	*current;
	int		fd;

	fd = open(argv, O_RDONLY, 0644);
	if (fd < 0)
		print_error(argv, 'p');
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
		print_error("Error\n", 'w');
	game.map = create_map(argv[1]);
	check_map(&game);
	print_map(game.map);
	free_str_array(game.map);
	return (0);
}
