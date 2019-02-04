/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:00:10 by vsmolii           #+#    #+#             */
/*   Updated: 2019/02/03 14:30:03 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		*add_list(t_tetr *list, char *buffer)
{
	t_tetr	*new;
	t_tetr	*tmp;

	if (list == NULL)//только при первом прохождение. Проверяем аргумент, если аргум плохой то мы его создаем с нуля(нулевой узел)
	{
		new = (t_tetr *)malloc(sizeof(t_tetr));
		new->data = ft_strdup(buffer);
		new->next = NULL;
		new->change_symbol = 'A';
		return (new);
	}
	tmp = list;//записываем нулевой индекс узла, для того чтобы потом вернуться на начало(для показа всех узлов)
	new = (t_tetr *)malloc(sizeof(t_tetr));
	new->data = ft_strdup(buffer);
	new->next = NULL;
	while (list->next)//прохождение по листу(пока лист существует)
		list = list->next;//перезаписывание листа
	new->change_symbol = list->change_symbol + 1;
	list->next = new;//добавление нового листа в конец линка
	return (tmp);//возвращаем pointer на начало наших листов
}

void	get_coords(t_coord *first_hash, t_coord *massiv, int *j, int i)
{
	if (first_hash->x == 6 && first_hash->y == 6)//заходит сюда только первый раз, остальные разы идет в else
	{
		first_hash->x = i % 5;//перезаписывает координату найденного # по х
		first_hash->y = i / 5;//перезаписывает координату найденного # по у
		massiv[*j].x = 0;//устанавливает новую позицию по х для нашего первого #(новая карта с #) ; x(#-№1): 0 y(#-№1): 0
		massiv[*j].y = 0;//.х мы используем только тогда когда мы работаем с адресом(смт. подсказку№1)
	}
	else
	{
		massiv[*j].x = (i % 5) - first_hash->x;//алгоритм для установления новых координат нашим # в massiv[j]
		massiv[*j].y = (i / 5) - first_hash->y;
	}
	(*j)++;
}


void	cut_tetrimino(t_tetr *list)
{
	int		i;//переменная для итерации по нашей карте(тетрамино)
	int		j;// -|- по нашему massiv в котором будут находиться наши #
	t_coord	*first_hash;//локальная структура
	t_coord *massiv;// структура куда будут записаны наши найденные #(маленькая карта)

	i = 0;
	j = 0;
	first_hash = (t_coord *)malloc(sizeof(t_coord));
	massiv = (t_coord *)malloc(sizeof(t_coord) * 4);//выделяем память только под наши 4 #, которые найдем
	first_hash->x = 6;
	first_hash->y = 6;
	while (list->data[i++])//поэлементная итерация нашего листа(list->data, потому что мы записываем наши листы в фу-ии add_list)
		if (list->data[i] == '#')
			get_coords(first_hash, massiv, &j, i);
	list->massiv = massiv;
}


/*
	Подсказка № 1:
	Для доступа к членам структуры с помощью указателя на структуру следует использовать оператор "стрелка"
	Оператор «точка» используется при обращении собственно к структуре или объединению напрямую. Оператор -> используется при наличии указателя на структуру или объединение.
*/
