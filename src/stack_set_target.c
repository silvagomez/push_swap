/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:18:31 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/26 16:12:00 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
