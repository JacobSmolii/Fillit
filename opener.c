/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opener.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:44:18 by vsmolii           #+#    #+#             */
/*   Updated: 2019/02/02 15:42:47 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	opener(char *source, char *buffer) //char *sourse потому что в maine мы делаем char **av
{
	int		fd;
	int		nbr;//переменная int потому что фу-я read возвращает ко-во считанных символов
	//char	**str;//создаем двойной массив для фу-ии ft_strsplit(разбивает один массив на подмассивы)
	//char	letter;
	int		index;
	t_tetr	*list;
	t_tetr	*tmp;

	//str = NULL;
	//letter = 'A';
	list = NULL;
	fd = open(source, O_RDONLY);
	while ((nbr = read(fd, buffer, 21)) > 0)//работа до конца файла(пока файл не закончится)
	{
		buffer[22] = '\0';
		list = add_list(list, buffer);

		list = cut_square(list);
	}
	// tmp = list;
	// int i;
	// while(tmp)
	// {
	// 	i = 0;
	// 	while (i < 4)
	// 		printf("%s\n", tmp->data[i++]);
	// 	printf("\n");
	// 	tmp = tmp->next;
	// }
	close(fd);
}

int		main(int ac, char **av)
{
	char	buffer[22];
	opener(av[1], buffer);
	checker(buffer);
	return (ac);
}

t_tetr		*add_list(t_tetr *list, char **buffer)
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
	list->next = new;//добавление нового листа в конец линка
	return (tmp);//возвращаем pointer на начало наших листов
}


t_tetr		*parse(char **array, char letter)
{
	char	arr[4][4];
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{

			x++;
		}
		y++;
	}
}
