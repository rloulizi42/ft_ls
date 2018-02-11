/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_espace2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 18:43:27 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 19:28:29 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_sharp3(t_mod *mod)
{
	if (!(mod->options))
		return ;
	if (!ft_strcmp(mod->options, "#-") || !ft_strcmp(mod->options, "-#"))
	{
		mod->buff = ft_strtrim(mod->buff);
		if ((mod->conv == 'o' || mod->conv == 'x' ||
					mod->conv == 'X') && mod->buff[0] != '0')
			ft_static_sharp2(mod);
	}
}

void		ft_sharp(t_mod *mod)
{
	char	*temp;

	if (!(mod->options))
		return ;
	if (!ft_strcmp(mod->options, "#"))
	{
		temp = mod->buff;
		mod->buff = ft_strtrim(mod->buff);
		free(temp);
		if ((mod->conv == 'o' || mod->conv == 'x' ||
					mod->conv == 'X'))
			ft_static_sharpp(mod);
	}
}

void		ft_minus2(t_mod *mod)
{
	size_t	i;

	if (!(mod->options))
		return ;
	i = ft_strlen(mod->buff);
	mod->buff = ft_strtrim(mod->buff);
	while (ft_strlen(mod->buff) < i)
		mod->buff = ft_strjoin(mod->buff, " ");
}

void		ft_minus(t_mod *mod)
{
	size_t	i;
	char	*temp;

	if (!(mod->options))
		return ;
	if (!ft_strcmp(mod->options, "-"))
	{
		i = ft_strlen(mod->buff);
		temp = mod->buff;
		mod->buff = ft_strtrim(mod->buff);
		free(temp);
		while (ft_strlen(mod->buff) < i)
		{
			temp = mod->buff;
			mod->buff = ft_strjoin(mod->buff, " ");
			free(temp);
		}
	}
}
