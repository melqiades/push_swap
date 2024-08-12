/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checks_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:59:35 by melquiade         #+#    #+#             */
/*   Updated: 2024/08/12 12:01:40 by melquiade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_arg(int argc, char *argv[])
{
	if (ft_doubles_check(argv) || ft_digit_check(argv) || ft_check_convert(argc, argv) || argc < 2)
		return (1);
	return(0);
}

int	ft_doubles_check(char **argv)
{
	int	i;
	int k;

	i = 1;
	k = 2;
	while(argv[i])
	{
		while(argv[k])
		{
			//printf("checking %s and %s\n", argv[i], argv[k]);
			if (!(ft_strncmp(argv[i], argv[k], 100)))
				return(1, ft_printf_e("Error1\n"));
			k++;
		}
		i++;
		k = i + 1;
	}
	return(0);
}

int ft_digit_check(char **argv)
{
	int i;
	int k;

	i = 1;
	k = 0;
	//printf("before while %d, argc = %d, \n", k, argc);
	while(argv[i])
	{
		while(argv[i][k])
		{
			//printf("i = %d, k = %d, argv is %c\n",i, k, argv[i][k]);
			if(ft_isdigit(argv[i][k]))
			{

				return (1, printf("Error2\n"));
			}
			k++;
		}
		i++;
		k = 0;
	}
	return (0);
}

int	ft_check_convert(int argc, char **argv)
{
	int i;

	i = 1;
	while(i < argc)
	{
		//printf("\nchecking k = %d i = %d and argv = %s\n ft_atoi_return = %d\n ", k,i, argv[i], ft_atoi(argv[i]));
		//fflush(stdout);
		if(!(ft_atoi(argv[i])) && (ft_strncmp(argv[i], "0", 1)))
			return (1, ft_printf_e("Error\n"));
		i++;
	}
	return(0);
}

int	ft_check_sorted(node_t *stack_a)
{
	int	i;

	i = stack_a->val;
	while (stack_a)
	{
		if (i > stack_a->val)
			return (0);
		i = stack_a->val;
		stack_a = stack_a->next;
	}
	return (1);
}
