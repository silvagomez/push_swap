/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_last_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:42:25 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/15 22:42:59 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

t_stack	*stack_get_last_node(t_stack *stack)
{
	if (!stack)
		//Should be a error?
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
