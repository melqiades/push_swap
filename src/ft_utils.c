/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:36:33 by melquiade         #+#    #+#             */
/*   Updated: 2024/08/12 18:46:21 by melquiade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(node_t *stack)
{
	int min;

	min = stack->val;
		while(stack)
		{
			if(min > stack->val)
				min = stack->val;
			stack = stack->next;
		}
		return (min);
}
int	ft_min_pos(node_t *stack, int min)
{
	int pos;

	pos = 0;
	while(stack->val != min)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}


int ft_rot_needed(node_t *stack_a, node_t *stack_b, int c)
{
	int diff = 0;
	int diff_min = INT_MAX;
	int i = 0;
	int turns = 0;

	///printf("res val = %d, res_b->val = %d\n", res->val, res_b->val);
	while (c != 0)
	{
		stack_a = stack_a->next;
		c--;
	}
	while (stack_b)
	{
		diff = stack_a->val - stack_b->val;
		// printf("stack_a->val = %d - stack_b->val = %d", stack_a->val, stack_b->val);
		if(diff < 0 && ft_abs_value(diff) < diff_min)
		{
			diff_min = ft_abs_value(diff);
			turns = i + 1;
			// printf("in if turns = %d\n", turns);

		}
		else if (diff > 0 && diff < diff_min)
		{
			diff_min = diff;
			turns = i;
			// printf("in elif turns = %d\n", turns);
		}
		i++;
		stack_b = stack_b->next;
	}
	//printf("Calculated turns: %d\n", turns);
	return (turns);
}

// this function returns the position of the node in stack_a that is cheapest to move
// to stack_b
int ft_cheapest_node(node_t *stack_a, node_t *stack_b, int nodes_in_a, int nodes_in_b)
{
	int turns_min;
	int turns;
	int node_pos;
	int node;

	turns_min = INT_MAX;
	turns = 0;
	node_pos = 0;
	node = 0;
	while(stack_a)
	{
		turns = ft_rot_needed(stack_a, stack_b, 0);
		if (nodes_in_a - node_pos < node_pos && nodes_in_b - turns < turns)
			turns = (nodes_in_b - turns) + (nodes_in_a - node_pos);
		else if (nodes_in_a - node_pos < node_pos && nodes_in_b - turns > turns)
			turns = turns + (nodes_in_a - node_pos);
		else if (nodes_in_a - node_pos > node_pos && nodes_in_b - turns < turns)
			turns = (nodes_in_b - turns)  + node_pos;
		else
			turns = turns + node_pos;
		if (turns < turns_min)
		{
			turns_min = turns;
			node = node_pos;
		}
		node_pos++;
		stack_a = stack_a->next;
	}
	return(node);
}

int ft_count_rotation (node_t **stack_a, node_t **stack_b, int node, int nodes_in_a, int nodes_in_b)
{
	int turns_a;
	int turns_b;

	turns_a = node;
	turns_b = ft_rot_needed(*stack_a, *stack_b, node);
	// printf("turns_a = %d,  turns_b = %d      \n", turns_a, turns_b);

	if ((nodes_in_a - node < node) && (nodes_in_b - turns_b < turns_b))
	{
		turns_a = -(nodes_in_a - node);
		turns_b = -(nodes_in_b - turns_b);
	}
	else if ((nodes_in_a - node < node) && (nodes_in_b - turns_b > turns_b))
		turns_a = -(nodes_in_a - node);
	else if ((nodes_in_a - node > node) && (nodes_in_b - turns_b < turns_b))
		turns_b = -(nodes_in_b - turns_b);
	// printf("Rotating a turns a = %d nodes_in_a = %d \n", turns_a, nodes_in_a);
	ft_perform_rotation(stack_a, turns_a, 0);
	// printf("Rotating b turns b = %d nodes_in_b = %d \n", turns_b, nodes_in_b);
	ft_perform_rotation(stack_b, turns_b, 1);
}

void	ft_perform_rotation(node_t **stack, int turns, int button)
{
	if (turns < 0)
	{
		while (turns++ != 0)
			if(button)
				ft_rrb(stack);
			else
				ft_rra(stack);
	}
	else
		while (turns != 0)
		{
			// printf ("rotating stack_vale = %d, turns = %d\n", (*stack)->val, turns);
			if(button)
				ft_rb(stack);
			else
				ft_ra(stack);
			turns--;
		}
}

int ft_abs_value (int n)
{
	if (n < 0)
		n = n * (-1);
	return (n);
}

void print_stack(node_t *stack)
{
    while (stack)
	{
        printf("%d ", stack->val);
        stack = stack->next;
    }
    printf("\n");
}

void	ft_final_rotate (node_t **stack, int argc)
{
	int	lowest;

	lowest = ft_min_pos(*stack, ft_min(*stack));
	// printf("lowest %d argc %d", lowest, argc);
	if (lowest > ((argc - 1)/2))
	{
		while ((argc - 1 - lowest) !=0)
		{
			 ft_rra(stack);
			 lowest++;
		}
	}
	else
	{
		while (lowest !=0)
			{
				ft_ra(stack);
				lowest--;
			}
	}
}

int	ft_len(char **args)
{
	int	i;

	i = 1;
	while (args[i])
		i++;
	return(i);

}
