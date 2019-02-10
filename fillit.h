/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:56:15 by eagulov           #+#    #+#             */
/*   Updated: 2019/02/09 18:21:08 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_tetr
{
	char			letter;
	t_coord			*coords;
	struct s_tetr	*next;
}					t_tetr;

void				all_process(int	fd, char *buf, t_tetr *list);
void				check_and_write(int rest, char *buf, t_tetr **list, char c);
int					checker(char *buf);
int					cnt_symbols(char *buf);
int					check_symbols(char *buf);
int					check_hash(char *buf);
t_tetr				*add_lists(t_tetr *list, char *buf, char c);
void				get_tetrimino(t_tetr *list, char *buf);
void				get_coords(t_coord *first_hash, t_coord *coords, int *j,
																	int index);
void				fill_it(t_tetr *tetr, int cnt);
char				**create_map(int size);
int					solve(t_tetr *tetr, char **map, int storona);
int					load_tetrimino(t_tetr *t, char **map, t_coord m_c,
																int storona);
int					is_legal(t_tetr *t, t_coord m_c, int storona);
int					is_empty(t_tetr *t, char **map, t_coord m_c);
void				remove_tetrimino(t_tetr *t, char **map, t_coord m_c);
void				print_final_map(char **map);
void				free_map(char **map, int storona);

#endif
