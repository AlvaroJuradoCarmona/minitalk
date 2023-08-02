/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:34:34 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/12 13:34:34 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*dest;
	char	*src;

	dest = (char *) str1;
	src = (char *) str2;
	if (dest > src)
	{
		while (n--)
			dest[n] = src[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (str1);
}
