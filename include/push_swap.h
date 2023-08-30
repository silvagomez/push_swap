/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:50:11 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/08/29 19:25:50 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Allowed libraries
# include "../libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					position;
	struct s_stack_node	*next;
	struct s_stack_node *prev;

}				t_stack_node;

typedef struct	s_stack
{
	int				size;
	int				max;
	int				min;
	t_stack_node	a;
	t_stack_node	b;

}				t_stack;

#endif
