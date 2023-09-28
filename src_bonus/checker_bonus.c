/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:06:44 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/28 02:59:50 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	checker_move_stack(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp("pa\n", line, 3) == 0 && *b)
		pa(a, b);
	else if (ft_strncmp("pb\n", line, 3) == 0 && *a && b)
		pb(b, a);
	else if (ft_strncmp("sa\n", line, 3) == 0 && *a)
		sa(a);
	else if (ft_strncmp("sb\n", line, 3) == 0 && *b)
		sb(b);
	else if (ft_strncmp("ss\n", line, 3) == 0 && *a && *b)
		ss(a, b);
	else if (ft_strncmp("ra\n", line, 3) == 0 && *a)
		ra(a);
	else if (ft_strncmp("rb\n", line, 3) == 0 && *b)
		rb(b);
	else if (ft_strncmp("rr\n", line, 3) == 0 && *a && *b)
		rr(a, b);
	else if (ft_strncmp("rra\n", line, 4) == 0 && *a)
		rra(a);
	else if (ft_strncmp("rrb\n", line, 4) == 0 && *b)
		rrb(b);
	else if (ft_strncmp("rrr\n", line, 4) == 0 && *a && *b)
		rrr(a, b);
	else
		error_unknow_move(a, b, line);
}

static void	checker_validate_sort(t_stack **a, t_stack **b, size_t size_a)
{
	if (is_stack_sorted(*a) && size_a == stack_size(*a))
		ft_putendl_fd("OK", 1);
	else
	{
		stack_free(a);
		stack_free(b);
		error_terminate("KO");
	}
}

void	checker(char **str_num, int event)
{
	t_stack	*a;
	t_stack	*b;
	size_t	size_a;
	char	*line;

	a = NULL;
	b = NULL;
	stack_init_a(&a, str_num, event);
	size_a = stack_size(a);
	line = get_next_line(0);
	while (line)
	{
		checker_move_stack(&a, &b, line); 
		free(line);
		line = get_next_line(0);
	}
	free(line);
	checker_validate_sort(&a, &b, size_a);
	stack_free(&a);
}
