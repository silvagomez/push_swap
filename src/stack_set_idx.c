/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:18:13 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/21 11:13:19 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_set_idx(t_stack *stack)
{
	size_t	half;
	size_t	idx;

	idx = 0;
	half = stack_size(stack) / 2;
	while (stack)
	{
		stack->idx = idx;
		if (idx <= half)
			stack->one_half = 1;
		else
			stack->one_half = 0;
		stack = stack->next;
		idx++;
	}
}
