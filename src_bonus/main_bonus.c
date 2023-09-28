/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:06:56 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/28 00:11:27 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char *av[])
{
	char	**str_num;

	if (ac == 1)
		return (1);
	else if (ac == 2)
	{
		validate_str_av(av[1]);
		str_num = ft_split(av[1], ' ');
		validate_av(str_num, ac);
	}
	else
	{
		str_num = av + 1;
		validate_av(str_num, 0);
	}
	checker(str_num, ac);
	if (ac == 2)
		free_2d_str(str_num);
	return (0);
}
