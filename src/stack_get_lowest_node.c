/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_lowest_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:39:25 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/22 15:02:56 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_get_lowest_node(t_stack *stack)
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
		//ft_printf("LOWest num %d\n", lowest_num);
		stack = stack->next;
	}
	return (lowest_node);
}
