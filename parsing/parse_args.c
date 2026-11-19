/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjaradat <sjaradat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:05:56 by sjaradat          #+#    #+#             */
/*   Updated: 2026/11/18 19:01:22 by sjaradat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	parse_digits(char **str, int sign, long long *value)
{
	long long	limit;
	int			digit;

	limit = INT_MAX;
	if (sign == -1)
		limit = -(long long)INT_MIN;
	*value = 0;
	while (**str >= '0' && **str <= '9')
	{
		digit = **str - '0';
		if (*value > (limit - digit) / 10)
			return (0);
		*value = *value * 10 + digit;
		(*str)++;
	}
	return (1);
}

static int	parse_number(char **str, int *number)
{
	int			sign;
	long long	value;

	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '\0')
		return (0);
	sign = get_sign(str);
	if (**str < '0' || **str > '9')
		return (-1);
	if (!parse_digits(str, sign, &value))
		return (-1);
	if (**str != '\0' && !(**str == ' ' || (**str >= 9 && **str <= 13)))
		return (-1);
	*number = (int)(value * sign);
	return (1);
}

static int	parse_argument(t_data *data, char *str)
{
	int		result;
	int		number;
	t_stack	*node;
	int		found;

	found = 0;
	while (1)
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
	return (found);
}

int	parse_args(t_data *data, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_argument(data, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
