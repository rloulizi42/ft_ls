/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:51:13 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/15 13:18:47 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	while (n > 0 && *s != c)
	{
		*d = *s;
		n--;
		d++;
		s++;
	}
	if (n > 0)
	{
		*d = *s;
		d++;
		s++;
		return ((void*)d);
	}
	else
		return (NULL);
}
