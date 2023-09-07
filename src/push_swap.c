/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:49:31 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/07 17:59:47 by dsilva-g         ###   ########.fr       */
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

void	lstlast_ps(t_stack *node


void	lstadd_back_ps(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (*stack == NULL)
		*stack = new;
	else
		(lstlast_ps(*stack))->next = new;
}


void    stack_init(t_stack **stack, int num)
{
    t_stack    *node;
    //t_stack    *last_node;

    if (!stack)
        ft_printf("is null **stack !!!\n");
    node = malloc(sizeof(t_stack));
    if (!node)
	{
		// here error and free
		ft_printf("node is null !!!!\n");
        return ;
	}
	ft_printf("Before node->\n");
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
		//Here add last to stack a

        //last_node = find_last_node(*stack);
        //last_node->next = node;
        //node->prev = last_node;
    }
}

void	push_swap(char **str_num, int event)
{
	t_stack			*a;
	//t_stack 		*b;
	int				*nums;
	unsigned int	size;
	unsigned int	idx;

	a = NULL;
	//b = NULL;
	size = get_size(str_num);
	nums = get_nums(str_num, size, event);
	idx = 0;
	while (idx < size)
	{
		stack_init(&a, nums[idx]);
		idx++;
	}
	//stack_init(&a, nums);
	//stack_init(&a, str_num, ac);
	free(nums);
}
