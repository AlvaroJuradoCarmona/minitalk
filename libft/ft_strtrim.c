/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:36:23 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/12 13:36:23 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (!s1 || !set)
		return (0);
	i = 0;
	k = 0;
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	if (i - 1 == j)
		return (ft_strdup(""));
	while (j != 0 && ft_is_set(s1[j], set))
		j--;
	str = (char *) ft_calloc(j - i + 2, sizeof(char));
	if (!str)
		return (0);
	while (i <= j)
		str[k++] = s1[i++];
	return (str);
}
