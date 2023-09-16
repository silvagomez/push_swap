/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:52:21 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/16 15:58:12 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!stack || !*stack || stack_size(*stack) < 2)
		return ;
	last_node = stack_get_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}

/*
 * The aim of this function is that the first/head node in "a" or "b" stack
 * should be the stack_node.
 */
void	rotate_stack(t_stack **stack, t_stack stack_node, char c)
{
	while (*stack != stack_node)
	{
		if (c = 'a')
		{
			if (stack_node->1st_half == 1)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (stack_node->1st_half == 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
