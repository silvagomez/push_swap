/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:49:31 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/12 01:50:48 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_size(char **str_num)
{
	unsigned int	size;
	size = 0;
	while (str_num[size])
		size++;
	return (size);
}

int	*get_nums(char **str_num, unsigned int size, int event)
{
	int				*nums;
	unsigned int	idx;
	
	nums = (int *)malloc(size * sizeof(int));
	if (!nums)
		error_validate(str_num, event);
	idx = 0;
	while (str_num[idx])
	{
		nums[idx] = ft_atoi(str_num[idx]);
		idx++;
	}
	return (nums);
}

t_stack	*stack_get_last_node(t_stack *stack)
{
	if (!stack)
		//Should be a error?
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

unsigned int	stack_size(t_stack *stack)
{
	unsigned int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		++size;
		stack = stack->next;
	}
	return (size);
}

/*
 * The a stack pointer changes only once -> from NULL to the first node.
 *
 */
void    stack_add_node(t_stack **stack, int num)
{
    t_stack    *node;
    t_stack    *last_node;

    if (!stack)
		return ;
        //ft_printf("is null **stack !!!\n");
    node = malloc(sizeof(t_stack));
    if (!node)
	{
		// here error and free
		// free_stack();
		ft_printf("node is null !!!!\n");
        return ;
	}
    node->next = NULL;
    node->value = num;
    if (!*stack)
    {
		ft_printf("Inside->\n");
        *stack = node;
        node->prev = NULL;
	ft_printf("End\n");
    }
    else
    {
		ft_printf("Inside--->\n");
        last_node = stack_get_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

void    stack_init(t_stack **stack, char **str_num, int event)
{
	int				*nums;
	unsigned int	size;
	unsigned int	idx;
	
	size = get_size(str_num);
	nums = get_nums(str_num, size, event);
	idx = 0;
	while (idx < size)
	{
		stack_add_node(stack, nums[idx]);
		idx++;
	}
	free(nums);
}

void	stack_free(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
		{
			ft_printf("NOT sorted\n");
			return (0);
		}
		stack = stack->next;
	}
	ft_printf("is sorted\n");
	return (1);
}

void	push_swap(char **str_num, int event)
{
	t_stack			*a;
	//t_stack 		*b;

	a = NULL;
	//b = NULL;
	stack_init(&a, str_num, event);
	if (!is_stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		//else if (stack_size == 3)
		//	sort_three(&a);
		//else
		//	sort_stack(&a, &b);
	}
	stack_free(&a);
}
