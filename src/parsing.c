/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:32:17 by lomajeru          #+#    #+#             */
/*   Updated: 2023/09/24 22:46:53 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	nb_lines(char *buff)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buff[i])
	{
		while (buff[i] == '\n')
			i++;
		while (buff[i] && buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
		{
			count++;
			while (buff[i] == '\n')
				i++;
		}
	}
	return (count);
}

char	*get_value(char *buff, int i, int k)
{
	char	*tmp;
	char	*value;

	while (buff[i] && buff[i] != '\n')
		i++;
	tmp = malloc(i + 1);
	if (!tmp || buff[0] == '\n' || buff[0] == '\0')
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		if (i != 0)
			tmp[k++] = ' ';
		while (buff[i] == ' ')
			i++;
		while (buff[i] && buff[i] != '\n' && buff[i] != ' ')
			tmp[k++] = buff[i++];
		while (buff[i] == ' ')
			i++;
	}
	tmp[k] = '\0';
	value = ft_strdup(tmp);
	free(tmp);
	return (value);
}

t_dict	*fill_dict(char *buff, int i, int k)
{
	t_dict	*dict;

	dict = malloc((nb_lines(buff) + 1) * sizeof(t_dict));
	while (buff[i])
	{
		while (buff[i] == '\n')
			i++;
		dict[k].nb = ft_atoi_rush(buff + i);
		while (buff[i] >= '0' && buff[i] <= '9')
			i++;
		while (buff[i] == ' ')
			i++;
		if (buff[i++] != ':')
			return (ft_free_dict(dict, k), ft_error(buff), NULL);
		dict[k].value = get_value(buff + i, 0, 0);
		if (!dict[k].value || dict[k].nb < 0)
			return (ft_free_dict(dict, k), ft_error(buff), NULL);
		while (buff[i] && buff[i] != '\n')
			i++;
		while (buff[i] == '\n')
			i++;
		k++;
	}
	dict[0].len = k;
	return (dict);
}

t_dict	*parsing(char *file_name)
{
	int		len_file;
	int		fd;
	char	*buff;
	char	c;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_error(NULL), NULL);
	len_file = 0;
	while (read(fd, &c, 1))
		len_file++;
	close(fd);
	buff = malloc(len_file + 1);
	if (!buff)
		return (ft_error(NULL), NULL);
	fd = open(file_name, O_RDONLY);
	read(fd, buff, len_file);
	buff[len_file] = '\0';
	close(fd);
	return (fill_dict(buff, 0, 0));
}
