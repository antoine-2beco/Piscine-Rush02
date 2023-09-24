/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:05:26 by hle-roi           #+#    #+#             */
/*   Updated: 2023/09/24 15:10:10 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushlib.h"

void	print_num(int num)
{
	ft_putnbr(num);
	ft_putchar(' ');
}

void	convert_num(int *num)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (3 - i == 1 && num[i] != 0)
		{
			print_num(num[i]);	
		}
		if (3 - i == 2 && num[i] != 0)
		{
			if (num[i] < 2)
			{
				print_num(num[i] * 10 + num[i + 1]);
				break ;
			}
			else
				print_num(num[i] * 10);
		}
		if (3 - i == 3 && num[i] != 0)
		{
			print_num(num[i]);
			print_num(100);
		}
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

void	num_spell(char *num)
{
	int	i;
	int	index;
	int	*temp;
	int	count;

	temp = malloc(3 * sizeof(int));
	count = 3 - (ft_strlen(num) % 3);
	if (count == 3)
		count = 0;
	i = 0;
	init_temp(temp);
	index = -1;
	while (num[i])
	{
		temp[count] = num[i] - 48;
		count++;
		if (count == 3 || num[i + 1] == 0)
		{
			convert_num(temp);
			init_temp(temp);
			index++;
			if (num[i + 1] != 0)
			{
				print_num(ft_power(1000, ft_strlen(num) / 3 - index));
			}
			count = 0;
		}
		i++;
	}
	free(temp);
}

int	main(void)
{
	char	num[] = "999999999";

	num_spell(num);
	return (0);
}
