/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:23:28 by melquiade         #+#    #+#             */
/*   Updated: 2024/07/28 22:06:46 by melquiade        ###   ########.fr       */
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
		printf("value is in string %s\n", argv[i]);
		current->next = (node_t *) malloc(sizeof(node_t));
		printf(" current val = %d\n head = %d\n", current->val, head->val);
		current = current->next;
		i++;
		//printf(" current val = %d\n head = %d\n", current->val, head->val);
	}
	current->val = ft_atoi(argv[i]);
	current->next = NULL;
	return(head);
}

int main(int argc, char * argv[])
{
	node_t *res = NULL;
	node_t *res_b = NULL;
	node_t *head = NULL;
	node_t *head_b = NULL;
	int	i;

	i = 0;
	res = ft_fill_stack(argv);
	res_b = ft_fill_stack(argv);
	head = res;
	head_b = res_b;
	//ft_sa(&res);

	while(head && i < 50)
	{
		printf("\nprinting stack a %d %p",head->val,head);
		head = head->next;
		i++;
	}
	while(head_b && i < 50)
	{
		printf("\nprinting stack b %d",head_b->val);
		head_b = head_b->next;
		i++;
	}
	//ft_pa(&res, &res_b);
	ft_rra(&res);
	printf("\nAFTER\n");
	while(res && i < 50)
	{
		printf("\nprinting stack a %d %p",res->val, res);
		res = res->next;
		i++;
	}
	while(res_b && i < 50)
	{
		printf("\nprinting stack b %d",res_b->val);
		res_b = res_b->next;
		i++;
	}
	printf("\n");
}
