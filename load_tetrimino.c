/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:18:24 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/09 12:43:42 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_legal(t_tetr *t, t_coord m_c, int storona)
{
	if (m_c.x + t->coords[1].x < 0 || m_c.y + t->coords[1].y < 0)
		return (1);
	if (m_c.x + t->coords[2].x < 0 || m_c.y + t->coords[2].y < 0)
		return (1);
	if (m_c.x + t->coords[3].x < 0 || m_c.y + t->coords[3].y < 0)
		return (1);
	if (m_c.x + t->coords[1].x > (storona - 1) ||
									m_c.y + t->coords[1].y > (storona - 1))
		return (1);
	if (m_c.x + t->coords[2].x > (storona - 1) ||
									m_c.y + t->coords[2].y > (storona - 1))
		return (1);
	if (m_c.x + t->coords[3].x > (storona - 1) ||
									m_c.y + t->coords[3].y > (storona - 1))
		return (1);
	return (0);
}

int		is_empty(t_tetr *t, char **map, t_coord m_c)
{
	if (map[m_c.y][m_c.x] != '.')
		return (1);
	if (map[(m_c.y + t->coords[1].y)][(m_c.x + t->coords[1].x)] != '.')
		return (1);
	if (map[(m_c.y + t->coords[2].y)][(m_c.x + t->coords[2].x)] != '.')
		return (1);
	if (map[(m_c.y + t->coords[3].y)][(m_c.x + t->coords[3].x)] != '.')
		return (1);
	return (0);
}

int		load_tetrimino(t_tetr *t, char **map, t_coord m_c, int storona)
{
	if (is_legal(t, m_c, storona) == 1)
		return (0);
	else if (is_empty(t, map, m_c) == 1)
		return (0);
	else
	{
		map[m_c.y][m_c.x] = t->letter;
		map[(m_c.y + t->coords[1].y)][(m_c.x + t->coords[1].x)] = t->letter;
		map[(m_c.y + t->coords[2].y)][(m_c.x + t->coords[2].x)] = t->letter;
		map[(m_c.y + t->coords[3].y)][(m_c.x + t->coords[3].x)] = t->letter;
	}
	return (1);
}

void	remove_tetrimino(t_tetr *t, char **map, t_coord m_c)
{
	map[m_c.y][m_c.x] = '.';
	map[(m_c.y + t->coords[1].y)][(m_c.x + t->coords[1].x)] = '.';
	map[(m_c.y + t->coords[2].y)][(m_c.x + t->coords[2].x)] = '.';
	map[(m_c.y + t->coords[3].y)][(m_c.x + t->coords[3].x)] = '.';
}
