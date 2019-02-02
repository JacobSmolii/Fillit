/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:41:27 by vsmolii           #+#    #+#             */
/*   Updated: 2019/02/02 15:42:47 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_map(char *buffer)
{
	int i;

	i = 0;
	while (buffer != '\0')//проверка на корректность символов
	{
		if (buffer[i] != '.' && buffer[i] != '#' && buffer[i] != '\n')
			return (-1);
		i++;
	}
	return (1);
}

int		check_cnt_symb(char *buffer)
{
	int i;
	int cnt_hash;
	int cnt_dots;

	i = 0;
	cnt_hash = 0;
	cnt_dots = 0;
	if (buffer[4] != '\n' && buffer[9] != '\n' && buffer[14] != '\n' &&//проверка \n на определенной позиции
		buffer[19] != '\n' && buffer[20] != '\n')
		return (-1);
	while (buffer[i] != '\0')//проверка на соответствующее ко-во точек и хешей
	{
		if (buffer[i] == '#')
			cnt_hash++;
		else if (buffer[i] == '.')
			cnt_dots++;
		i++;
	}
	if (cnt_hash != 4 && cnt_dots != 12)//проверка на ко-во четырех # и ко-во 12 точек
		return (-1);
	return (1);
}



int		check_hash(char *buffer)//проверка на соседство #
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < 21)//21 потому что наша карта состоит из 21 символа
	{
		if (buffer[i] == '#')
		{
			if (buffer[i + 1] == '#')//проверяет # справа соответствующей строки
				count++;
			if (buffer[i - 1] == '#')//проверяет # слева
				count++;
			if (buffer[i + 5] = '#')//проверяет # ниже [i + 5] и [i - 5] потому что мы работаем в одномерном массиве(одной строке)
				count++;
			if (buffer[i - 5] = '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (-1);
}

int		checker(char *buffer)//фу-я проверяет на валидность других фу-ий (с помощью этой фу-ии можно проверить на валидность других фу-ий)
{
	if (check_cnt_symb(buffer) == -1 || check_map(buffer) == -1 || check_hash(buffer))
		return (-1);
	return (1);
}



t_tetr	*cut_square(t_tetr *lists)//фу-я(алгоритм) решения(находит наш квадрат с # и записывает координаты этого квадрата)
{
	t_tetr	list;
	t_tetr	new;
	int i;

	i = 0;


	list->min.x = 6;// 6 и -1 это нереальные, невозможные(идеальные) значения для алгометрического решения этой(данной) задачи
	list->max.x = -1;
	list->min.y = 6;
	list->max.y = -1;
	while (buffer[i] != '\0')
	{
		if (i == '#')
		{
			if (list->min.x > i % 5)// 5 потому что у нас в строке 5 символов, и таким образом может
				list->min.x = i % 5;//найти # в соответствующей строке по (x координате) и по (y координате)
			if (list->max.x < i % 5)
				list->max.x = i % 5;
			if (list->min.y > i / 5)
				list->min.y = i / 5;
			if (list->max.y < i / 5)
				list->max.y = i / 5;
		}
		i++;
	}
	new = add_list(new, list->min.x, list->min.y, list->max.x, list->max.y);
	return (new);
}


// t_tetr	*add_list(t_tetr *list, list->min.x, list->min.y, list->max.x, list->max.y)//фу-я которая выделяет память под наши координаты
// {
// 	t_tetr	heigh;
// 	t_tetr	width;
// 	int i;

// 	i = 0;
// 	heigh = (list->max.y - list->min.y + 1);
// 	width = (list->max.x - list->min.x + 1);
// 	list->data = (t_tetr *)malloc(sizeof(t_tetr) * heigh);
// 	while (i < heigh)
// 	{
// 		list->data = (t_tetr *)malloc(sizeof(t_tetr *) * width)
// 		i++;
// 	}

// }







