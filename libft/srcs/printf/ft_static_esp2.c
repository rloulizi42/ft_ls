/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_esp2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:27:24 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 19:21:58 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_static2more3(t_mod *mod)
{
	int		i;
	char	*temp;

	i = ft_atoi(mod->buff);
	if (i >= 0)
	{
		if (mod->min_width > mod->precision)
		{
			temp = mod->buff;
			mod->buff = ft_strtrim(mod->buff);
			free(temp);
			temp = mod->buff;
			mod->buff = ft_strjoin("+", mod->buff);
			free(temp);
			i = mod->min_width - mod->precision;
			while (i - 1 > 0)
			{
				mod->buff = ft_strjoin(mod->buff, " ");
				i--;
			}
		}
		else
			mod->buff = ft_strjoin("+", mod->buff);
	}
}

void	ft_static2esp(t_mod *mod)
{
	int		i;
	char	*temp;

	i = ft_atoi(mod->buff);
	if (i < 0)
		return ;
	if (i >= 0)
	{
		temp = mod->buff;
		mod->buff = ft_strjoin(" ", mod->buff);
		free(temp);
		if (mod->min_width > mod->precision)
		{
			temp = mod->buff;
			mod->buff = ft_strtrim(mod->buff);
			free(temp);
			i = mod->min_width - mod->precision;
			while (i-- > 0)
			{
				temp = mod->buff;
				mod->buff = ft_strjoin(" ", mod->buff);
				free(temp);
			}
		}
	}
}

void	ft_static2more(t_mod *mod)
{
	int		i;
	char	*temp;

	i = ft_atoi(mod->buff);
	if (i >= 0)
	{
		if (mod->min_width > mod->precision)
		{
			temp = mod->buff;
			mod->buff = ft_strtrim(mod->buff);
			free(temp);
			temp = mod->buff;
			mod->buff = ft_strjoin("+", mod->buff);
			free(temp);
			i = mod->min_width - mod->precision;
			while (i - 1 > 0)
			{
				mod->buff = ft_strjoin(" ", mod->buff);
				i--;
			}
		}
		else
			mod->buff = ft_strjoin("+", mod->buff);
	}
}

void	ft_static2zero(t_mod *mod, int j, size_t i)
{
	char *temp;

	while (ft_strlen(mod->buff) < i)
	{
		if (j == 0)
		{
			temp = mod->buff;
			mod->buff = ft_strjoin("0", mod->buff);
			free(temp);
		}
		else
			mod->buff = ft_strjoin("0", mod->buff);
	}
	if (j == 1)
		mod->buff[0] = '-';
}
