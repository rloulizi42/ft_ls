/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:35:51 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/14 14:01:29 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && j < ft_strlen(little))
			{
				if (j == ft_strlen(little) - 1)
					return ((char *)big + i);
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
