/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:29:13 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/13 10:57:37 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_root *root, int x, int y)
{
	root->game->player_up = 0;
	if (root->game->exit.x == root->game->player.x
		&& root->game->exit.y == root->game->player.y - 1)
		if (root->game->count_coll != root->game->player_coll)
			return ;
	if (root->game->map[y - 1][x] == 0)
		root->game->player.y -= 1;
}

void	move_down(t_root *root, int x, int y)
{
	root->game->player_down = 0;
	if (root->game->exit.x == root->game->player.x
		&& root->game->exit.y == root->game->player.y + 1)
		if (root->game->count_coll != root->game->player_coll)
			return ;
	if (root->game->map[y + 1][x] == 0)
		root->game->player.y += 1;
}

void	move_left(t_root *root, int x, int y)
{
	root->game->player_left = 0;
	if (root->game->exit.x == root->game->player.x - 1
		&& root->game->exit.y == root->game->player.y)
		if (root->game->count_coll != root->game->player_coll)
			return ;
	if (root->game->map[y][x - 1] == 0)
		root->game->player.x -= 1;
}

void	move_right(t_root *root, int x, int y)
{
	root->game->player_right = 0;
	if (root->game->exit.x == root->game->player.x + 1
		&& root->game->exit.y == root->game->player.y)
		if (root->game->count_coll != root->game->player_coll)
			return ;
	if (root->game->map[y][x + 1] == 0)
		root->game->player.x += 1;
}
