/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@s42abudhabi.ae>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:51:44 by iarikupu          #+#    #+#             */
/*   Updated: 2021/10/08 16:20:23 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*r;

	if (! lst || ! f)
		return (0);
	r = ft_lstnew(f(lst->content));
	if (! r)
		return (0);
	t = r;
	lst = lst->next;
	while (lst)
	{
		t->next = ft_lstnew(f(lst->content));
		if (! t->next)
			return (0);
		t = t->next;
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (r);
}
