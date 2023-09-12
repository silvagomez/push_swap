/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:51:50 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/12 01:45:29 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * "stack" is a pointer to pointer;
 * did you mean to dereference it before applying "->" to it?
 *  |         *stack = *stack->next;
 *  |                      ^~
 *  |                  (*  )
 */

static void	swap(t_stack **stack)
{
	//unsigned int	size;

	//size = stack_size(*stack);
	if (!stack | !*stack | (stack_size(*stack) < 2))
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
