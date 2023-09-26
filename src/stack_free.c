/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:48:05 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/26 13:32:24 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*node;

	if (!stack)
		return ;
	node = *stack;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*stack = NULL;
}
