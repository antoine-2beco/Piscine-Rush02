/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:05:02 by lomajeru          #+#    #+#             */
/*   Updated: 2023/09/24 19:35:43 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (0);
	ft_strcpy(dest, src);
	return (dest);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_power(int nb, int power)
{
	int	rep;

	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	if (power == 0 && nb != 0)
		return (1);
	rep = nb;
	while (--power > 0)
		rep *= nb;
	return (rep);
}
