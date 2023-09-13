/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:28:56 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/13 13:37:35 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_get_highest_node(t_stack *stack)
{
	t_stack	*highest_node;
	int		highest_num;

	highest_num = -2147483648;
	while (stack->next)
	{
		if (stack->num > highest_num)
		{
			highest_num = stack->num;
			highest_node = stack;
		}
		ft_printf("HIghest num %d\n", highest_num);
		stack = stack->next;
	}
	return (highest_node);
}

t_stack *stack_get_lowest_node(t_stack *stack)
{
	t_stack	*lowest_node;
	int		lowest_num;

	lowest_num = 2147483647;
	while (stack->next)
	{
		if (stack->num < lowest_num)
		{
			lowest_num = stack->num;
			lowest_node = stack;
		}
		ft_print("LOWest num %d\n", lowest_num);
		stack = stack->next;
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = stack_get_highest_node(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}
