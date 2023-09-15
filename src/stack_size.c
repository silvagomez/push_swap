/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:43:16 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/15 22:44:03 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

size_t	stack_size(t_stack *stack)
{
	size_t	size;

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
