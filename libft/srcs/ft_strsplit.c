/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 13:42:31 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/15 16:52:45 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_len(char const *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static void		init(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**tab;
	int		n;

	init(&n, &i);
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*)
					* ft_word_number((char*)s, c) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			tab[n] = (char*)ft_strnew(sizeof(char) * get_str_len(s + i, c) + 1);
			ft_strncpy(tab[n], (char*)s + i, get_str_len(s + i, c));
			n++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	tab[n] = 0;
	return (tab);
}
