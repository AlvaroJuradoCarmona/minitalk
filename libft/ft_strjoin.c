/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:35:37 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/12 13:35:37 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	concat = malloc(sizeof(char) * len + 1);
	if (!concat)
		return (0);
	ft_strlcpy(concat, s1, len + 1);
	ft_strlcat(concat, s2, len + 1);
	return (concat);
}
