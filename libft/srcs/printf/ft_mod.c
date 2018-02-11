/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 14:52:53 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/19 16:57:14 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_options(const char *format, t_mod *mod, size_t *i)
{
	size_t n;

	n = 0;
	while (format[*i] == '-' || format[*i] == '+' || format[*i] == '0' ||
			format[*i] == ' ' || format[*i] == '#')
	{
		n++;
		*i = *i + 1;
	}
	if (n > 0)
	{
		mod->options = ft_strnew(n);
		ft_strncpy(mod->options, format, n);
	}
}

void	ft_min_width(const char *format, t_mod *mod, size_t *i)
{
	while (format[*i] <= '9' || format[*i] >= '0')
	{
		mod->min_width = ft_atoi(format + *i);
		*i = *i + 1;
	}
}

void	ft_precision(const char *format, t_mod *mod, size_t *i)
{
	if (format[*i] == '.')
	{
		*i = *i + 1;
		mod->precision = ft_atoi(format + *i);
	}
	while (format[*i] >= '0' && format[*i] <= '9')
		*i = *i + 1;
}

void	ft_size(const char *format, t_mod *mod, size_t *i)
{
	size_t	n;

	n = 0;
	if (format[*i + n] == 'h' || format[*i + n] == 'l' || format[*i + n] == 'j'
			|| format[*i + n] == 'z')
	{
		n++;
		if (format[*i + n] == 'h' || format[*i + n] == 'l' ||
				format[*i + n] == 'j' || format[*i + n] == 'z')
		{
			n++;
			mod->size = ft_strnew(2);
			mod->size[0] = format[*i + 0];
			mod->size[1] = format[*i + 1];
		}
		else
		{
			mod->size = ft_strnew(1);
			mod->size[0] = format[*i + 0];
		}
		mod->size[n] = '\0';
	}
	*i = *i + n;
}

void	ft_convert(const char *format, t_mod *mod, size_t *i)
{
	if (format[*i] == 's' || format[*i] == 'S' || format[*i] == 'p' ||
			format[*i] == 'd' || format[*i] == 'D' || format[*i] == 'i' ||
			format[*i] == 'o' || format[*i] == 'O' || format[*i] == 'u' ||
			format[*i] == 'U' || format[*i] == 'x' || format[*i] == 'X' ||
			format[*i] == 'c' || format[*i] == 'C' || format[*i] == '%')
		mod->conv = format[*i];
}
