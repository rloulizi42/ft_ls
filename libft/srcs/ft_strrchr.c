/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:41:08 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/15 14:12:27 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		str_len;
	char	a;

	str_len = (int)ft_strlen(str);
	i = 0;
	a = c;
	while (str_len >= i)
	{
		if (a == str[str_len])
			return ((char*)str + str_len);
		str_len = str_len - 1;
	}
	return (NULL);
}
