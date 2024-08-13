/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:45:50 by melquiade         #+#    #+#             */
/*   Updated: 2024/08/12 19:12:50 by melquiade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	get_min(node_t **stack, int val)
// {
// 	node_t	*head;
// 	int		min;

// 	head = *stack;
// 	min = head->index;
// 	while (head->next)
// 	{
// 		head = head->next;
// 		if ((head->index < min) && head->index != val)
// 			min = head->index;
// 	}
// 	return (min);
// }

void ft_sort_three(node_t **stack)
{
    if (!*stack || !(*stack)->next || !(*stack)->next->next)
        return; // Already sorted or not enough elements
	// printf("we are in sort threee");

    // Assuming stack has exactly 3 elements
    int a = (*stack)->val;
    int b = (*stack)->next->val;
    int c = (*stack)->next->next->val;

    if (a > b && b > c)
	{
        ft_ra(stack);
        ft_sa(stack);
    }
	else if (a > b && a < c && b < c)
        ft_sa(stack);
    else if (a > b && a > c && b < c)
        ft_ra(stack);
	else if (a < b && b > c && a < c)
	{
        ft_sa(stack);
        ft_ra(stack);
	}
    else if (a < b && b > c && a > c)
	{
        ft_rra(stack);
    }
	// print_stack(*stack);
}

void ft_sort_four(node_t **stack_a)
{
	node_t *stack_b;
	int	min;

	// printf("we are in sort four");
	// print_stack(*stack_a);
	// fflush(stdout);
	stack_b = NULL;
	min = ft_min(*stack_a);
	while ((*stack_a)->val != min)
		ft_ra(stack_a);
	ft_pb(stack_a, &stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_a, &stack_b);
}

void ft_sort_five(node_t **stack_a)
{
	node_t *stack_b;
	int	min;

	// printf("we are in sort four");
	// print_stack(*stack_a);
	// fflush(stdout);
	stack_b = NULL;
	min = ft_min(*stack_a);
	while ((*stack_a)->val != min)
		ft_ra(stack_a);
	ft_pb(stack_a, &stack_b);
	min = ft_min(*stack_a);
	while ((*stack_a)->val != min)
		ft_ra(stack_a);
	ft_pb(stack_a, &stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_a, &stack_b);
	ft_pa(stack_a, &stack_b);
}

void ft_small_sort(node_t **stack_a, int size)
{

	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	 else if (size == 4)
		ft_sort_four(stack_a);
	else if (size == 5)
		ft_sort_five(stack_a);
	// print_stack(*stack_a);
}
