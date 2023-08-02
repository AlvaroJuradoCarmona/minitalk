/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:32:29 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/12 13:32:29 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*arr;
	size_t	mult;

	mult = nitems * size;
	arr = malloc(mult);
	if (!arr || (nitems != 0 && size != mult / nitems))
		return (0);
	ft_bzero(arr, mult);
	return (arr);
}
