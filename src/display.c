/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:29:34 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/14 06:54:09 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	texture_load(t_root *root, void **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	if (*img == 0)
		root_kill(0, "texture_load(): can't load texture", 0);
}

void	add_stuff(t_root *root, int i, int j)
{
	int				k;

	if (root->game->exit.x == i && root->game->exit.y == j)
		mlx_put_image_to_window(root->mlx, root->mlx_win,
			root->exit, i * 64, j * 64);
	k = -1;
	while (++k < root->game->count_coll)
		if (root->game->coll[k].x == i && root->game->coll[k].y == j)
			mlx_put_image_to_window(root->mlx, root->mlx_win,
				root->coll, i * 64, j * 64);
	if (root->game->player.x == i && root->game->player.y == j)
		mlx_put_image_to_window(root->mlx, root->mlx_win,
			root->player, i * 64, j * 64);
	k = -1;
	while (++k < root->game->count_wolf)
		if (root->game->wolf[k].x == i && root->game->wolf[k].y == j)
			mlx_put_image_to_window(root->mlx, root->mlx_win,
				root->wolf, i * 64, j * 64);
}

void	draw_map(t_root *root)
{
	int				i;
	int				j;

	j = 0;
	while (j < root->game->height)
	{
		i = 0;
		while (i < root->game->width + 1)
		{
			if (i == root->game->width)
				mlx_put_image_to_window(root->mlx, root->mlx_win,
					root->side, i * 64, j * 64);
			else if (root->game->map[j][i] == 1)
				mlx_put_image_to_window(root->mlx, root->mlx_win,
					root->wall, i * 64, j * 64);
			else
				mlx_put_image_to_window(root->mlx, root->mlx_win,
					root->ground, i * 64, j * 64);
			add_stuff(root, i, j);
			i++;
		}
		j++;
	}
}

int	char_disp(t_root *root)
{
	static int	ic;

	usleep(30000);
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->ground, root->game->player.x * 64, root->game->player.y * 64);
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->player[++ic],
		root->game->player.x * 64, root->game->player.y * 64);
	if (ic == 3)
		ic = 0;
	usleep(30000);
	return (0);
}
