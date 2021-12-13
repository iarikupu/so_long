/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@s42abudhabi.ae>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:48:16 by iarikupu          #+#    #+#             */
/*   Updated: 2021/10/02 10:06:40 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dptr;
	char	*sptr;

	dptr = (char *)dst;
	sptr = (char *)src;
	if (dst == NULL && src == NULL)
		return (0);
	if (dptr < sptr)
		ft_memcpy(dst, src, len);
	else
	{
		while (len-- > 0)
			*(dptr + len) = *(sptr + len);
	}
	return (dst);
}
