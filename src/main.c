/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:49:31 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/08/30 01:41:06 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handling(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

void	free_2d_ptr(char **s, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		free(s[idx]);
		idx++;
	}
	free(s);
}
/*
int	validate_chr(char *s)
{
	unsigned int	idx;

	idx = 0;
	while (s[idx])
	{
		if (ft_isdigit(s[idx]) || ((s[idx] = '-' || s[idx] '+')))
		{

		}
	}
}
*/
void	validate_argv(char **sn, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (sn[i][j])
		{
			if ((!ft_isdigit(sn[i][j]) || sn[i][j] != '+' || sn[i][j] != '-') \
					|| (ft_isdigit(sn[i][j]) && sn[i][j + 1] && \
						(sn[i][j + 1] == '-' || sn[i][j + 1] == '+' )))
			{
				free_2d_ptr(sn, size);
				error_handling("ERROR : argv must be numbers");
				j++;
			}
		}
		i++;
	}
}

void	validate_args(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && !av[1][0]))
		error_handling("ERROR : invalid arguments");
	else if (ac == 2)
		validate_argv(ft_split(av[1], ' '), ac - 1);
	else
		validate_argv(av + 1, ac - 1);
}

int	main(int ac, char *av[])
{
	t_stack	*stk;

	validate_args(ac, av);
	stk = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if(!stk)
		error_handling("ERROR : malloc");
	(void) stk;
	return (0);
}
