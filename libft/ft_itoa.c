/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@s42abudhabi.ae>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:31:29 by iarikupu          #+#    #+#             */
/*   Updated: 2021/10/01 14:27:56 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digist(int n)
{
	size_t	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_write_nbr(char *dest, unsigned int n)
{
	if (n < 10)
		*dest = n + '0';
	else
	{
		*dest = n % 10 + '0';
		ft_write_nbr(dest - 1, n / 10);
	}
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*result;
	size_t			len;

	nbr = n;
	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		if (n < 0 )
			len = ft_count_digist(n) + 1;
		else
			len = ft_count_digist(n);
		result = (char *)malloc(sizeof(char) * (len + 1));
		if (!result)
			return (0);
		if (n < 0)
			ft_write_nbr((result + len - 1), -nbr);
		else
			ft_write_nbr((result + len - 1), nbr);
		if (n < 0)
			*result = '-';
		result[len] = '\0';
	}
	return (result);
}
