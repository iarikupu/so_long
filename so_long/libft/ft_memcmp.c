/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@s42abudhabi.ae>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:32:45 by iarikupu          #+#    #+#             */
/*   Updated: 2021/10/01 17:03:53 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s1ptr;
	char	*s2ptr;

	s1ptr = (char *)s1;
	s2ptr = (char *)s2;
	while (n-- > 0)
	{
		if (*s1ptr != *s2ptr)
			return ((unsigned char)*s1ptr - (unsigned char)*s2ptr);
		s1ptr++;
		s2ptr++;
	}
	return (0);
}
