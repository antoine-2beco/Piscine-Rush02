/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:43:55 by hle-roi           #+#    #+#             */
/*   Updated: 2023/09/23 12:15:59 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushlib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
