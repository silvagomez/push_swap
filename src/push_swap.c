/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:49:31 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/07 12:26:26 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_init(t_stack **stack, int nbr)
{
    t_stack    *node;
    //t_stack    *last_node;

    if (NULL == stack)
        ft_printf("si es null **stack !!!\n");
    node = malloc(sizeof(t_stack));
    if (NULL == node)
	{
		ft_printf("node es null !!!!\n");
        return ;
	}
	ft_printf("Estoy antes de node->\n");
    node->next = NULL;
    node->value = nbr;
    if (NULL == *stack)
    {
		ft_printf("Estoy dentro de node->\n");
        *stack = node;
        node->prev = NULL;
	ft_printf("Adios\n");
    }
    else
    {
        //last_node = find_last_node(*stack);
        //last_node->next = node;
        //node->prev = last_node;
    }
}

