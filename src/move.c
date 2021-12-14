/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:29:13 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/14 09:34:19 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_root *root, int x, int y)
{
	int	k;

	root->game->player_up = 0;
	if (root->game->exit.x == root->game->player.x
		&& root->game->exit.y == root->game->player.y - 1)
		if (root->game->count_coll != root->game->player_coll)
			return ;
	k = -1;
	while (++k < root->game->count_wolf)
		if (root->game->map[root->game->wolf[k].y - 1]
			[root->game->wolf[k].x] == 0 && not_wolf(root, k, 1))
			root->game->wolf[k].y -= 1;
	if (root->game->map[y - 1][x] == 0)
		root->game->player.y -= 1;
}

void	move_down(t_root *root, int x, int y)
{
	int	k;

	root->game->player_down = 0;
	if (root->game->exit.x == root->game->player.x
		&& root->game->exit.y == root->game->player.y + 1)
		if (root->game->count_coll != root->game->player_coll)
			return ;
	k = -1;
	while (++k < root->game->count_wolf)
		if (root->game->map[root->game->wolf[k].y + 1]
			[root->game->wolf[k].x] == 0 && not_wolf(root, k, 2))
			root->game->wolf[k].y += 1;
	if (root->game->map[y + 1][x] == 0)
		root->game->player.y += 1;
}

void	move_left(t_root *root, int x, int y)
{
	int	k;

	root->game->player_left = 0;
	if (root->game->exit.x == root->game->player.x - 1
		&& root->game->exit.y == root->game->player.y)
		if (root->game->count_coll != root->game->player_coll)
			return ;
	k = -1;
	while (++k < root->game->count_wolf)
		if (root->game->map[root->game->wolf[k].y]
			[root->game->wolf[k].x - 1] == 0 && not_wolf(root, k, 3))
			root->game->wolf[k].x -= 1;
	if (root->game->map[y][x - 1] == 0)
		root->game->player.x -= 1;
}

void	move_right(t_root *root, int x, int y)
{
	int	k;

	root->game->player_right = 0;
	if (root->game->exit.x == root->game->player.x + 1
		&& root->game->exit.y == root->game->player.y)
		if (root->game->count_coll != root->game->player_coll)
			return ;
	k = -1;
	while (++k < root->game->count_wolf)
		if (root->game->map[root->game->wolf[k].y]
			[root->game->wolf[k].x + 1] == 0 && not_wolf(root, k, 4))
			root->game->wolf[k].x += 1;
	if (root->game->map[y][x + 1] == 0)
		root->game->player.x += 1;
}

int	not_wolf(t_root *root, int n, int m)
{
	int	k;

	k = -1;
	while (k < root->game->count_wolf)
	{
		if(m == 1 && root->game->wolf[k].y == root->game->wolf[n].y - 1 
				&& root->game->wolf[k].x == root->game->wolf[n].x)
				return (0);
		else if(m == 2 && root->game->wolf[k].y == root->game->wolf[n].y + 1 
				&& root->game->wolf[k].x == root->game->wolf[n].x)
				return (0);
		else if(m == 3 && root->game->wolf[k].y == root->game->wolf[n].y
				&& root->game->wolf[k].x == root->game->wolf[n].x - 1)
				return (0);
		else if(m == 4 && root->game->wolf[k].y == root->game->wolf[n].y
				&& root->game->wolf[k].x == root->game->wolf[n].x + 1)
				return (0);
		k++;
	}
	return (1);
}
