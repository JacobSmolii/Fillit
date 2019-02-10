/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:39:22 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/10 12:29:23 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_final_map(char **map)/* печатает финальный вид карты */
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		++i;
	}
}

char	**create_map(int storona)/* создает карту и заполняет ее точками */
{
	char	**map;
	int		i;
	int		j;

	map = (char **)ft_memalloc(sizeof(char *) * storona + 1);
	i = 0;
	while (i < storona)
	{
		map[i] = ft_strnew(storona + 1);
		j = 0;
		while (j < storona)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	free_map(char **map, int storona)
{
	int i;

	i = 0;
	while (i < storona)
	{
		ft_memdel((void **)&(map[i]));
		i++;
	}
	ft_memdel((void **)&map);
}

int		solve(t_tetr *tetr, char **map, int storona)
{
	t_coord	m_c;

	if (tetr == NULL)
		return (1);
	m_c.y = 0;
	while (m_c.y < storona)
	{
		m_c.x = 0;
		while (m_c.x < storona)
		{
			if (load_tetrimino(tetr, map, m_c, storona))
			{
				if (solve(tetr->next, map, storona))
					return (1);
				else
					remove_tetrimino(tetr, map, m_c);
			}
			++m_c.x;
		}
		++m_c.y;
	}
	return (0);
}

void	fill_it(t_tetr *tetr, int cnt)
{
	char	**map;
	int		storona;
	t_tetr	*tmp;

	tmp = tetr;
	storona = my_sqrt(cnt * 4);
	map = create_map(storona);
	while (!solve(tetr, map, storona))
	{
		free_map(map, storona);
		++storona;
		map = create_map(storona);
	}
	print_final_map(map);
	free_map(map, storona);
}
