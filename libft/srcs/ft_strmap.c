/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:55:58 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/15 17:12:49 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*fresh;

	fresh = NULL;
	if (s != NULL)
	{
		len = ft_strlen(s);
		if (!(fresh = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			fresh[i] = f(s[i]);
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}
