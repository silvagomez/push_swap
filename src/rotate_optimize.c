/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_optimize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:09:18 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/19 16:23:25 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_optimize(t_satck **a, t_stack_b **b, t_stack cheapest_node, \
		site_t fst_half)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
	{
		if (fst_half == 1)
			rr(a, b);
		else if (fst_half == 0)
			rrr(a,b)
	}
	stack_set_idx(*a);
	stack_set_idx(*b);
}
