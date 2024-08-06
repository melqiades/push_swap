/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:23:28 by melquiade         #+#    #+#             */
/*   Updated: 2024/08/05 16:17:04 by melquiade        ###   ########.fr       */
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
	// int	i;
	// int k;

	// i = 1;
	// k = 0;
	// //printf("before while %d, argc = %d, \n", k, argc);
	// while(argv[i])
	// {
	// 	while(argv[i][k])
	// 	{
	// 		if(ft_isdigit(argv[i][k]))
	// 			return (1, ft_printf_e("Error\n"));
	// 		k++;
	// 	}
	// 	i++;
	// }
	// i = 1;
	// k = 0;
	// while(i < argc)
	// {
	// 	printf("\nchecking k = %d i = %d and argv = %s\n ft_atoi_return = %d\n ", k,i, argv[i], ft_atoi(argv[i]));
	// 	//fflush(stdout);
	// 	if(!(ft_atoi(argv[i++])))
	// 		return (1, ft_printf_e("Error\n"));
	// }
	// i = 1;
	// k = 2;
	// while(argv[i])
	// {
	// 	while(argv[k])
	// 	{
	// 		//printf("checking %s and %s\n", argv[i], argv[k]);
	// 		if (!(ft_strncmp(argv[i], argv[k], 100)))
	// 			return(1, ft_printf_e("Error\n"));
	// 		k++;
	// 	}
	// 	i++;
	// 	k = i + 1;
	// }
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
	int	i;

	i = 0;

	if (argc < 2)
		return (1);
	if (ft_check_arg(argc, argv))
		return (1);
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
	ft_rr(&res, &res_b);
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
