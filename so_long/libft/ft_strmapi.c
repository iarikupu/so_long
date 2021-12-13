/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@s42abudhabi.ae>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 10:26:57 by iarikupu          #+#    #+#             */
/*   Updated: 2021/10/06 16:22:31 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	i;

	i = 0;
	if (! s)
		return (NULL);
	if (! f)
		return (NULL);
	r = ft_strdup(s);
	if (! r)
		return (NULL);
	while (r[i])
	{
		r[i] = f(i, r[i]);
		i++;
	}
	return (r);
}
