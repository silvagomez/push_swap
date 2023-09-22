/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:26:26 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/21 23:37:48 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init_nodes(t_stack *a, t_stack *b)
{
	ft_printf("Init nodes\n");
	stack_set_idx(a);
	ft_printf("Init nodes check b\n");
	if (b)
	{
		stack_set_idx(b);
		stack_set_target(a, b);
		stack_set_move_cost(a, b);
		stack_set_cheapest(b);
	}
	else
		ft_printf("FIRST TIME NO EXIST B\n");
}
