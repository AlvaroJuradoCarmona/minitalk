/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:51:15 by ajurado-          #+#    #+#             */
/*   Updated: 2023/06/17 18:20:42 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_signal(char *str, int pid, int len)
{
	int	bit;
	int	i;

	i = 0;
	while (i <= len)
	{
		bit = -1;
		while (++bit < 7)
		{
			if ((str[i] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Wrong number of arguments!!", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_signal(argv[2], pid, ft_strlen(argv[2]));
	ft_putstr_fd(("Message sent: "), 1);
	ft_putstr_fd(argv[2], 1);
	return (0);
}
