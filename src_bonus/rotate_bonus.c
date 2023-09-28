/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:52:21 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/28 01:28:20 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
 * "stack" is a pointer to pointer;
 * did you mean to dereference it before applying "->" to it?
 *  |         *stack = *stack->next;
 *  |                      ^~
 *  |                  (*  )
 */
static void	rotate(t_stack **stack)
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
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
