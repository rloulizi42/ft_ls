/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_sharp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:56:38 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 19:27:24 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_static_sharp(t_mod *mod)
{
	char *temp;

	temp = mod->buff;
	if (mod->conv == 'o')
	{
		ft_zero(mod);
		mod->buff = ft_strjoin("0", mod->buff);
		free(temp);
	}
	else if (mod->conv == 'x')
	{
		ft_zero2(mod);
		mod->buff = ft_strjoin("0x", mod->buff);
		free(temp);
	}
	else if (mod->conv == 'X')
	{
		ft_zero2(mod);
		mod->buff = ft_strjoin("0X", mod->buff);
		free(temp);
	}
}

void	ft_static_sharp2(t_mod *mod)
{
	char	*temp;

	temp = mod->buff;
	if (mod->conv == 'o')
	{
		mod->buff = ft_strjoin("0", mod->buff);
		ft_min_wi(mod);
		ft_minus2(mod);
	}
	else if (mod->conv == 'x')
	{
		mod->buff = ft_strjoin("0x", mod->buff);
		free(temp);
	}
	else if (mod->conv == 'X')
	{
		mod->buff = ft_strjoin("0X", mod->buff);
		free(temp);
	}
}

void	ft_static_sharpp(t_mod *mod)
{
	char	*temp;

	if (mod->conv == 'o' && mod->buff[0] != '0')
	{
		temp = mod->buff;
		mod->buff = ft_strjoin("0", mod->buff);
		free(temp);
	}
	else if (mod->conv == 'x' && (mod->buff[0] != '\0' &&
				mod->buff[0] != '0'))
	{
		temp = mod->buff;
		mod->buff = ft_strjoin("0x", mod->buff);
		free(temp);
	}
	else if (mod->conv == 'X' && mod->buff[0] != '0')
	{
		temp = mod->buff;
		mod->buff = ft_strjoin("0X", mod->buff);
		free(temp);
	}
	ft_min_wi(mod);
}
