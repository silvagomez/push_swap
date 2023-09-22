/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_highest_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:36:49 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/22 10:29:27 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_printf("HIghest num %d\n", highest_num);
		stack = stack->next;
	}
	return (highest_node);
}
