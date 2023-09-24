/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:57:26 by lomajeru          #+#    #+#             */
/*   Updated: 2023/09/24 22:40:32 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	in_dict(long long nb, t_dict *dict)
{
	int	k;

	k = 0;
	while (k < dict[0].len)
	{
		if (dict[k].nb == nb)
			return (write(1, dict[k].value, ft_strlen(dict[k].value)));
		k++;
	}
	return (0);
}

int	writtable(long long nbr, t_dict *dict)
{
	int	k;

	k = 0;
	while (k < dict[0].len)
	{
		if (dict[k].nb * 1000 > nbr)
		{
			if (dict[k].nb == 1000000)
				return (1);
			if (dict[k].nb == 1000000000)
				return (1);
			if (dict[k].nb == 1000000000000)
				return (1);
			if (dict[k].nb == 1000000000000000)
				return (1);
			if (dict[k].nb == 1000000000000000000)
				return (1);
		}
		k++;
	}
	return (0);
}

int	do_ac_2(char **av)
{
	t_dict	*dict;

	if (ft_atoi_check(av[1]) < 0)
		return (write(2, "Error\n", sizeof("Error\n")));
	dict = parsing("numbers.dict");
	if (!dict)
		return (1);
	if (!writtable(ft_atoi_check(av[1]), dict) 
		&& in_dict(ft_atoi_check(av[1]), dict))
		return (0);
	if (!writtable(ft_atoi_check(av[1]), dict))
		return (write(2, "Dict Error\n", sizeof("Dict Error\n")));
	ft_print_nbr(ft_atoi_check(av[1]), dict);
	return (0);
}

int	do_ac_3(char **av)
{
	t_dict	*dict;

	if (ft_atoi_check(av[2]) < 0)
		return (write(2, "Error\n", sizeof("Error\n")));
	dict = parsing(av[1]);
	if (!dict)
		return (1);
	if (!writtable(ft_atoi_check(av[2]), dict) 
		&& in_dict(ft_atoi_check(av[1]), dict))
		return (0);
	if (!writtable(ft_atoi_check(av[2]), dict))
		return (write(2, "Dict Error\n", sizeof("Dict Error\n")));
	ft_print_nbr(ft_atoi_check(av[2]), dict);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		return (do_ac_2(av));
	if (ac == 3)
		return (do_ac_3(av));
	return (0);
}
