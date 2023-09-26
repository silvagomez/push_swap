/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:44:53 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/26 18:03:24 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
