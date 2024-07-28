/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:29:07 by lpesan            #+#    #+#             */
/*   Updated: 2024/07/28 22:07:39 by melquiade        ###   ########.fr       */
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

#endif
