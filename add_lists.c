/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:00 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/10 12:18:04 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_coords(t_coord *first_hash, t_coord *coords, int *j, int index)
{
	if (first_hash->x == 6 && first_hash->y == 6)/* заходит сюда только первый раз, остальные разы идет в else */
	{
		first_hash->x = index % 5;/* перезаписывает координату найденного # по х */
		first_hash->y = index / 5;/* перезаписывает координату найденного # по у */
		coords[*j].x = 0;/* устанавливает новую позицию по х для нашего первого #(новая карта с #) ; x(#-№1): 0 y(#-№1): 0 */
		coords[*j].y = 0;/* .х мы используем только тогда когда мы работаем с адресом(смт. подсказку№1) */
	}
	else
	{
		coords[*j].x = (index % 5) - first_hash->x;/* алгоритм для установления новых координат нашим # в massiv[j] */
		coords[*j].y = (index / 5) - first_hash->y;
	}
	(*j)++;
}

void	get_tetrimino(t_tetr *new, char *buf)
{
	int		index;/* переменная для итерации по нашей карте(тетрамино) */
	int		j;/*  -|- по нашему massiv в котором будут находиться наши # */
	t_coord	*first_hash;/* локальная структура */
	t_coord	*coords;/*  структура куда будут записаны наши найденные #(маленькая карта) */

	index = 0;
	j = 0;
	first_hash = (t_coord *)malloc(sizeof(t_coord));
	coords = (t_coord *)malloc(sizeof(t_coord) * 4);/* выделяем память только под наши 4 #, которые найдем */
	first_hash->x = 6;
	first_hash->y = 6;
	while (buf[index])
	{
		if (buf[index] == '#')
			get_coords(first_hash, coords, &j, index);
		++index;
	}
	new->coords = coords;
	free(first_hash);
}

t_tetr	*add_lists(t_tetr *list, char *buf, char c)
{
	t_tetr	*new;
	t_tetr	*tmp;

	if (list == NULL)/* только при первом прохождение. Проверяем аргумент, если аргум плохой то мы его создаем с нуля(нулевой узел) */
	{
		new = (t_tetr *)malloc(sizeof(t_tetr));
		get_tetrimino(new, buf);
		new->next = NULL;
		new->letter = c;
		return (new);
	}
	tmp = list;/* записываем нулевой индекс узла, для того чтобы потом вернуться на начало(для показа всех узлов) */
	new = (t_tetr *)malloc(sizeof(t_tetr));
	get_tetrimino(new, buf);
	new->next = NULL;
	while (list->next)/* прохождение по листу(пока лист существует) */
		list = list->next;
	new->letter = c;
	list->next = new;/* добавление нового листа в конец линка */
	return (tmp);/* возвращаем pointer на начало наших листов */
}


/*
Подсказка №1:
Оператор . «точка» и оператор -> «стрелка» используются для обращения к отдельным элементах структур и объединений.
Структуры и объединения объединяют типы данных под одним именем.

Оператор «точка» используется при обращении собственно к структуре или объединению напрямую.
Оператор -> используется при наличии указателя на структуру или объединение.
*/
