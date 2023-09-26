/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:46:50 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/26 13:21:07 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_total_nums(char **str_num)
{
	size_t	size;

	size = 0;
	while (str_num[size])
		size++;
	return (size);
}

int	*get_nums(char **str_num, size_t size, int event)
{
	int		*nums;
	size_t	idx;

	nums = (int *)malloc(size * sizeof(int));
	if (!nums)
		error_validate(str_num, event);
	idx = 0;
	while (str_num[idx])
	{
		nums[idx] = ft_atoi(str_num[idx]);
		idx++;
	}
	return (nums);
}

/*
 * Create/add number to the node of stack a.
 */
void	stack_init_a(t_stack **a, char **str_num, int event)
{
	int		*nums;
	size_t	size;
	size_t	idx;

	size = get_total_nums(str_num);
	nums = get_nums(str_num, size, event);
	idx = 0;
	while (idx < size)
	{
		if (stack_add_node(a, nums[idx]) == 0)
		{
			free(nums);
			error_validate(str_num, event);
		}
			idx++;
	}
	free(nums);
}
