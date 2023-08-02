/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:34:24 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/12 13:34:24 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	while (n != 0)
	{
		if (*(unsigned char *) str1 != *(unsigned char *) str2)
			return (*(unsigned char *) str1 - *(unsigned char *) str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
