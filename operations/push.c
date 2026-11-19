/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjaradat <sjaradat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:00:23 by sjaradat          #+#    #+#             */
/*   Updated: 2026/11/18 19:02:22 by sjaradat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_data *data)
{
	t_stack	*temp;

	if (!data->a)
		return ;
	temp = data->a;
	data->a = data->a->next;
	temp->next = data->b;
	data->b = temp;
	data->size_a--;
	data->size_b++;
}

void	pa(t_data *data)
{
	t_stack	*temp;

	if (!data->b)
		return ;
	temp = data->b;
	data->b = data->b->next;
	temp->next = data->a;
	data->a = temp;
	data->size_a++;
	data->size_b--;
}
