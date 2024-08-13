/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:23:28 by melquiade         #+#    #+#             */
/*   Updated: 2024/08/13 11:13:48 by melquiade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node_t *ft_fill_stack(char **argv)
{
	node_t * head = NULL;
	node_t * current = NULL;
	int i;

	i = 0;
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
	}
	current->val = ft_atoi(argv[i]);
	current->next = NULL;
	return(head);
}

int main(int argc, char * argv[])
{
	node_t *res = NULL;
	char **args;
	int len;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else if (argc == 1)
		return (0);
	else
		args = argv + 1;
	len = ft_len(args);
	if (ft_check_arg(argc, argv))
		return (1);
	//ft_sort(argc, argv);
	res = ft_fill_stack(args);
	fflush(stdout);
	if (ft_check_sorted(res))
		return(0);
	if(len < 6)
		ft_small_sort(&res, len);
	else
		res = ft_sort(argc, args);
	ft_free(&res);
// //	printf("\nAFTER\n steps =%d\n", steps);
// 	printf("\nprinting stack a: ");
	//  print_stack(res);
	return (0);
}
