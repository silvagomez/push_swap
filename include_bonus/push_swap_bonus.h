/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:06:56 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/09/28 13:43:31 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

// Allowed libraries
# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	size_t			idx;
	size_t			move_cost;
	size_t			one_half;
	size_t			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_sizes
{
	size_t	a;
	size_t	b;
}				t_sizes;

// Validate functions
void	validate_str_av(char *s);
void	validate_av(char **str_num, int event);
int		validate_chr(char *s);
void	validate_is_duplicate(char **str_num, size_t size, int event);
int		is_duplicate(long *nums, size_t size);

// Utils
long	ft_atol(const char *str);
int		*get_nums(char **str_num, size_t size, int event);
size_t	get_total_nums(char **str_num);

// Error functions
void	error_terminate(char *str_error);
void	error_validate(char **s, int event, char *str_error);
void	error_unknow_move(t_stack **a, t_stack **b, char *line);

// Free memory functions
void	free_2d_str(char **s);

// Checker functions
void	checker(char **str_num, int event);

// Stack structure functions
void	stack_init_a(t_stack **a, char **str_num, int event);
size_t	stack_add_node(t_stack **stack, int num);
size_t	stack_size(t_stack *stack);
void	stack_free(t_stack **stack);
t_stack	*stack_get_last_node(t_stack *stack);

// Push functions pa | pb
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// Swap functions sa | sb | ss
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// Rotate functions ra | rb | rr
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// Reverse rotatte functions rra | rrb | rrr
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
