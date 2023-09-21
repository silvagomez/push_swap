/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:33:06 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/21 22:29:11 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_terminate(char *str_error)
{
	ft_putendl_fd(str_error, 2);
	exit(1);
}

void	error_validate(char **s, int event)
{
	if (event == 2)
	{
		free_2d_str(s);
		error_terminate("ERROR 4");
	}
	error_terminate("ERROR 5");
}
