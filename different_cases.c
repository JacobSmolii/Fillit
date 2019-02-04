/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   different_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:29:03 by vsmolii           #+#    #+#             */
/*   Updated: 2019/02/03 10:33:16 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_tetr	*cut_square(t_tetr *lists)//фу-я(алгоритм) решения(находит наш квадрат с # и записывает координаты этого квадрата)
{
	t_tetr	*list;
	t_tetr	*new;
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
