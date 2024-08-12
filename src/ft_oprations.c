/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oprations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:29:11 by melquiade         #+#    #+#             */
/*   Updated: 2024/08/12 15:40:57 by melquiade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(node_t **stack_a)
{
	node_t	*temp_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return(0);
	//printf("BEFORE\nstack_a = %p\nstack_a->next = %p\nstack_a->next->next = %p \n",*stack_a, *stack_a->next, *stack_a->next->next);
	temp_node = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	temp_node->next = *stack_a;
	*stack_a = temp_node;
	ft_printf("sa\n");
	return (0);
}
int	ft_sb(node_t **stack_b)
{
	node_t	*temp_node;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return(0);
	//printf("BEFORE\nstack_a = %p\nstack_a->next = %p\nstack_a->next->next = %p \n",*stack_a, *stack_a->next, *stack_a->next->next);
	temp_node = (*stack_b)->next;
	(*stack_b)->next = (*stack_b)->next->next;
	temp_node->next = *stack_b;
	*stack_b = temp_node;
	ft_printf("sb\n");
	return (0);
}

int	ft_ss(node_t **stack_a, node_t **stack_b)
{
	ft_sa(stack_a);
	ft_sa(stack_b);
	ft_printf("ss\n");
	return (0);
}

int	ft_pa(node_t **stack_a, node_t **stack_b)
{
	node_t	*temp_node;

	if (*stack_b == NULL)
		return(0);
	temp_node = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = temp_node;
	ft_printf("pa\n");
	return(0);
}

// int	ft_pb(node_t **stack_a, node_t **stack_b)
// {
// 	node_t	*temp_node;

// 	if (*stack_a == NULL)
// 		return(0);
// 	temp_node = (*stack_a)->next;
// 	(*stack_a)->next = *stack_b;
// 	*stack_b = *stack_a;
// 	*stack_a = temp_node;
// 	ft_printf("pb\n");
// 	return(0);
// }

int ft_pb(node_t **stack_a, node_t **stack_b)
{
    node_t *temp_node;

    // Check if stack_a is empty
    if (*stack_a == NULL)
        return (0);

    // Store the node to be moved (current head of stack_a)
    temp_node = *stack_a;

    // Move the head of stack_a to stack_b
    *stack_a = (*stack_a)->next;  // Update stack_a to the next node
    temp_node->next = *stack_b;   // Link the moved node to the top of stack_b
    *stack_b = temp_node;         // Update stack_b to point to the moved node

    ft_printf("pb\n");
    return (0);
}

int	ft_ra(node_t **stack_a)
{
	node_t	*temp_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return(0);

	temp_node = *stack_a;
	while(temp_node->next)
		temp_node = temp_node->next;
	temp_node->next = *stack_a;
	*stack_a = (*stack_a)->next;
	(temp_node)->next->next = NULL;
	ft_printf("ra\n");
	return(0);
}

int	ft_rb(node_t **stack_b)
{
	node_t	*temp_node;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return(0);

	temp_node = *stack_b;
	while(temp_node->next)
		temp_node = temp_node->next;
	temp_node->next = *stack_b;
	*stack_b = (*stack_b)->next;
	(temp_node)->next->next = NULL;
	ft_printf("rb\n");
	return(0);
}

// int	ft_rb(node_t **stack_b)
// {
//     node_t	*temp_node;
//     node_t  *first_node;

//     // Check if the stack is empty or contains only one node
//     if (*stack_b == NULL || (*stack_b)->next == NULL)
//         return (0);

//     // Save the first node (current head)
//     first_node = *stack_b;

//     // Traverse to the last node
//     temp_node = *stack_b;
//     while (temp_node->next)
//         temp_node = temp_node->next;

//     // Move the first node to the end
//     temp_node->next = first_node;

//     // Update the head to the second node
//     *stack_b = (*stack_b)->next;

//     // Now, the first node (old head) should point to NULL
//     first_node->next = NULL;

//     ft_printf("rb\n");
//     return (0);
// }

int	ft_rr(node_t **stack_a, node_t **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	ft_printf("rr\n");
	return (0);
}

int	ft_rra(node_t **stack_a)
{
	node_t	*temp_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return(0);

	temp_node = *stack_a;
	while(temp_node->next->next)
		temp_node = temp_node->next;
	temp_node->next->next = *stack_a;
	*stack_a = temp_node->next;
	(temp_node)->next= NULL;
	ft_printf("rra\n");
	return(0);
}

int	ft_rrb(node_t **stack_b)
{
	node_t	*temp_node;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return(0);

	temp_node = *stack_b;
	while(temp_node->next->next)
		temp_node = temp_node->next;
	temp_node->next->next = *stack_b;
	*stack_b = temp_node->next;
	(temp_node)->next= NULL;
	ft_printf("rrb\n");
	return(0);
}

int	ft_rrr(node_t **stack_a, node_t **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	ft_printf("rrr\n");
	return (0);
}
