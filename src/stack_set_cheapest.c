/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_cheapest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:19:02 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/26 18:11:04 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_set_cheapest(t_stack *b)
{
	t_stack	*cheapest_node;
	size_t	cheapest_cost;

	if (!b)
		return ;
	cheapest_cost = 2147483647;
	while (b)
	{
		b->cheapest = 0;
		if (b->move_cost < cheapest_cost)
		{
			cheapest_cost = b->move_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = 1;
}
