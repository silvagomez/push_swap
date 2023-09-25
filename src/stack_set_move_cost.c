/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_move_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:18:45 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/25 18:05:00 by dsilva-g         ###   ########.fr       */
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

size_t	move_cost_same_half(t_stack *a, t_stack *b, size_t one_half)
{
	size_t	size_a;
	size_t	size_b;


	size_a = stack_size(a);
	size_b = stack_size(b);
	if (one_half == 1)
	{	
		if (b->target->idx > b->idx)
			return (b->idx + (b->target->idx - b->idx));
		else
			return (b->target->idx + (b->idx - b->target->idx));
	}
	else
	{
		if ((size_a - b->target->idx) > (size_b - b->idx))
			return (size_a - b->target->idx);
		else
			return (size_b - b->idx);
	}
}	

/*
 * Like vim calculate the relaitve number for move_cost in stack "b"
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
		if (b->target->one_half == 1 && b->one_half == 1)
		{
			//b->move_cost = move_cost_same_half(a, b, 1);
			
			if (b->target->idx > b->idx)
				b->move_cost = (b->idx + (b->target->idx - b->idx));
			else
				b->move_cost = (b->target->idx + (b->idx - b->target->idx));
			
		}
		else if (b->target->one_half == 0 && b->one_half == 1)
			b->move_cost = b->idx + (size_a - b->target->idx);	
		else if (b->target->one_half == 1 && b->one_half == 0)
			b->move_cost = b->target->idx + (size_b - b->idx);
		else if (b->target->one_half == 0 && b->one_half == 0)
		{
			//b->move_cost = move_cost_same_half(a, b, 0);
			
			if ((size_a - b->target->idx) > (size_b - b->idx))
				b->move_cost = (size_a - b->target->idx);
			else
				b->move_cost = (size_b - b->idx);
			
		}
		b = b->next;
	}
}
