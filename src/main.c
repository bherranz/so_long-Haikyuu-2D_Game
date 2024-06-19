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

void	print_map(char **map)
{
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
}

void	print_error(char *msg)
{
	perror(msg);
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
		print_error(argv);
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

void	input_control(int argc, char **argv)
{
	if (argc != 2 || ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	char	**map;

	input_control(argc, argv);
	map = create_map(argv[1]);
	print_map(map);
	check_map(map);
	return (0);
}
