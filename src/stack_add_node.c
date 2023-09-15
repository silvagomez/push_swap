/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:44:53 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/15 22:45:43 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    node->num = num;
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
