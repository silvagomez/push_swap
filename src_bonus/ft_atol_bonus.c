/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:42:52 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/27 23:24:31 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// Converts ASCII string to integers long value.

long	ft_atol(const char *str)
{
	unsigned int	idx;
	long			num;
	int				sign;

	idx = 0;
	num = 0;
	sign = 1;
	while ((str[idx] >= '\t' && str[idx] <= '\r') || str[idx] == ' ')
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		num = num * 10 + str[idx] - '0';
		idx++;
	}
	return (num * sign);
}
