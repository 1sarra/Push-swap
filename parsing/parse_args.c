/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjaradat <sjaradat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:05:56 by sjaradat          #+#    #+#             */
/*   Updated: 2026/11/17 18:05:57 by sjaradat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "../push_swap.h"

static int is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

static int parse_number(char **str, int *number)
{
    long long   value;
    long long   limit;
    int         sign;
    int         digit;

    while (is_space(**str))
        (*str)++;
    if (**str == '\0')
        return (0);
    sign = 1;
    if (**str == '-' || **str == '+')
    {
        if (**str == '-')
            sign = -1;
        (*str)++;
    }
    if (**str < '0' || **str > '9')
        return (-1);
    value = 0;
    if (sign == 1)
        limit = INT_MAX;
    else
        limit = -(long long)INT_MIN;
    while (**str >= '0' && **str <= '9')
    {
        digit = **str - '0';
        if (value > (limit - digit) / 10)//overflow protection
            return (-1);
        value = value * 10 + digit;
        (*str)++;
    }
    if (**str != '\0' && !is_space(**str))
        return (-1);
    *number = (int)(value * sign);
    return (1);
}

int parse_args(t_data *data, int argc, char **argv)
{
    int     i;
    int     result;
    int     number;
    int     found;
    char    *str;
    t_stack *node;

    i = 1;
    while (i < argc)
    {
        str = argv[i];
        found = 0;
        while (1)//Because we don't know how many numbers are inside the argument.
        {
            result = parse_number(&str, &number);
            if (result == 0)
                break ;
            if (result == -1)
                return (0);
            node = new_node(number);
            if (!node)
                return (0);
            stack_add_back(&data->a, node);
            data->size_a++;
            data->total_size++;
            found = 1;
        }
        if (!found)
            return (0);
        i++;
    }
    return (1); 
}