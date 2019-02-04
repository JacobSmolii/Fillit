/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opener.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:44:18 by vsmolii           #+#    #+#             */
/*   Updated: 2019/02/03 11:55:03 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	opener(char *source, char *buffer) //char *sourse потому что в maine мы делаем char **av
{
	int		fd;
	int		nbr;//переменная int потому что фу-я read возвращает ко-во считанных символов
	//char	**str;//создаем двойной массив для фу-ии ft_strsplit(разбивает один массив на подмассивы)
	//char	letter;
	// int		index;
	t_tetr	*list;
	t_tetr	*tmp;

	//str = NULL;
	//letter = 'A';
	list = NULL;
	fd = open(source, O_RDONLY);
	while ((nbr = read(fd, buffer, 21)) > 0)//работа до конца файла(пока файл не закончится)
	{
		buffer[22] = '\0';
		// if (checker(buffer) == 1)
		list = add_list(list, buffer);
	}

	// list = cut_square(list);

	tmp = list;

	while(tmp)
	{
		cut_tetrimino(tmp);
		printf("[0]: x: %d y: %d, [1]: x: %d y: %d, [2]: x: %d y: %d, [3]: x: %d y: %d", tmp->massiv[0].x, tmp->massiv[0].y, tmp->massiv[1].x, tmp->massiv[1].y, tmp->massiv[2].x, tmp->massiv[2].y, tmp->massiv[3].x, tmp->massiv[3].y);
		printf("\n");
		tmp = tmp->next;


		// i = 0;
		// while (i < 4)
		// 	printf("%s\n", tmp->data[i++]);
		// printf("\n");
		// tmp = tmp->next;
	}

	close(fd);
}

int		main(int ac, char **av)
{
	char	buffer[22];
	opener(av[1], buffer);
	// checker(buffer);
	return (ac);
}

