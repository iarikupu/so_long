/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:18:55 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/14 06:44:13 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	root_kill(t_root *root, char *errmsg, int errnum)
{
	if (root != 0)
	{
		if (root->ground != 0)
			mlx_destroy_image(root->mlx, root->ground);
		if (root->wall != 0)
			mlx_destroy_image(root->mlx, root->wall);
		if (root->coll != 0)
			mlx_destroy_image(root->mlx, root->coll);
		if (root->exit != 0)
			mlx_destroy_image(root->mlx, root->exit);
		if (*root->player != 0)
			mlx_destroy_image(root->mlx, *root->player);
		if (root->wolf != 0)
			mlx_destroy_image(root->mlx, root->wolf);
		if (root->mlx_win != 0)
			mlx_destroy_window(root->mlx, root->mlx_win);
		if (root->mlx != 0)
			free(root->mlx);
		if (root->game != 0)
			game_kill(root->game);
		free(root);
	}
	error_display(errmsg, errnum);
}

void	game_kill(t_game *game)
{
	int				i;

	if (game != 0)
	{
		if (game->coll != 0)
			free(game->coll);
		if (game->wolf != 0)
			free(game->wolf);
		if (game->map != 0)
		{
			i = 0;
			while (i < game->height)
				free(game->map[i++]);
			free(game->map);
		}
		free(game);
	}
}

void	error_display(char *errm, int errn)
{
	if (errm != 0 || errn != 0)
		ft_putendl_fd("Error", 2);
	if (errm != 0)
		ft_putstr_fd(errm, 2);
	if (errm != 0 && errn != 0)
		ft_putstr_fd(": ", 2);
	if (errn != 0)
		ft_putstr_fd(strerror(errn), 2);
	if (errm != 0 || errn != 0)
	{
		ft_putendl_fd("", 2);
		exit(1);
	}
	exit(0);
}

void	free_the_matrix(t_root *root, char *file, int **m, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	root->game->map = 0;
	free(file);
	root_kill(root, "map_parsing(): malloc()", errno);
}
