/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@s42abudhabi.ae>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:29:38 by iarikupu          #+#    #+#             */
/*   Updated: 2021/10/01 16:50:42 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*srcptr;
	char	*desptr;

	if (!dest && !src)
		return (0);
	desptr = (char *)dest;
	srcptr = (char *)src;
	while (n-- > 0)
	{
		*desptr++ = *srcptr++;
	}
	return (dest);
}
