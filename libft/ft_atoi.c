/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:31:40 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/12 13:31:41 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space(char str)
{
	return (str == '\v' || str == '\f' || str == '\n'
		|| str == '\r' || str == '\t' || str == ' ');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sol;
	int	sign;

	i = 0;
	sol = 0;
	sign = 1;
	while (space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		sol *= 10;
		sol += str[i] - '0';
		i++;
	}
	return (sol * sign);
}
