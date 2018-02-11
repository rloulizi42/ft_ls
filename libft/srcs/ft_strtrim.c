/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:36:23 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/15 17:24:06 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	start = i;
	i = ft_strlen(s) - 1;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i--;
	return (ft_strsub(s, start, i - start + 1));
}
