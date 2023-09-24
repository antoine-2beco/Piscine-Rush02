/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:10:16 by lomajeru          #+#    #+#             */
/*   Updated: 2023/09/24 16:53:16 by lomajeru         ###   ########.fr       */
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
	dict = NULL;
	if (k == 0)
	{
		while(dict[k].value)
			free(dict[k++].value);
	}
	else
	{
		while (k >= 0)
			free(dict[k--].value);
		free(dict);
	}
}
