/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:52:52 by rloulizi          #+#    #+#             */
/*   Updated: 2018/01/26 19:10:22 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nlen(char *str, char c)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (!str)
		str = ft_strnew(1);
	while (!(ft_strchr(str, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
			break ;
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = ft_strjoin(str, buf);
		ft_strdel(&str);
		str = tmp;
	}
	if (ft_strlen(str) == 0)
		return (0);
	*line = ft_strsub(str, 0, nlen(str, '\n'));
	tmp = ft_strsub(str, nlen(str, '\n') + 1, ft_strlen(&str[nlen(str, '\n')]));
	ft_strdel(&str);
	str = tmp;
	return (1);
}
