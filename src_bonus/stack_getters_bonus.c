/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_getters_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:49:33 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/27 23:11:55 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

t_stack	*stack_get_highest_node(t_stack *stack)
{
	t_stack	*highest_node;
	int		highest_num;

	highest_num = -2147483648;
	while (stack)
	{
		if (stack->num > highest_num)
		{
			highest_num = stack->num;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_stack	*stack_get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_get_lowest_node(t_stack *stack)
{
	t_stack	*lowest_node;
	int		lowest_num;

	lowest_num = 2147483647;
	while (stack)
	{
		if (stack->num < lowest_num)
		{
			lowest_num = stack->num;
			lowest_node = stack;
		}
		stack = stack->next;
	}
	return (lowest_node);
}
