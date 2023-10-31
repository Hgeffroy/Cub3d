/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:58:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/23 14:50:49 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_close(t_game *g)
{
	int	i;

	i = 0;
	mlx_destroy_image(g->mlx, g->display.img);
	while (i < 4)
	{
		mlx_destroy_image(g->mlx, g->walls[i].img);
		i++;
	}
	mlx_destroy_window(g->mlx, g->win);
	free(g);
	exit (0);
}

int	init_game(t_game *g)
{
	g->player.fx = g->player.x + 0.5;
	g->player.fy = g->player.y + 0.5;
	init_minimap(g);
	init_walls(g);
	return (0);
}

int	display(t_game *g)
{
	draw_display(g);
	draw_minimap(g);
	mlx_put_image_to_window(g->mlx, g->win, g->display.img, 0, 0);
	mlx_string_put(g->mlx, g->win, \
			6 * TILE_SZ * cosf((-1) * g->player.angle + M_PI) + 7 * TILE_SZ, \
			6 * TILE_SZ * sinf((-1) * g->player.angle + M_PI) + 7 * TILE_SZ, \
			H_RED, "N");
	return (0);
}

int	mlx_play(t_game *g)
{
	if (g->movement.rotate_left)
		rotate_left(g, 10);
	if (g->movement.rotate_right)
		rotate_right(g, 10);
	if (g->movement.move_up)
		move_forward(g);
	if (g->movement.move_down)
		move_backward(g);
	if (g->movement.move_left)
		move_left(g);
	if (g->movement.move_right)
		move_right(g);
	display(g);
	return (0);
}

void	play(t_game *g)
{
	init_game(g);
	mlx_hook(g->win, 2, 1L << 0, &press_key, g);
	mlx_hook(g->win, 3, 1L << 1, &release_key, g);
	mlx_hook(g->win, 4, 1L << 2, &press_mouse, g);
	mlx_hook(g->win, 5, 1L << 3, &release_mouse, g);
	mlx_hook(g->win, 6, 1L << 6, &move_mouse, g);
	mlx_loop_hook(g->mlx, &mlx_play, g);
	mlx_loop(g->mlx);
}
