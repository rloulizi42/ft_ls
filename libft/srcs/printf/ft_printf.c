/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:08:44 by rloulizi          #+#    #+#             */
/*   Updated: 2018/01/26 18:45:06 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			ft_make(t_mod *mod)
{
	ft_prec(mod);
	ft_min_wi(mod);
	ft_espace(mod);
	ft_zero(mod);
	ft_sharp2(mod);
	ft_sharp(mod);
	ft_sharp3(mod);
	ft_more(mod);
	ft_minus(mod);
	ft_more2(mod);
	ft_more3(mod);
}

static void		ft_freestruc(t_mod *mod)
{
	if (mod->buff)
		free(mod->buff);
	if (mod->options)
		free(mod->options);
	if (mod->size)
		free(mod->size);
}

static int		ft_clone(const char *format, int ret, va_list argptr)
{
	size_t		i;
	t_mod		mod;

	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i = ft_mod(format, &mod);
			ft_conv(argptr, &mod, &ret);
			ft_make(&mod);
			format = format + i;
			write(1, mod.buff, ft_strlen(mod.buff));
			ret = ret + ft_strlen(mod.buff);
			ft_freestruc(&mod);
		}
		else
		{
			ft_putchar(*format);
			ret++;
		}
		format++;
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	int			ret;
	va_list		argptr;

	va_start(argptr, format);
	ret = 0;
	ret = ft_clone(format, ret, argptr);
	va_end(argptr);
	return (ret);
}
