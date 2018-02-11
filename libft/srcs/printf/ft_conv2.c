/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:34:13 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 16:41:10 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mod_long(va_list argptr, t_mod *mod)
{
	long int	arg;
	char		*temp;

	arg = (long int)va_arg(argptr, int);
	if (arg < 0)
	{
		arg = arg * -1;
		mod->buff = ft_itoa_base(arg, 10);
		temp = mod->buff;
		mod->buff = ft_strjoin("-", mod->buff);
		free(temp);
	}
	else
		mod->buff = ft_itoa_base(arg, 10);
}

void	ft_int(va_list argptr, t_mod *mod)
{
	int		arg;
	char	*temp;

	arg = va_arg(argptr, int);
	if (arg == -2147483648)
		mod->buff = ft_strdup("-2147483648");
	else if (arg < 0)
	{
		arg = arg * -1;
		mod->buff = ft_itoa_base(arg, 10);
		temp = mod->buff;
		mod->buff = ft_strjoin("-", mod->buff);
		free(temp);
	}
	else
		mod->buff = ft_itoa_base(arg, 10);
}

void	ft_int_h(va_list argptr, t_mod *mod)
{
	short int	arg;

	arg = (signed int)va_arg(argptr, int);
	if (arg < 0)
	{
		arg = arg * -1;
		mod->buff = ft_itoa_base(arg, 10);
		mod->buff = ft_strjoin("-", mod->buff);
	}
	else
		mod->buff = ft_itoa_base(arg, 10);
}

void	ft_int_hh(va_list argptr, t_mod *mod)
{
	signed char arg;
	char		*temp;

	arg = (signed char)va_arg(argptr, signed int);
	if (arg < 0)
	{
		arg = arg * -1;
		mod->buff = ft_itoa_base(arg, 10);
		temp = mod->buff;
		mod->buff = ft_strjoin("-", mod->buff);
		free(temp);
	}
	else
		mod->buff = ft_itoa_base(arg, 10);
}
