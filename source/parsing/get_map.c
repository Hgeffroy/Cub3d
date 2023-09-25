/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:04:00 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/25 15:26:56 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*go_to_map(int fd)
{
	char *line;
	
	line = NULL;
	while (is_mapline(line) == NO)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	return (line);
}

t_map	*malloc_map(t_map *smap, char *file)
{
	int		fd;
	int		mapsz;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = go_to_map(fd);
	mapsz = 1;
	while (is_mapline(line) == YES)
	{
		if (line)
			free(line);
		mapsz++;
		line = get_next_line(fd);
	}
	smap->map = (char **)malloc(sizeof(char *) * (mapsz + 1));
	if (!smap->map)
		return (NULL);
	smap->mapsize = (int *)malloc(sizeof(char *) * mapsz);
	if (!smap->mapsize)
		return (NULL);
	close (fd);
	return (smap);
}

t_map	*fill_map(t_map *smap, char *line, int fd)
{
	int	i;
	
	i = 0;
	while (is_mapline(line) == YES)
	{
		smap->map[i] = line;
		smap->mapsize[i] = ft_strlen(line);
		line = get_next_line(fd);
		i++;
	}
	smap->map[i] = NULL;
	if (line)
		free(line);
	return (smap);
}

t_map	*get_map(char *file)
{
	t_map	*smap;
	int		fd;
	char	*line;

	smap = (t_map *)malloc(sizeof(t_map));
	if (!smap)
		return (NULL);
	smap = malloc_map(smap, file);
	if (!smap)
		return(NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = NULL;
	line = go_to_map(fd);
	smap = fill_map(smap, line, fd);
	if (!smap)
		return (NULL);
	close(fd);	
	return (smap);
}