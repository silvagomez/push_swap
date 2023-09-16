/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:26:26 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/16 15:14:10 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	stack_init_nodes(t_sack *a, t_stack *b)
{
	stack_set_idx(a);
	stack_set_idx(b);
	stack_set_target(a, b);
	stack_set_move_cost(a, b);
	stack_set_cheapest(b);
}
