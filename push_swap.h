/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjaradat <sjaradat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:27:41 by sjaradat          #+#    #+#             */
/*   Updated: 2026/11/18 19:05:42 by sjaradat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_counts
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_counts;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	int				size_a;
	int				size_b;
	int				total_size;
	double			disorder;
	int				strategy;
	int				bench;
	t_counts		counts;
}					t_data;

t_stack				*new_node(int value);
t_stack				*stack_last(t_stack *stack);
void				stack_add_back(t_stack **stack, t_stack *new);
int					stack_size(t_stack *stack);
void				free_stack(t_stack **stack);
int					parse_args(t_data *data, int argc, char **argv);
int					validate_args(t_stack *stack);
void				sa(t_data *data);
void				sb(t_data *data);
void				ss(t_data *data);
void				pa(t_data *data);
void				pb(t_data *data);
void				assign_index(t_stack *stack);
#endif
