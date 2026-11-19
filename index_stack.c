/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjaradat <sjaradat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:29:44 by sjaradat          #+#    #+#             */
/*   Updated: 2026/11/19 16:29:46 by sjaradat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    assign_index(t_stack *stack)
{
    t_stack *current;
    t_stack *compare;
    int     index;

    current = stack; //points to the first node
    while (current) //Continue while there is a node
    {
        index = 0;
        compare = stack; //Start comparing from the first node again.
        while (compare)
        {
            if (compare->value < current->value)
                index++;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}