/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:50:11 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/07 16:59:16 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Allowed libraries
# include "../libft/libft.h"

typedef struct s_stack
{
	int					value;
	unsigned int		position;
	unsigned int		move_cost;
	unsigned int		above_median;
	unsigned int		cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node *prev;
}				t_stack;

// Validate functions
void	validate_str_av(char *s);
void	validate_av(char **str_num, int event);
int		validate_chr(char *s);
void	validate_is_duplicate(char **str_num, unsigned int size,  int event);
int		is_duplicate(long *nums, unsigned int size);

long	ft_atol(const char *str);

// Error functions
void	error_terminate(char *str_error);
void	error_validate(char **s, int event);

// Free memory functions
void	free_2d_str(char **s);

//	Push swap functions

void	push_swap(char **str_num, int event);
void    stack_init(t_stack **stack, int nbr);
int	*get_nums(char **str_num, unsigned int size, int event);
unsigned int	get_size(char **str_num);
#endif
