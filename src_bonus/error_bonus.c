/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:33:06 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/28 03:11:39 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_terminate(char *str_error)
{
	ft_putendl_fd(str_error, 2);
	exit(1);
}

void	error_validate(char **s, int event, char *str_error)
{
	if (event == 2)
	{
		free_2d_str(s);
		error_terminate(str_error);
	}
	error_terminate(str_error);
}

void	error_unknow_move(t_stack **a, t_stack **b, char *line)
{
	free(line);
	stack_free(a);
	stack_free(b);
	error_terminate("ERROR: unknown move OR invalid move");
}
