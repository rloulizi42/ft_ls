/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:23:20 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/24 19:42:49 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_size(size_t nb, int base, int *len)
{
	if (nb >= (size_t)base)
	{
		get_size(nb / base, base, len);
		get_size(nb % base, base, len);
	}
	else
		(*len)++;
}

static void		ft_fill_str(char *str, size_t n, int *index, int base)
{
	if (n >= (size_t)base)
	{
		ft_fill_str(str, n % base, index, base);
		ft_fill_str(str, n / base, index, base);
	}
	else
	{
		if (n > 9)
		{
			str[*index] = 'a' - 10 + n;
			*index = *index + 1;
		}
		else
		{
			str[*index] = '0' + n;
			*index = *index + 1;
		}
	}
}

char			*ft_itoa_base(size_t n, int base)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	get_size(n, base, &len);
	str = (char*)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	ft_fill_str(str, n, &i, base);
	return (ft_strrev(str));
}
