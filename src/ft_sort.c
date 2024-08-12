/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:45:26 by melquiade         #+#    #+#             */
/*   Updated: 2024/08/12 16:31:47 by melquiade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


node_t	*ft_sort(int argc, char** argv)
{
	int steps;
	int nbrs_in_b;
	int lowest;
	node_t *res;
	node_t *res_b;
	int node;

	steps = 0;
	lowest = 0;
	nbrs_in_b = 0;
	node = 0;
	res_b = NULL;
	res = ft_fill_stack(argv);
	while (res)
	{
		// printf("\nstack_b at the beggining of the cycle: ");
		// print_stack(res_b);
		node = ft_cheapest_node(res, res_b, (argc - 1 - nbrs_in_b), nbrs_in_b);
		ft_count_rotation (&res, &res_b, node, (argc - 1 - nbrs_in_b), nbrs_in_b);
		ft_pb(&res, &res_b);
		steps++;
		nbrs_in_b++;
	}
	// printf("\nprinting stack_b before pushing to a \n");
	// print_stack(res_b);
	ft_final_rotate(&res_b, argc);
	// printf("\nprinting stack_b after rotation \n");
	// print_stack(res_b);
	while (res_b)
		ft_pa(&res, &res_b);
	// printf("\nprinting stack in ft_sort ");
	// print_stack(res);
	// fflush(stdout);
	ft_free (&res_b);
	// printf("final rotat\n");
	ft_final_rotate(&res, argc);
	return(res);
}
