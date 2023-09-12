/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:53:49 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/12 01:29:35 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	if (!stack || !*stack || stack_size(*stack) < 2)
		return ;
	last_node = stack_get_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = (*stack);
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **a, t_stack **b);
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
