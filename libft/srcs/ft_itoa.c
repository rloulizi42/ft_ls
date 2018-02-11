/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 13:43:43 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/15 15:35:56 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t		i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void		ft_fill(char *fresh, int *i, int n)
{
	if (n < 10)
	{
		fresh[*i] = '0' + n;
		*i = *i + 1;
	}
	else
	{
		ft_fill(fresh, i, n / 10);
		ft_fill(fresh, i, n % 10);
	}
}

char			*ft_itoa(int n)
{
	char	*fresh;
	int		is_neg;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n = n * -1;
	}
	if (!(fresh = ft_strnew(sizeof(char) * get_size(n) + is_neg)))
		return (NULL);
	if (is_neg == 1)
		fresh[0] = '-';
	ft_fill(fresh + is_neg, &i, n);
	return (fresh);
}
