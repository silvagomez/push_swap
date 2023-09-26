/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:28:30 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/26 17:24:30 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function validate case if av = "numbers".
 * Characters can be digits, + , - or space.
 */
void	validate_str_av(char *s)
{
	size_t	idx;

	if (!s || !*s)
		error_terminate("ERROR");
	idx = 0;
	if (s[idx] == ' ')
		error_terminate("ERROR");
	while (s[idx])
	{
		if (!ft_isdigit(s[idx]) && s[idx] != '+' && s[idx] != '-' && \
				s[idx] != ' ')
			error_terminate("ERROR");
		idx++;
	}
}

int	is_duplicate(long *nums, size_t size)
{
	size_t	i;
	size_t	j;
	long	aux;
	size_t	duplicate;

	i = 0;
	while (i < size)
	{
		aux = nums[i];
		j = 0;
		duplicate = 0;
		while (j < size)
		{
			if (aux == nums[j])
				duplicate++;
			if (duplicate > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_is_duplicate(char **str_num, size_t size, int event)
{
	long	*nums;
	size_t	idx;

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

/*
 * Validate characters, can be digits, + , - or space.
 * Validate format, only can be digit, +digit or -digit.
 */
int	validate_chr(char *s)
{
	size_t	idx;

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
 * Orchestrator validator.
 */
void	validate_av(char **str_num, int event)
{
	size_t	idx;
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
}
/*
	THIS SHOULD BE GO IN stack_init or in the main.
	if (event == 2)
		free_2d_str(str_num);
*/
