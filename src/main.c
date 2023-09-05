/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:49:31 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/06 01:09:05 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handling(char *s)
{
		ft_printf("%s\n", s);
		exit(1);
}

void	error_terminate(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_2d_str(char **s)
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

void	error_validate(char **s, int event)
{
	if (event == 1)
	{
		free_2d_str(s);
		error_terminate();
	}
		error_terminate();
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
/*
void	validate_av(char **str_num, int event)
//void	validate_av(char **str_num, int size)
{
	int		idx;
	long	num;

	idx = 0;
	while (str_num[idx])
	{
		if (validate_chr(str_num[idx]) == 0)
		{
			if (event == 1)
				free_2d_str(str_num);
			error_handling("ERROR : argv must be numbers");
		}
		num = ft_atol(str_num[idx]);
		if (num < -2147483648 || num > 2147483647)
		{
			if (event == 1)
				free_2d_str(str_num);
			error_handling("ERROR : argv must be numbers");
		}
		idx++;
	}
	if (event == 1)
		free_2d_str(str_num);
}
*/

int	is_duplicate(long *nums, int size)
{
	int		i;
	int		j;
	long	aux;

	i = 0;
	while(i < size)
	{
		aux = nums[i];
		j = 0;
		while (j < size)
		{
			if (aux == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_is_duplicate(char **str_num, int size,  int event)
{
	long	*nums;
	int		idx;

	nums = (long *)malloc(size * sizeof(long));
	if (!nums)
		error_validate(str_num, event);
	idx = 0;
	while (str_num[idx])
	{
		nums[idx] = ft_atol(str_num[idx]);
		idx++;
	}
	if (is_duplicate(nums, size) == 1)
	{
		free(nums);
		error_validate(str_num, event);
	}
	free(nums);
}


void	validate_av(char **str_num, int event)
{
	int		idx;
	long	num;

	idx = 0;
	while (str_num[idx])
	{
		if (validate_chr(str_num[idx]) == 0)
			error_validate(str_num, event);
		num = ft_atol(str_num[idx]);
		if (num < -2147483648 || num > 2147483647)
			error_validate(str_num, event);
		idx++;
	}
	validate_is_duplicate(str_num, idx, event);
	if (event == 1)
		free_2d_str(str_num);
}

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
