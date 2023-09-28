/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:53:49 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/28 01:28:54 by dsilva-g         ###   ########.fr       */
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
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!stack || !*stack || stack_size(*stack) < 2)
		return ;
	last_node = stack_get_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
