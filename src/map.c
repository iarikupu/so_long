/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:32:31 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/14 07:11:08 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_create(t_root *root, char *filename)
{
	int				fd;
	char			*file;
	char			buf[1024 + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		root_kill(root, filename, errno);
	file = file_create(root, fd);
	file_read(root, &file, buf, fd);
	close(fd);
	map_read(root, file);
	free(file);
}

void	map_read(t_root *root, char *file)
{
	map_width(root, file);
	map_height(root, file);
	map_check(root, file);
	root->game->coll
		= (t_coord *)malloc(sizeof(t_coord) * root->game->count_coll);
	root->game->wolf
		= (t_coord *)malloc(sizeof(t_coord) * root->game->count_wolf);
	if (root->game->coll == 0)
	{
		free(file);
		root_kill(root, "map_parsing(): malloc()", errno);
	}
	root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
	if (root->game->map == 0)
	{
		free(file);
		root_kill(root, "map_parsing(): malloc()", errno);
	}
	map_parsing(root, file);
}

void	map_height(t_root *root, char *file)
{
	int				i;
	int				j;

	root->game->height = 1;
	i = root->game->width + 1;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (root->game->width != j)
		{
			free(file);
			root_kill(root, "map format is invalid", 0);
		}
		i += root->game->width + 1;
		root->game->height++;
	}
}

void	map_parsing(t_root *root, char *file)
{
	int				i;
	int				j;
	int				k;
	int				obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < root->game->height)
	{
		root->game->map[j] = (int *)malloc(sizeof(int) * root->game->width);
		if (root->game->map[j] == 0)
			free_the_matrix(root, file, root->game->map, j);
		i = 0;
		while (i < root->game->width)
		{
			get_coord(root, file, k, &obj);
			root->game->map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}

void	map_width(t_root *root, char *file)
{
	root->game->width = 0;
	while (file[root->game->width] && file[root->game->width] != '\n')
		root->game->width++;
	if (root->game->width == 0 || file[root->game->width] == 0)
	{
		free(file);
		root_kill(root, "map file is invalid", 0);
	}
}
