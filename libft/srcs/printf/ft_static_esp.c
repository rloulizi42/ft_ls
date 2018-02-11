/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_esp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 18:52:36 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 19:13:23 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_static_more3(t_mod *mod)
{
	if (mod->conv != '%')
		ft_static2more3(mod);
}

void	ft_static_more(t_mod *mod)
{
	if (mod->conv != '%')
		ft_static2more(mod);
}

void	ft_static_esp(t_mod *mod)
{
	if (mod->conv != '%')
		ft_static2esp(mod);
}

void	ft_static_zero(t_mod *mod)
{
	int		j;
	size_t	i;
	char	*temp;

	j = 0;
	i = ft_strlen(mod->buff);
	temp = mod->buff;
	mod->buff = ft_strtrim(mod->buff);
	free(temp);
	if (mod->buff[0] == '-')
	{
		j++;
		mod->buff++;
	}
	if (mod->min_width > mod->precision && mod->precision != -1)
	{
		i = mod->min_width - mod->precision;
		while (i > 0)
		{
			mod->buff = ft_strjoin(" ", mod->buff);
			i--;
		}
	}
	ft_static2zero(mod, j, i);
}
