/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:33:56 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/12 13:33:56 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*first;
	void	*r_func;

	if (!lst || !f || !del)
		return (0);
	first = 0;
	while (lst)
	{
		r_func = f(lst->content);
		cpy = ft_lstnew(r_func);
		if (!cpy)
		{
			del(r_func);
			ft_lstclear(&first, del);
			return (0);
		}
		lst = lst -> next;
		ft_lstadd_back(&first, cpy);
	}
	return (first);
}
