/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rr_optimize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:09:18 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/25 10:09:00 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * The aim of this function is that the first/head node in "a" or "b" stack
 * should be the stack_node.
 */
void	r_rr_stack(t_stack **stack, t_stack *stack_node, char c)
{
	while (*stack != stack_node)
	{
		if (c == 'a')
		{
			if (stack_node->one_half == 1)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (stack_node->one_half == 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	r_rr_optimize(t_stack **a, t_stack **b, t_stack *cheapest_node, \
		size_t one_half)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
	{
		if (one_half == 1)
			rr(a, b);
		else if (one_half == 0)
			rrr(a,b);
	}
	stack_set_idx(*a);
	stack_set_idx(*b);
}
