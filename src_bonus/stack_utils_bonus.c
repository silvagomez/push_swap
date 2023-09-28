/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:02:09 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/27 23:04:54 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
 * The a stack pointer changes only once -> from NULL to the first node.
 * *a->next points to the next node, the last node points to NULL.
 * *a->prev points to the prev node, the first node point to NULL.
 * Example:
 * NULL<-stack<-last_node->node->NNULL
 */
size_t	stack_add_node(t_stack **stack, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return (0);
	node = malloc(sizeof(t_stack));
	if (!node)
	{
		stack_free(stack);
		return (0);
	}
	node->next = NULL;
	node->num = num;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = stack_get_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return (1);
}

void	stack_init_nodes(t_stack *a, t_stack *b)
{
	stack_set_idx(a);
	stack_set_idx(b);
	stack_set_target(a, b);
	stack_set_move_cost(a, b);
	stack_set_cheapest(b);
}

size_t	stack_size(t_stack *stack)
{
	size_t	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		++size;
		stack = stack->next;
	}
	return (size);
}

void	stack_free(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*node;

	if (!stack)
		return ;
	node = *stack;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*stack = NULL;
}
