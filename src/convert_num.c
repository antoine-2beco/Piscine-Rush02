/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:05:26 by lomajeru          #+#    #+#             */
/*   Updated: 2023/09/24 21:42:22 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

long long	ft_curr_len(long long nb)
{
	if (nb >= 1000000000000000000)
		return (1000000000000000000);
	else if (nb >= 1000000000000000)
		return (1000000000000000);
	else if (nb >= 1000000000000)
		return (1000000000000);
	else if (nb >= 1000000000)
		return (1000000000);
	else if (nb >= 1000000)
		return (1000000);
	else if (nb >= 1000)
		return (1000);
	else if (nb >= 100)
		return (100);
	return (0);
}

char	*find_in_dict(long long nbr, t_dict *dict)
{
	int	k;

	k = 0;
	while (k < dict[0].len)
	{
		if (dict[k].nb == nbr)
			return (dict[k].value);
		k++;
	}
	return (NULL);
}

void	ft_print_multiple(long long nbr, t_dict *dict)
{
	if (nbr / 100 != 0)
	{
		ft_putstr(find_in_dict(nbr / 100, dict));
		write(1, " ", 1);
		ft_putstr(find_in_dict(100, dict));
		nbr = nbr % 100;
		if (nbr != 0)
			write(1, " ", 1);
	}
	if (nbr / 10 != 0 && nbr >= 20)
	{
		ft_putstr(find_in_dict(nbr / 10 * 10, dict));
		nbr = nbr % 10;
		if (nbr != 0)
			write(1, " ", 1);
	}
	if (nbr > 0 && nbr < 20)
	{
		ft_putstr(find_in_dict(nbr, dict));
	}
}

void	ft_print_nbr(long long nbr, t_dict *dict)
{
	long long	curr_num;

	if (nbr == 0)
		ft_putstr(find_in_dict(nbr, dict));
	curr_num = ft_curr_len(nbr);
	while (curr_num >= 1000)
	{
		if (nbr / curr_num != 0)
		{
			ft_print_multiple(nbr / curr_num, dict);
			write(1, " ", 1);
			ft_putstr(find_in_dict(curr_num, dict));
			if (nbr % curr_num != 0)
				write(1, " ", 1);
		}
		nbr = nbr % curr_num;
		curr_num = curr_num / 1000;
	}
	ft_print_multiple(nbr, dict);
	write(1, "\n", 1);
}
