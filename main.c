/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:45:20 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/10 12:26:35 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_tetr *list)
{
	t_tetr *tmp;

	while (list)
	{
		tmp = list->next;
		free((void *)list->coords);
		free(list);
		list = tmp;
	}
}

void	check_and_write(int rest, char *buf, t_tetr **list, char c)
{
	if (rest == 20)
		buf[20] = '\n';
	buf[21] = '\0';/* всегда должны ставить '\0' после определенного считывания символов(закрыть контейнер так сказать), чтобы не было ликов  */
	if (checker(buf) == 1)
		*list = add_lists(*list, buf, c);
	else
		exit(write(1, "error\n", 6) ? 0 : 0);
}

void	all_process(int fd, char *buf, t_tetr *list)
{
	int		rest;/* переменная int потому что фу-я read возвращает ко-во считанных символов */
	int		old_rest;/* переменная которая в последний раз покажет \n, так как мы считываем по 21 символу, то есть предпоследний символ \n, или наша последняя тетрамино не должна заканчиваться \n */
	int		cnt;/* для счета ко-во листов */
	char	c;

	old_rest = 0;
	c = 'A';
	cnt = 0;
	while ((rest = read(fd, buf, 21)))/* работа до конца файла(пока файл не закончится), когда фу-ия read дойдет до конца файла , то она должна вернуть 0(типо прочитало все) */
	{
		check_and_write(rest, buf, &list, c);
		cnt++;
		c++;
		old_rest = rest;
	}
	close(fd);
	if (rest != 0 || old_rest != 20)
		exit(write(1, "error\n", 6) ? 0 : 0);
	fill_it(list, cnt);
	free_list(list);
}

int		main(int argc, char **argv)
{
	char	buf[22];
	int		fd;
	t_tetr	*list;

	list = NULL;
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		exit(write(1, "error\n", 6) ? 0 : 0);/* 0 и 0 потому что exit должен возврвщать число */
	all_process(fd, buf, list);				/* (в нашем случае вернет число 6 то есть error\n). */
	return (argc);							/* Если не сработает фу-я open, то нам выдаст error\n  */
}

/*
Для проверки на leaks мы должны вставить ( while (1){} ) перед нашим return (argc), для запуска вечного цикла,
в этот момент открываем терминал и вбиваем команду leaks и название нашего файла компилятора(в нашем случае fillit)
*/
