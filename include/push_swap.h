/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:29:07 by lpesan            #+#    #+#             */
/*   Updated: 2024/08/12 18:43:20 by melquiade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include <stdint.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

node_t *ft_fill_stack(char **argv);
int	ft_sa(node_t **stack_a);
int	ft_pa(node_t **stack_a, node_t **stack_b);
int	ft_pb(node_t **stack_a, node_t **stack_b);
int	ft_ra(node_t **stack_a);
int	ft_rb(node_t **stack_b);
int	ft_rra(node_t **stack_a);
int	ft_rrb(node_t **stack_b);
int	ft_check_convert(int argc, char **argv);
int ft_digit_check(char **argv);
int	ft_doubles_check(char **argv);
int	ft_ss(node_t **stack_a, node_t **stack_b);
int	ft_rr(node_t **stack_a, node_t **stack_b);
int	ft_rrr(node_t **stack_a, node_t **stack_b);
int	ft_min(node_t *stack);
int ft_rot_needed(node_t *stack_a, node_t *stack_b, int c);
int ft_abs_value (int n);
void print_stack(node_t *stack);
int ft_cheapest_node(node_t *stack_a, node_t *stack_b, int nodes_in_a, int nodes_in_b);
int ft_count_rotation (node_t **stack_a, node_t **stack_b, int node, int nodes_in_a, int nodes_in_b);
void	ft_perform_rotation(node_t **stack, int turns, int button);
int	ft_min_pos(node_t *stack, int min);
int	ft_check_sorted(node_t *stack_a);
void	ft_free(node_t **lst);
node_t	*ft_sort(int argc, char** argv);
void	ft_final_rotate (node_t **stack, int argc);
int ft_check_arg(int argc, char *argv[]);
void	ft_small_sort(node_t **stack_a, int argc);
void ft_sort_three(node_t **stack);
void ft_sort_four(node_t **stack_a);
void ft_sort_five(node_t **stack_a);
int	ft_len(char **args);

#endif
