/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:09:52 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 19:36:28 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_freepre(t_mod *mod)
{
	char		*s;

	s = ft_memalloc(ft_strlen(mod->buff) + mod->precision);
	s = ft_memset(s, '0', mod->precision - ft_strlen(mod->buff));
	mod->buff = ft_strjoin(s, mod->buff);
	free(s);
}

void			ft_prec(t_mod *mod)
{
	int			i;

	i = 0;
	if (mod->buff == NULL)
		return ;
	if (mod->buff[0] == '-')
	{
		i++;
		mod->buff++;
	}
	if (mod->precision == 0 && mod->buff[0] == '0')
	{
		mod->buff[0] = '\0';
		return ;
	}
	ft_prec_s(mod);
	ft_prec2(mod, i);
}

void			ft_prec_s(t_mod *mod)
{
	char		*s;

	if (mod->conv == 's')
	{
		if (mod->precision != -1 && (mod->precision <
					(int)ft_strlen(mod->buff)))
		{
			s = ft_memalloc(mod->precision);
			s = ft_strncpy(s, mod->buff, mod->precision);
			mod->buff = ft_strcpy(mod->buff, s);
			free(s);
		}
	}
}

void			ft_prec2(t_mod *mod, int i)
{
	char		*temp;

	if (mod->precision > (int)ft_strlen(mod->buff) && mod->conv != 's')
	{
		if (i == 0)
		{
			temp = mod->buff;
			ft_freepre(mod);
			free(temp);
		}
		else
			ft_freepre(mod);
	}
	if (i == 1)
		mod->buff = ft_strjoin("-", mod->buff);
}
