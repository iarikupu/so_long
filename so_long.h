/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:25:28 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/14 09:34:37 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_game
{
	int		**map;
	int		height;
	int		width;
	t_coord	player;
	int		player_up;
	int		player_down;
	int		player_left;
	int		player_right;
	int		player_move;
	int		player_coll;
	t_coord	exit;
	t_coord	*coll;
	t_coord	*wolf;
	int		count_coll;
	int		t_wc;
	int		count_wolf;
	int		count_exit;
	int		count_player;
}	t_game;

typedef struct s_root
{
	void	*player[4];
	void	*exit;
	void	*coll;
	void	*wall;
	void	*ground;
	void	*side;
	void	*wolf;
	void	*mlx;
	void	*mlx_win;
	t_game	*game;
}	t_root;

void	game_create(t_root *root, char *filename);
void	window_create(t_root *root);
void	textures_create(t_root *root);
t_root	*root_create(char *filename);
void	had_move(t_root *root, int x, int y);
void	iscollectable(t_root *root);
void	update(t_root *root);
void	get_coord(t_root *root, char *file, int k, int *obj);
void	move_up(t_root *root, int x, int y);
void	move_down(t_root *root, int x, int y);
void	move_left(t_root *root, int x, int y);
void	move_right(t_root *root, int x, int y);
void	map_create(t_root *root, char *filename);
void	map_read(t_root *root, char *file);
void	map_height(t_root *root, char *file);
void	map_parsing(t_root *root, char *file);
void	map_width(t_root *root, char *file);
void	free_the_matrix(t_root *root, char *file, int **m, int size);
void	error_display(char *errm, int errn);
void	game_kill(t_game *game);
void	root_kill(t_root *root, char *errmsg, int errnum);
int		key_press(int keycode, t_root *root);
int		kill_hook(int keycode, t_root *root);
void	file_parse(t_root *root, char **file, char buf[], int fd);
void	file_read(t_root *root, char **file, char buf[], int fd);
char	*file_create(t_root *root, int fd);
void	texture_load(t_root *root, void **img, char *path);
void	add_stuff(t_root *root, int i, int j);
void	draw_map(t_root *root);
int		isborder(t_root *root, int i);
void	isvalid(t_root *root, char *file, int i);
void	map_check(t_root *root, char *file);
int		filecheck(char *file);
int		char_display(t_root root);
int		char_disp(t_root *root);
void	iswolf(t_root *root);
int	not_wolf(t_root *root, int n, int m);

#endif
