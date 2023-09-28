/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setters_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:49:42 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/27 23:19:59 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	stack_set_idx(t_stack *stack)
{
	size_t	half;
	size_t	idx;

	if (!stack)
		return ;
	idx = 0;
	half = stack_size(stack) / 2;
	while (stack)
	{
		stack->idx = idx;
		if (idx <= half)
			stack->one_half = 1;
		else
			stack->one_half = 0;
		stack = stack->next;
		idx++;
	}
}

size_t	move_cost_same_half(t_stack *b, size_t size_a, size_t size_b, \
		size_t one_half)
{
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

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		if (b->target->one_half == 1 && b->one_half == 1)
			b->move_cost = move_cost_same_half(b, size_a, size_b, 1);
		else if (b->target->one_half == 0 && b->one_half == 1)
			b->move_cost = b->idx + (size_a - b->target->idx);
		else if (b->target->one_half == 1 && b->one_half == 0)
			b->move_cost = b->target->idx + (size_b - b->idx);
		else if (b->target->one_half == 0 && b->one_half == 0)
			b->move_cost = move_cost_same_half(b, size_a, size_b, 0);
		b = b->next;
	}
}

/*
 * The target node could be the lowest or the hihgest depending num of b stack.
 * //
 * ft_printf("%d his target pointer is %p with num: %d\n", \
 * b->num, b->target, b->target->num);
 */
void	stack_set_target(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*temp_a;
	int		target_index;

	while (b)
	{
		target_index = 2147483647;
		temp_a = a;
		while (temp_a)
		{
			if (temp_a->num > b->num && temp_a->num < target_index)
			{
				target_index = temp_a->num;
				target_node = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (target_index == 2147483647)
			b->target = stack_get_lowest_node(a);
		else
			b->target = target_node;
		b = b->next;
	}
}
