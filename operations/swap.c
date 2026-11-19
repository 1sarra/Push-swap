/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjaradat <sjaradat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:26:39 by sjaradat          #+#    #+#             */
/*   Updated: 2026/11/18 19:02:47 by sjaradat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_data *data)
{
	swap_stack(&data->a);
}

void	sb(t_data *data)
{
	swap_stack(&data->b);
}

void	ss(t_data *data)
{
	swap_stack(&data->a);
	swap_stack(&data->b);
}
