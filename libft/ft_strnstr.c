/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:36:11 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/12 13:36:11 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_tmp;
	char	*little_tmp;
	size_t	size;

	size = len - ft_strlen(little) + 1;
	if (!*little)
		return ((char *) big);
	if (!*big || ft_strlen(little) > len)
		return (0);
	while (size-- && *big)
	{
		big_tmp = (char *) big;
		little_tmp = (char *) little;
		while (*big_tmp != '\0' && *little_tmp == *big_tmp)
		{
			little_tmp++;
			big_tmp++;
		}
		if (!(*little_tmp))
			return ((char *) big);
		big++;
	}
	return (0);
}
