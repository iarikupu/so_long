/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@s42abudhabi.ae>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:04:04 by iarikupu          #+#    #+#             */
/*   Updated: 2021/10/08 12:13:15 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	char	*s;

	if (n == 0)
		return (NULL);
	s = (char *)src;
	if (*s == (char)c && n > 0)
		return ((char *)s);
	s++;
	n--;
	while (*s && *s != (char)c && n--)
		s++;
	if (*s == (char)c && n > 0)
		return ((char *)s);
	return (NULL);
}
