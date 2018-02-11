/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_wi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:32:33 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 16:24:23 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_min_wi(t_mod *mod)
{
	char *s;
	char *temp;

	if (!(mod->buff))
		return ;
	if (mod->min_width > (int)ft_strlen(mod->buff))
	{
		s = ft_memalloc(ft_strlen(mod->buff) + mod->min_width);
		s = ft_memset(s, ' ', mod->min_width - ft_strlen(mod->buff));
		temp = mod->buff;
		mod->buff = ft_strjoin(s, mod->buff);
		free(temp);
		free(s);
	}
}

void	ft_zero1(t_mod *mod)
{
	size_t	i;
	int		j;

	if (!(mod->options))
		return ;
	j = 0;
	i = ft_strlen(mod->buff);
	mod->buff = ft_strtrim(mod->buff);
	if (mod->buff[0] == '-')
	{
		j++;
		mod->buff++;
	}
	while (ft_strlen(mod->buff) < i - 1)
		mod->buff = ft_strjoin("0", mod->buff);
	if (j == 1)
		mod->buff[0] = '-';
}

void	ft_zero2(t_mod *mod)
{
	size_t	i;
	int		j;

	if (!(mod->options))
		return ;
	j = 0;
	i = ft_strlen(mod->buff);
	mod->buff = ft_strtrim(mod->buff);
	if (mod->buff[0] == '-')
	{
		j++;
		mod->buff++;
	}
	while (ft_strlen(mod->buff) < i - 2)
		mod->buff = ft_strjoin("0", mod->buff);
	if (j == 1)
		mod->buff[0] = '-';
}

void	ft_zero3(t_mod *mod)
{
	size_t	i;
	int		j;

	if (!(mod->options))
		return ;
	j = 0;
	i = ft_strlen(mod->buff);
	mod->buff = ft_strtrim(mod->buff);
	if (mod->buff[0] == '-')
	{
		j++;
		mod->buff++;
	}
	while (ft_strlen(mod->buff) < i)
		mod->buff = ft_strjoin("0", mod->buff);
	if (j == 1)
		mod->buff[0] = '-';
}

void	ft_zero(t_mod *mod)
{
	if (!(mod->options))
		return ;
	if (!ft_strcmp(mod->options, "0"))
		ft_static_zero(mod);
}
