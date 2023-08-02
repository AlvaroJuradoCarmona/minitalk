/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:35:28 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/12 13:35:28 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*cpy;
	size_t	len;

	len = ft_strlen(string);
	cpy = malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (0);
	ft_strlcpy(cpy, string, len + 1);
	return (cpy);
}
