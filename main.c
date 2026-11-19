/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjaradat <sjaradat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:29:47 by sjaradat          #+#    #+#             */
/*   Updated: 2026/11/19 15:52:02 by sjaradat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data		data;// data is the actual structure
	
	data = (t_data){0}; // It initializes every member of t_data to zero
	if (argc < 2)
		return (0);
	if (!parse_args(&data, argc, argv)) // if parsing fails
	{
		write(2, "Error\n", 6);
		free_stack(&data.a);
		free_stack(&data.b);
		return (1);
	}
	if (!validate_args(data.a))
	// data.a is a pointer to the first node of Stack A
	{
		write(2, "Error\n", 6);
		free_stack(&data.a);
		free_stack(&data.b);
		return (1); // Program finished with an error.
	}
	free_stack(&data.a);
	free_stack(&data.b);
	return (0); // Program finished successfully.
}
