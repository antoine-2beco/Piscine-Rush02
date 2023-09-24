/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:47:05 by lomajeru          #+#    #+#             */
/*   Updated: 2023/09/24 22:00:06 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_dict
{
	long long	nb;
	char		*value;
	int			len;
}	t_dict;

//parsing.c
int					nb_lines(char *buff);
char				*get_value(char *buff, int i, int k);
t_dict				*fill_dict(char *buff, int i, int k);
t_dict				*parsing(char *file_name);

// ft_utils.c
long long			ft_atoi_rush(char *str);
int					ft_strlen(char *str);
int					ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *src);
void				ft_putchar(char c);
int					ft_power(int nb, int power);
long long			ft_atoi_check(char *str);
void				ft_putstr(char *str);

//ft_error.c
int					ft_error(char *buff);
void				ft_free_dict(t_dict *dict, int k);

// convert_num.c
void				ft_print_nbr(long long nbr, t_dict *dict);

#endif