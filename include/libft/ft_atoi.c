/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpesan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:50:48 by lpesan            #+#    #+#             */
/*   Updated: 2023/09/07 14:33:12 by lpesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sig;
	long res;

	i = 0;
	sig = 1;
	res = 0;

	while ((8 < str[i] && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	else if (!('0' <= str[i] && str[i] <= '9'))
	{
		// printf("error in digit check ");
		return (0);
	}
	// printf("entering atoi char INTmax = %d sig = %d res = %ld \n", INT_MAX, sig, res);

	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((sig == 1 && res > (long)INT_MAX) || res > (long)INT_MAX + 1)
		{
			// printf("error in INT check");
			return (0);
		}
		i++;
	}
	return (sig * res);
}

/*
int main (void)
{
	char *str = "  +5456561";

	printf("%d", atoi(str));
}*/
