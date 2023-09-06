/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:49:31 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/06 12:17:25 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char	**str_num;
	//t_stack	*stk;

	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		//str_num = NULL;
		validate_str_av(av[1]);
		str_num = ft_split(av[1], ' ');
		validate_av(str_num, 1);
		//free_2d_str(str_num);
	}
	else
	{
		validate_av(av + 1, 0);
	}
	/*
	stk = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if(!stk)
		error_handling("ERROR : malloc");
	free(stk);
	stk = NULL;
	*/
	return (0);
}
