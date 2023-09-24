/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:10:16 by lomajeru          #+#    #+#             */
/*   Updated: 2023/09/24 19:39:51 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_error(char *buff)
{
	if (buff)
		free(buff);
	write(2, "Dict Error\n", sizeof("Dict Error\n"));
	return (0);
}

void	ft_free_dict(t_dict *dict, int k)
{
	if (k == 0)
	{
		while (k < dict[0].len)
		{
			dict[k].value = NULL;
			free(dict[k++].value);
		}
	}
	else
	{
		while (k-- >= 0)
			free(dict[k].value);
		free(dict);
	}
}
