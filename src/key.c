/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:23:06 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/14 07:17:57 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, t_root *root)
{
	if (keycode == 53)
		root_kill(root, 0, 0);
	if (keycode == 13)
		root->game->player_up = 1;
	if (keycode == 1)
		root->game->player_down = 1;
	if (keycode == 0)
		root->game->player_left = 1;
	if (keycode == 2)
		root->game->player_right = 1;
	update(root);
	return (0);
}

int	kill_hook(int keycode, t_root *root)
{
	(void)keycode;
	(void)root;
	root_kill(0, 0, 0);
	return (0);
}
