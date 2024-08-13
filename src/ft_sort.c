/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:45:26 by melquiade         #+#    #+#             */
/*   Updated: 2024/08/12 22:13:49 by melquiade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


node_t	*ft_sort(int argc, char** argv)
{
	int nbrs_in_b;
	int lowest;
	node_t *res;
	node_t *res_b;
	int node;

	lowest = 0;
	nbrs_in_b = 0;
	node = 0;
	res_b = NULL;
	res = ft_fill_stack(argv);
	while (res)
	{
		node = ft_cheapest_node(res, res_b, (argc - 1 - nbrs_in_b), nbrs_in_b);
		ft_count_rotation (&res, &res_b, node, (argc - 1 - nbrs_in_b), nbrs_in_b);
		ft_pb(&res, &res_b);
		nbrs_in_b++;
	}
	while (res_b)
		ft_pa(&res, &res_b);
	ft_free (&res_b);
	ft_final_rotate(&res, argc);
	return(res);
}
