/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:57:26 by lomajeru          #+#    #+#             */
/*   Updated: 2023/09/24 20:22:27 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int ac, char **av)
{
	t_dict	*dict;

	if (ac == 2)
	{
		if (ft_atoi_check(av[1]) < 0)
			return (write(2, "Error\n", sizeof("Error\n")));
		if (ft_atoi_check(av[1]) > 999999999999)
			return (write(2, "Dict Error\n", sizeof("Dict Error\n")));
		dict = parsing("numbers.dict");
		if (!dict)
			return (1);
		ft_print_nbr(ft_atoi_check(av[1]), dict);
	}
	if (ac == 3)
	{
		if (ft_atoi_check(av[2]) < 0)
			return (write(2, "Error\n", sizeof("Error\n")));
		if (ft_atoi_check(av[2]) > 999999999999)
			return (write(2, "Dict Error\n", sizeof("Dict Error\n")));
		dict = parsing(av[1]);
		if (!dict)
			return (1);
		ft_print_nbr(ft_atoi_check(av[2]), dict);
	}
}
