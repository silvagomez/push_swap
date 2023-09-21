/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_optimize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:09:18 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/21 11:29:27 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_optimize(t_stack **a, t_stack **b, t_stack *cheapest_node, \
		size_t one_half)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
	{
		if (one_half == 1)
			rr(a, b);
		else if (one_half == 0)
			rrr(a,b);
	}
	stack_set_idx(*a);
	stack_set_idx(*b);
}
