/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checks_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melquiade <melquiade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:59:35 by melquiade         #+#    #+#             */
/*   Updated: 2024/08/12 18:47:45 by melquiade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_arg(int argc, char **argv)
{
	char **args;

	// printf("in check arg");
	// fflush(stdout);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
	}
	else
		args = argv + 1 ;
	if (ft_doubles_check(args) || ft_digit_check(args) || ft_check_convert(argc, args))
		return (1);
	return(0);
}

int	ft_doubles_check(char **argv)
{
	int	i;
	int k;

	i = 0;
	k = 1;
	while(argv[i])
	{
		while(argv[k])
		{
			//  printf("checking %s and %s\n", argv[i], argv[k]);
			if (!(ft_strncmp(argv[i], argv[k], 100)))
				return(1, ft_printf_e("Error\n"));
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

	i = 0;
	k = 0;
	// printf("before while %d, argc = %d, \n", k, argc);
	while(argv[i])
	{
		while(argv[i][k])
		{
			// printf("i = %d, k = %d, argv is %c\n",i, k, argv[i][k]);
			if(ft_isdigit(argv[i][k]))
			{

				return (1, printf("Error\n"));
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

	i = 0;
	if (argc < 2)
		return(1, ft_printf_e("Error\n"));
	while(i < argc - 1)
	{
		// printf("\nchecking i = %d and argv = %s\n ft_atoi_return = %d\n ", i, argv[i], ft_atoi(argv[i]));
		// fflush(stdout);
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
