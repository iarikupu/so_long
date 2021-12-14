/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:34:59 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/14 07:40:02 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	had_move(t_root *root, int x, int y)
{
	char	*c;

	if (root->game->player.x != x || root->game->player.y != y)
	{
		root->game->player_move++;
		ft_putnbr_fd(root->game->player_move, 1);
		ft_putendl_fd("", 1);
	}
	c = ft_itoa(root->game->player_move);
	mlx_string_put(root->mlx, root->mlx_win,
		(root->game->width * 64), 20, 0, c);
	free(c);
}

void	iscollectable(t_root *root)
{
	int				k;

	k = 0;
	while (k < root->game->count_coll)
	{
		if (root->game->coll[k].x == root->game->player.x
			&& root->game->coll[k].y == root->game->player.y)
		{
			root->game->coll[k].x = -1;
			root->game->coll[k].y = -1;
			root->game->player_coll++;
		}
		k++;
	}
}

void	iswolf(t_root *root)
{
	int				k;

	k = 0;
	while (k < root->game->count_wolf)
	{
		if (root->game->wolf[k].x == root->game->player.x
			&& root->game->wolf[k].y == root->game->player.y)
		{
			ft_putstr_fd("Game Over : You Died", 1);
			key_press(53, root);
		}
		k++;
	}
}

void	update(t_root *root)
{
	int				x;
	int				y;

	x = root->game->player.x;
	y = root->game->player.y;
	if (root->game->player_up != 0)
		move_up(root, x, y);
	else if (root->game->player_down != 0)
		move_down(root, x, y);
	else if (root->game->player_left != 0)
		move_left(root, x, y);
	else if (root->game->player_right != 0)
		move_right(root, x, y);
	iscollectable(root);
	iswolf(root);
	draw_map(root);
	had_move(root, x, y);
	if (root->game->exit.x == root->game->player.x
		&& root->game->exit.y == root->game->player.y)
		if (root->game->count_coll == root->game->player_coll)
			root_kill(root, 0, 0);
}

void	get_coord(t_root *root, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		root->game->player.x = k % (root->game->width + 1);
		root->game->player.y = k / (root->game->width + 1);
	}
	else if (file[k] == 'E')
	{
		root->game->exit.x = k % (root->game->width + 1);
		root->game->exit.y = k / (root->game->width + 1);
	}
	else if (file[k] == 'C')
	{
		root->game->coll[*obj].x = k % (root->game->width + 1);
		root->game->coll[(*obj)++].y = k / (root->game->width + 1);
	}
	else if (file[k] == 'X')
	{
		root->game->wolf[root->game->t_wc].x = k % (root->game->width + 1);
		root->game->wolf[(root->game->t_wc)++].y = k / (root->game->width + 1);
	}
	if (file[k] != '1')
		file[k] = '0';
}
