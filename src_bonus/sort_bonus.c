/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:31:05 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/27 23:38:21 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* 
 * Sort 3 numbers.
 */
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

/*
 * Prepare 5 numbers for sorting sending the 2 lowest node to stack b.
 */
void	sort_five_nodes(t_stack **a, t_stack **b, size_t size_a)
{
	t_stack	*lowest_node;

	while (size_a > 3)
	{
		stack_set_idx(*a);
		lowest_node = stack_get_lowest_node(*a);
		while (*a != lowest_node)
		{
			if (lowest_node->one_half == 1)
				ra(a);
			else if (lowest_node->one_half == 0)
				rra(a);
		}
		if (*a == lowest_node)
		{
			pb (b, a);
			size_a--;
		}
	}
}

/*
void	sort_logic_five_nodes(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		stack_init_nodes(*a, *b);
		rotate_stack(a, stack_get_lowest_node(*a), 'a');
		pb(b,a);
	}
}
*/
/*
void	sort_five_idea_1(t_stack **a, t_stack **b, size_t size_a)
{
	while (size_a != 3)
	{
		lowest_node = stack_get_lowest_node(*a)
		while (*a != lowest_node)

		pb(b, a);
		size_a--;
	}
	if ((*a)->num > (*a)->next->num)
		sa(a);
	sort_three_nodes(a);
	while(*b)
	{
		stack_init_nodes(*a, *b);
		sort_to_optimize(a, b);
	}
}
*/

/*
 * Optimize move, inspiration VIM relative numbers. 
 */
void	sort_to_optimize(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = stack_get_cheapest_node(*b);
	if (cheapest_node->one_half == 1 && cheapest_node->target->one_half == 1)
		r_rr_optimize(a, b, cheapest_node, 1);
	else if (cheapest_node->one_half == 0 \
			&& cheapest_node->target->one_half == 0)
		r_rr_optimize(a, b, cheapest_node, 0);
	r_rr_stack(b, cheapest_node, 'b');
	r_rr_stack(a, cheapest_node->target, 'a');
	pa(a, b);
}

void	sort_to_finish(t_stack **a)
{
	t_stack	*lowest_node;

	stack_set_idx(*a);
	lowest_node = stack_get_lowest_node(*a);
	if (lowest_node->one_half == 1)
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
	if (size_a < 6)
		sort_five_nodes(a, b, size_a);
	else
	{
		while (size_a > 3)
		{
			pb(b, a);
			size_a--;
		}
	}
	sort_three_nodes(a);
	while (*b)
	{
		stack_init_nodes(*a, *b);
		sort_to_optimize(a, b);
	}
	sort_to_finish(a);
}

/*
void	sort_stack_idea_1(t_stack **a, t_stack **b)
{
	t_stack	*lowest_node;
	size_t	size_a;
	size_t	size_b;

	stack_set_idx(*a);
	size_a = stack_size(*a);
	while (size_a != 1)
	{
		lowest_node = stack_get_lowest_node(*a);
		while (*a != lowest_node)
		{
			if (lowest_node->one_half == 1)
				ra(a);
			else if (lowest_node->one_half == 0)
				rra(a);
		}
		if (*a == lowest_node)
		{
			pb (b, a);
			size_a--;
		}
		stack_set_idx(*a);
	}
	size_b = stack_size(*b);
	while (*b)
		pa(a, b);
}
*/
