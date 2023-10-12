/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:51:36 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/12 09:00:50 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_col_n(t_game *g, t_wallray *wallray)
{
	wallray->x_impact = g->ray.impact[0] * g->walls[NORTH].width;
	wallray->y_impact = g->ray.impact[1] * g->walls[NORTH].width;
	wallray->y_ratio = g->walls[NORTH].height / wallray->height;
}

void	init_col_s(t_game *g, t_wallray *wallray)
{
	wallray->x_impact = g->ray.impact[0] * g->walls[SOUTH].width;
	wallray->y_impact = g->ray.impact[1] * g->walls[SOUTH].width;
	wallray->y_ratio = g->walls[SOUTH].height / wallray->height;
}

void	init_col_w(t_game *g, t_wallray *wallray)
{
	wallray->x_impact = g->ray.impact[0] * g->walls[WEST].width;
	wallray->y_impact = g->ray.impact[1] * g->walls[WEST].width;
	wallray->y_ratio = g->walls[WEST].height / wallray->height;
}

void	init_col_e(t_game *g, t_wallray *wallray)
{
	wallray->x_impact = g->ray.impact[0] * g->walls[EAST].width;
	wallray->y_impact = g->ray.impact[1] * g->walls[EAST].width;
	wallray->y_ratio = g->walls[EAST].height / wallray->height;
}

void	init_col(t_game *g, t_wallray *wallray)
{
	const t_init_col	tab[] = {&init_col_n, &init_col_s, &init_col_w, \
								&init_col_w};
								
	(*tab[g->ray.wall_found])(g, wallray);
}