/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_move_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:18:45 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/25 11:16:58 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Like vim calculate the relaitve number for move_cost in stack "b"
 */
/*
void	stack_set_move_cost(t_stack *a, t_stack *b)
{
	size_t	size_a;
	size_t	size_b;

	//if (!a | !b)
	//	return ;
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		//ft_printf("SET move cost\n");
		b->move_cost = b->idx;
		if (b->one_half == 0)
			b->move_cost = size_b - b->idx;
		if (b->target->one_half == 1)
			b->move_cost += b->target->idx;
		else
			b->move_cost += size_a - b->target->idx;
		b = b->next;
	}
}
*/

void	stack_set_move_cost(t_stack *a, t_stack *b)
{
	size_t	size_a;
	size_t	size_b;

	//if (!a | !b)
	//	return ;
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		//ft_printf("SET move cost\n");
		b->move_cost = b->idx;
		if (b->one_half == 0)
			b->move_cost = size_b - b->idx;
		if (b->target->one_half == 1 && b->one_half == 1)
			b->move_cost += b->move_cost;
		else if (b->target->one_half == 0 && b->one_half == 1)
			b->move_cost += b->target->idx;	
		else if (b->target->one_half == 1 && b->one_half == 0)
			b->move_cost += size_a - b->target->idx;
		else if (b->target->one_half == 0 && b-one_half == 0)
			b->move_cost += b->target->idx;	
		b = b->next;
	}
}
