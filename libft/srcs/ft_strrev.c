/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:44:55 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/17 14:45:31 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	swap;
	int		b;
	int		c;

	b = 0;
	c = ft_strlen(str) - 1;
	while (b < c)
	{
		swap = str[b];
		str[b] = str[c];
		str[c] = swap;
		b++;
		c--;
	}
	return (str);
}
