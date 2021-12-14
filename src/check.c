/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:28:10 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/14 06:49:02 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	filecheck(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (! file)
		return (1);
	if (len < 5)
		return (1);
	if (ft_strncmp(file + len - 4, ".ber", 4))
		return (1);
	return (0);
}

void	map_check(t_root *root, char *file)
{
	int				i;

	i = -1;
	while (file[++i] != 0)
	{
		if (file[i] == '\n')
			continue ;
		if (isborder(root, i))
		{
			if (file[i] != '1')
			{
				free(file);
				root_kill(root, "map isn't surrounded by walls", 0);
			}
		}
		else
			isvalid(root, file, i);
	}
	if (root->game->count_player != 1
		|| root->game->count_exit != 1
		|| root->game->count_coll < 1)
	{
		free(file);
		root_kill(root, "map configuration is invalid", 0);
	}
}

void	isvalid(t_root *root, char *file, int i)
{
	if (file[i] == 'P')
		root->game->count_player++;
	else if (file[i] == 'E')
		root->game->count_exit++;
	else if (file[i] == 'C')
		root->game->count_coll++;
	else if (file[i] == 'X')
		root->game->count_wolf++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		root_kill(root, "map content is invalid", 0);
	}
}

int	isborder(t_root *root, int i)
{
	if (i < root->game->width
		|| i > (root->game->width + 1) * (root->game->height - 1)
		|| i % (root->game->width + 1) == 0
		|| i % (root->game->width + 1) == root->game->width - 1)
		return (1);
	return (0);
}
