/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_cheapest_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:27:24 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/26 17:56:43 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_get_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest_node;

	if (!stack)
		return (NULL);
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->cheapest && stack->cheapest == 1)
			cheapest_node = stack;
		stack = stack->next;
	}
	return (cheapest_node);
}
