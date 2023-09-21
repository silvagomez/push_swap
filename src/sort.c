/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:31:05 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/21 11:28:13 by dsilva-g         ###   ########.fr       */
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

void	sort_logic_five_nodes(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		stack_init_nodes(*a, *b);
		rotate_stack(a, stack_get_lowest_node(*a), 'a');
		pb(b,a);
	}
}

void	sort_to_optimize(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = stack_get_cheapest_node(*b);
	if (cheapest_node->one_half == 1 && cheapest_node->target->one_half == 1)
		rotate_optimize(a, b, cheapest_node, 1);
	else if (cheapest_node->one_half == 0 \
			&& cheapest_node->target->one_half == 0)
		rotate_optimize(a, b, cheapest_node, 0);
	rotate_stack(b, cheapest_node, 'b');
	rotate_stack(a, cheapest_node->target, 'a');
	pa(a, b);
}

void	sort_to_finish(t_stack **a)
{
	t_stack	*lowest_node;
	
	stack_set_idx(*a);
	lowest_node = stack_get_lowest_node(*a);
	if (lowest_node->idx == 1)
	{
		while (*a != lowest_node)
			ra(a);
	}
	else
	{
		while (*a != lowest_node)
			rra(a);
	}

}

void	sort_stack(t_stack **a, t_stack **b)
{
	size_t	size_a;

	size_a = stack_size(*a);
	if (size_a == 5)
		sort_logic_five_nodes(a, b);
	else
		while (size_a > 3)
		{
			pb (b, a);
			size_a--;
		}
	sort_three_nodes(a);
	while (*b)
	{
		stack_init_nodes(*a, *b);
		sort_to_optimize(a, b);
	}
	sort_to_finish(a);
}
