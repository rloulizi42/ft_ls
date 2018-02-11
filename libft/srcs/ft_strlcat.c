/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:39:52 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/14 13:35:46 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	if (size == ft_strlen(dst) + 1)
		return (ft_strlen(dst) + ft_strlen(src));
	else
	{
		dst_len = ft_strlen(dst);
		src_len = ft_strlen(src);
		ft_strncat(dst, (char *)src, (size - dst_len - 1));
		return (dst_len + src_len);
	}
}
