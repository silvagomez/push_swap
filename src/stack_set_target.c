/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:18:31 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/22 17:12:38 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_set_target(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*temp_a;
	int		target_index;

	while (b)
	{
		//ft_printf("SET target\n");
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
		if (INTMAX == target_index)
			b->target = stack_get_lowest_node(a);
		else
			b->target = target_node;
		//ft_printf("%d his target pointer is %p with num: %d\n", b->num, b->target, b->target->num);
		b = b->next;
	}
}
