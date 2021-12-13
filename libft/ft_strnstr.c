/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@s42abudhabi.ae>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:34:23 by iarikupu          #+#    #+#             */
/*   Updated: 2021/10/06 12:40:09 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t	nl;

	if (*ndl == '\0')
		return ((char *)hay);
	if (! *hay)
		return (NULL);
	nl = ft_strlen(ndl);
	while (*hay && len-- > 0)
	{
		if (*hay == *ndl && nl <= len + 1)
			if (ft_strncmp(hay, ndl, nl) == 0)
				return ((char *)hay);
		hay++;
	}
	return (NULL);
}
