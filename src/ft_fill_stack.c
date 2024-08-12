/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:23:28 by melquiade         #+#    #+#             */
/*   Updated: 2024/08/12 11:27:47 by melquiade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node_t *ft_fill_stack(char **argv)
{
	node_t * head = NULL;
	node_t * current = NULL;
	int i;

	i = 1;
	head = (node_t *) malloc(sizeof(node_t));
	if (head == NULL)
		return (NULL);
	current = head;
	while(argv[i + 1])
	{
		current->val = ft_atoi(argv[i]);
		current->next = (node_t *) malloc(sizeof(node_t));
		current = current->next;
		i++;
		//printf(" current val = %d\n head = %d\n", current->val, head->val);
	}
	current->val = ft_atoi(argv[i]);
	current->next = NULL;
	return(head);
}
int ft_check_arg(int argc, char *argv[])
{
	if (ft_doubles_check(argv) || ft_digit_check(argv) || ft_check_convert(argc, argv))
		return (1);
	return(0);
}


int main(int argc, char * argv[])
{
	node_t *res = NULL;
	node_t *res_b = NULL;
	node_t *head = NULL;
	node_t *head_b = NULL;
	node_t *temp = NULL;
	int	i;
	int node = 0;
	int lowest;

	i = 0;
	lowest = 0;

	if (argc < 2)
		return (1);
	if (ft_check_arg(argc, argv))
		return (1);
	res = ft_fill_stack(argv);

	int steps = 0;
	int nbrs_in_b = 0;
	while (res)
	{
		node = ft_cheapest_node(res, res_b, (argc - 1 - nbrs_in_b), nbrs_in_b);
		// printf("cheapest node %d argc = %d\n", node, argc);
		ft_count_rotation (&res, &res_b, node, (argc - 1 - nbrs_in_b), nbrs_in_b);
		fflush(stdout);
		ft_pb(&res, &res_b);
		steps++;
		nbrs_in_b++;
		// printf("\nprinting stack a: ");
		// print_stack(res);
		// printf("printing stack b: ");
		// print_stack(res_b);
		fflush(stdout);
	}
	// printf("\nprinting stack a: ");
	// print_stack(res);
	// printf("printing stack b: ");
	// print_stack(res_b);
	while (res_b)
	{
		ft_pa(&res, &res_b);

	head = res;
	head_b = res_b;
	}
	// printf("\nprinting stack a: ");
	// print_stack(res);
	lowest = ft_min_pos(res, ft_min(res)) + 1;
	printf("lowest %d argc %d", lowest, argc);
	if (lowest > ((argc - 1)/2))
	{
		while ((argc - 1 - lowest) !=0)
		{
			 ft_rra(&res);
			 lowest++;
		}
	}
	else
	{
		while (lowest !=0)
			{
				ft_ra(&res);
				lowest--;
			}
	}

	printf("\nAFTER\n steps =%d\n", steps);
	printf("\nprinting stack a: ");
	print_stack(res);
	printf("printing stack b: ");
	print_stack(res_b);
	printf("argc = %d\n", argc);
}
