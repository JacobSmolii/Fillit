/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:09:21 by vsmolii           #+#    #+#             */
/*   Updated: 2019/02/02 14:37:18 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 21

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_tetr
{
	char			**data;
	char			change_symbol;
	t_coord			min;
	t_coord			max;
	struct s_tetr	*next;
}				t_tetr;

// typedef struct tetr//название структуры
// {
// 	char			**data;
// 	char			change_symbol;
// 	int				x;
// 	int				y;
// 	int				x_mn;
// 	int				x_mx;
// 	int				y_mn;
// 	int				y_mx;
// 	struct tetr		*next;
// }				t_tetr;//переменная структуры

int		check_map(char *buffer);
int		check_cnt_symb(char *buffer);
int		checker(char *buffer);
void	opener(char *source, char *buffer);

t_tetr		*add_list(t_tetr *list, char **buffer);
t_tetr	*cut_square(t_tetr *list);


# endif
