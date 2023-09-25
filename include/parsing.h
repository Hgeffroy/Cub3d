/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:07:26 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/25 15:27:41 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef struct s_player
{
	int	x;
	int	y;
	int	dir[2]; // Coordonnees du vecteur
}	t_player;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_textures;

typedef struct s_colors
{
	char	*rgb_floor;
	char	*rgb_roof;
	char	*hexa_floor;
	char	*hexa_roof;
}	t_colors;

typedef struct s_map
{
	char	**map;
	int		*mapsize;
}	t_map;

typedef struct s_game
{
	int				*mapsize;
	t_map			*smap;
	t_textures		*textures;
	t_colors		*colors;
	t_player		*player;
}	t_game;

t_game	*parsing(char *file);
int		get_textures(t_game **g, int fd);
int		is_mapline(char *line);
int		check_file(char *file);
t_map	*get_map(char *file);
void	print_parsing(t_game *g);

#endif

