/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:55:41 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 16:54:21 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "cub3D.h"

void	init_minimap(t_data *cub);
void	draw_minimap(t_data *cub);
float	minimap_ray(t_data *cub, float angle);
float	raycasting(t_data *cub, float angle);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		draw_display(t_data *cub);
void	init_col(t_data *cub, t_wallray *wallray);
int		get_color(t_walltext w, int x, int y);
void	get_wall_color(t_data *cub, t_wallray *wallray);

typedef	void	(*t_init_col)(t_data *cub, t_wallray *wallray);
typedef void	(*t_wall_color)(t_data *cub, t_wallray *wallray);

#endif