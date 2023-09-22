/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:49:31 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/22 10:04:27 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
		{
			ft_printf("NOT sorted\n");
			return (0);
		}
		stack = stack->next;
	}
	ft_printf("IS sorted\n");
	return (1);
}

void	push_swap(char **str_num, int event)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	stack_init_a(&a, str_num, event);
	if (is_stack_sorted(a) == 0)
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_three_nodes(&a);
		else
			sort_stack(&a, &b);
	}
	stack_free(&a);
}
