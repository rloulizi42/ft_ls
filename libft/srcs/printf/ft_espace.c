/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_espace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:01:37 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 13:38:41 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_espace(t_mod *mod)
{
	if (!(mod->options))
		return ;
	if (!ft_strcmp(mod->options, " "))
		ft_static_esp(mod);
}

void	ft_more(t_mod *mod)
{
	if (!(mod->options))
		return ;
	if (!ft_strcmp(mod->options, "+"))
		ft_static_more(mod);
}

void	ft_more3(t_mod *mod)
{
	if (!(mod->options))
		return ;
	if (!ft_strcmp(mod->options, "+-") || !ft_strcmp(mod->options, "-+"))
		ft_static_more3(mod);
}

void	ft_more2(t_mod *mod)
{
	int		i;
	char	*temp;

	if (!(mod->options))
		return ;
	if (!ft_strcmp(mod->options, "0+") || !ft_strcmp(mod->options, "+0"))
	{
		if (mod->conv != '%')
		{
			i = ft_atoi(mod->buff);
			if (i >= 0)
			{
				ft_zero1(mod);
				temp = mod->buff;
				mod->buff = ft_strjoin("+", mod->buff);
				free(temp);
			}
			if (i < 0)
			{
				ft_zero3(mod);
			}
		}
	}
}

void	ft_sharp2(t_mod *mod)
{
	if (!(mod->options))
		return ;
	if (!ft_strcmp(mod->options, "#0") || !ft_strcmp(mod->options, "0#"))
		ft_static_sharp(mod);
}
