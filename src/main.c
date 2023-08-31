/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:49:31 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/08/31 14:21:24 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handling(char *s)
{
	if (s == NULL)
	{
		exit(1);
	}
	else
	{
		ft_printf("%s\n", s);
		exit(1);
	}
}

void	free_2d_str(char ***s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		free(s[idx]);
		idx++;
	}
	free(s);
}

int	validate_chr(char *s)
{
	unsigned int	idx;

	idx = 0;
	if (ft_isdigit(s[idx]) || s[idx] == '-' || s[idx] == '+')
		idx++;
	else
		return (0);
	while (s[idx])
	{
		if (!ft_isdigit(s[idx]))
			return (0);
		idx++;
	}
	return (1);
}

void	validate_av(char **str_num)
//void	validate_av(char **str_num, int size)
{
	int	idx;

	idx = 0;
	while (str_num[idx])
	{
		ft_printf("antes %s\n", str_num[idx]);
		if (validate_chr(str_num[idx]) == 0)
		{
			//return (0);
			//free_2d_str(&str_num);
			error_handling("ERROR : argv must be numbers");
		}
		idx++;
	}
	//return (1);
}
/*
void	validate_args(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && !av[1][0]))
		error_handling("ERROR : invalid arguments");
	else if (ac == 2)
		validate_argv(ft_split(av[1], ' '), ac - 1);
	else
		validate_argv(av + 1, ac - 1);
}
*/
void	validate_str_av(char *s)
{
	unsigned int	idx;

	if (!s || !*s)
		error_handling("ERROR : wrong chararcter");
	idx = 0;
	while (s[idx])
	{
		if (!ft_isdigit(s[idx]) && s[idx] != '+' && s[idx] != '-' && \
				s[idx] != ' ')
			error_handling("ERROR : wrong chararcter");
		idx++;
	}
}

int	main(int ac, char *av[])
{
	char	**str_num;
	t_stack	*stk;

	str_num = NULL;
	if (ac == 1)
		error_handling(NULL);
	else if (ac == 2)
	{
		validate_str_av(av[1]);
		str_num = ft_split(av[1], ' ');
		validate_av(str_num);
	}
	else
	{
		str_num = av + 1;
		validate_av(str_num);
	}
	free_2d_str(&str_num);
	stk = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if(!stk)
		error_handling("ERROR : malloc");
	free(stk);
	stk = NULL;
	return (0);
}

//LEAKS
//Liberar split
