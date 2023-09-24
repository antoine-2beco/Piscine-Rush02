/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:05:26 by hle-roi           #+#    #+#             */
/*   Updated: 2023/09/24 17:17:31 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print_num(int num, t_dict *dict)
{
	int	k;
	int i;

	k = 0;
	while (dict[k].nb != num)
		k++;
	i = 0;
	while (dict[k].value[i])
		ft_putchar(dict[k].value[i++]);
	if (ft_strlen(dict[0].num) == dict[0].index - 1)
		return ;
	ft_putchar(' ');
}

void	convert_num(int *num, t_dict *dict)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (3 - i == 1 && num[i] != 0)
		{
			print_num(num[i], dict);	
		}
		if (3 - i == 2 && num[i] != 0)
		{
			if (num[i] < 2)
			{
				print_num(num[i] * 10 + num[i + 1], dict);
				break ;
			}
			else
				print_num(num[i] * 10, dict);
		}
		if (3 - i == 3 && num[i] != 0)
		{
			print_num(num[i], dict);
			print_num(100, dict);
		}
		dict[0].index++;
		i++;
	}
}

void	init_temp(int *temp)
{
	int i;

	i = -1;
	while (++i < 3)
		temp[i] = 0;
}

int	num_spell(char *num, t_dict *dict)
{
	int	i;
	int	index;
	int	*temp;
	int	count;

	dict[0].num = num;
	temp = malloc(3 * sizeof(int));
	if (!temp)
		return (ft_free_dict(dict, 0), 0);
	count = ft_strlen(num) % 3;
	if (count == 2)
		count = 1;
	else if (count == 1)
		count = 2;
	i = 0;
	init_temp(temp);
	index = 0;
	while (num[i])
	{
		temp[count] = num[i] - 48;
		count++;
		if (count == 3 || num[i + 1] == 0)
		{
			dict[0].index = i;
			convert_num(temp, dict);
			init_temp(temp);
			index++;
			if (num[i + 1] != 0)
			{
				print_num(ft_power(1000, ft_strlen(num) / 3 - index), dict);
			}
			count = 0;
		}
		i++;
	}
	free(temp);
	return (0);
}
