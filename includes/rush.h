/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:47:05 by lomajeru          #+#    #+#             */
/*   Updated: 2023/09/24 16:44:38 by lomajeru         ###   ########.fr       */
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
	int		nb;
	char	*value;
	char	*num;
	int		index;
}	t_dict;

//rush02.c

//parsing.c
int					nb_lines(char *buff);
char				*get_value(char *buff);
t_dict				*fill_dict(char *buff);
t_dict				*parsing(char *file_name);

// ft_utils.c
int					ft_atoi_rush(char *str);
int					ft_strlen(char *str);
int					ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *src);
void				ft_putchar(char c);
int					ft_power(int nb, int power);
long long			ft_atoi_check(char *str);


//ft_error.c
int					ft_error(char *buff);
void				ft_free_dict(t_dict *dict, int k);

// convert_num.c
int					num_spell(char *num, t_dict *dict);
void				init_temp(int *temp);
void				convert_num(int *num, t_dict *dict);
void				print_num(int num, t_dict *dict);


#endif