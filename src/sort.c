/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:31:05 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/16 00:58:17 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nodes(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = stack_get_highest_node(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

void	sort_for_moves(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		stack_init_nodes(*a, *b);
		rotate_stack(
		pb(b,a);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	size_t	size_a;

	size_a = stack_size(*a);
	if (size_a == 5)
		sort_for_moves(a, b);
	else
		while (size_a > 3)
		{
			pb (b, a);
			size_a--;
		}
	sort_three_nodes(*a);
	while (*b)
}
