/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:20:19 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/05 10:20:19 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_create(t_root *root, char *filename)
{
	root->game = (t_game *)malloc(sizeof(t_game));
	if (root->game == 0)
		root_kill(root, "game_create(): malloc()", errno);
	root->game->map = 0;
	root->game->coll = 0;
	root->game->count_coll = 0;
	root->game->count_exit = 0;
	root->game->count_player = 0;
	root->game->player_move = 0;
	root->game->player_coll = 0;
	root->game->player_up = 0;
	root->game->player_down = 0;
	root->game->player_left = 0;
	root->game->player_right = 0;
	map_create(root, filename);
}

void	window_create(t_root *root)
{
	root->mlx = mlx_init();
	if (root->mlx == 0)
		root_kill(root, "mlx_create(): can't load mlx", 0);
	root->mlx_win = mlx_new_window(root->mlx, (root->game->width + 1) * 64,
			root->game->height * 64, "so_long");
	if (root->mlx_win == 0)
		root_kill(root, "mlx_new_window(): can't create a window", 0);
}

void	textures_create(t_root *root)
{
	texture_load(root, &root->player[0], "./xpm/char/char1.xpm");
	texture_load(root, &root->player[1], "./xpm/char/char2.xpm");
	texture_load(root, &root->player[2], "./xpm/char/char3.xpm");
	texture_load(root, &root->player[3], "./xpm/char/char4.xpm");
	texture_load(root, &root->exit, "./xpm/exit.xpm");
	texture_load(root, &root->coll, "./xpm/potion.xpm");
	texture_load(root, &root->wall, "./xpm/wall.xpm");
	texture_load(root, &root->ground, "./xpm/floor.xpm");
	texture_load(root, &root->side, "./xpm/side.xpm");
}

t_root	*root_create(char *filename)
{
	t_root	*root;

	root = (t_root *)malloc(sizeof(t_root));
	if (! root)
		root_kill(0, "root_create() : malloc()", errno);
	root->game = 0;
	root->mlx = 0;
	root->mlx_win = 0;
	*root->player = 0;
	root->exit = 0;
	root->coll = 0;
	root->wall = 0;
	root->ground = 0;
	game_create(root, filename);
	window_create(root);
	textures_create(root);
	return (root);
}

int	main(int argc, char **argv)
{
	t_root	*root;

	if (argc != 2)
		error_display("Invalid number of arguments passed", 0);
	if (filecheck(argv[1]))
		error_display("Invalid file passed, (<name>.ber) ", 0);
	root = root_create(argv[1]);
	draw_map(root);
	mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root);
	mlx_hook(root->mlx_win, 17, 1L << 17, kill_hook, root);
	mlx_loop_hook(root->mlx, char_disp, root);
	mlx_loop(root->mlx);
	return (0);
}
