/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:35:18 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/12 13:35:18 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (len);
}

static int	word_size(char const *s, char c, int i)
{
	int	len;

	len = i;
	while (s[len] && s[len] != c)
		len++;
	return (len - i);
}

static void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**ft_insert_words(char const *s, char **str, char c)
{
	size_t	k;
	size_t	i;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			str[k++] = ft_substr(s, i, word_size(s, c, i));
			if (!str[k - 1])
			{
				free_split(str);
				return (0);
			}
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (0);
	str = ft_calloc(ft_words(s, c) + 1, sizeof(char *));
	if (!str)
		return (0);
	return (ft_insert_words(s, str, c));
}
