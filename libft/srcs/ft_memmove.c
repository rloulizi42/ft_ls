/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:09:56 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/17 16:22:23 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	str[n];

	if (n < 134217728)
	{
		ft_memcpy(str, (unsigned char *)s2, n);
		ft_memcpy((unsigned char *)s1, str, n);
		return ((unsigned char *)s1);
	}
	return (NULL);
}
