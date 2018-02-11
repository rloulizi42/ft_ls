/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:32:06 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 13:36:18 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uox_l(va_list argptr, t_mod *mod)
{
	unsigned long int arg;

	arg = va_arg(argptr, unsigned long int);
	if (mod->conv == 'u')
		mod->buff = ft_itoa_base(arg, 10);
	else if (mod->conv == 'o')
		mod->buff = ft_itoa_base(arg, 8);
	else if (mod->conv == 'x')
		mod->buff = ft_itoa_base(arg, 16);
	else if (mod->conv == 'U')
		mod->buff = ft_itoa_base(arg, 10);
	else if (mod->conv == 'O')
		mod->buff = ft_itoa_base(arg, 8);
	else if (mod->conv == 'X')
	{
		mod->buff = ft_itoa_base(arg, 16);
		mod->buff = ft_upp(mod->buff);
	}
}

void	ft_uox_ll(va_list argptr, t_mod *mod)
{
	unsigned long long int arg;

	arg = va_arg(argptr, unsigned long long int);
	if (mod->conv == 'u')
		mod->buff = ft_itoa_base(arg, 10);
	else if (mod->conv == 'o')
		mod->buff = ft_itoa_base(arg, 8);
	else if (mod->conv == 'x')
		mod->buff = ft_itoa_base(arg, 16);
	else if (mod->conv == 'U')
		mod->buff = ft_itoa_base(arg, 10);
	else if (mod->conv == 'O')
		mod->buff = ft_itoa_base(arg, 8);
	else if (mod->conv == 'X')
	{
		mod->buff = ft_itoa_base(arg, 16);
		mod->buff = ft_upp(mod->buff);
	}
}

void	ft_int_j(va_list argptr, t_mod *mod)
{
	intmax_t	arg;
	char		*temp;

	arg = va_arg(argptr, intmax_t);
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

void	ft_int_z(va_list argptr, t_mod *mod)
{
	size_t arg;

	arg = va_arg(argptr, size_t);
	mod->buff = ft_itoa_base(arg, 10);
}

void	ft_uox_j(va_list argptr, t_mod *mod)
{
	uintmax_t arg;

	arg = va_arg(argptr, uintmax_t);
	if (mod->conv == 'u')
		mod->buff = ft_itoa_base(arg, 10);
	else if (mod->conv == 'o')
		mod->buff = ft_itoa_base(arg, 8);
	else if (mod->conv == 'x')
		mod->buff = ft_itoa_base(arg, 16);
	else if (mod->conv == 'U')
		mod->buff = ft_itoa_base(arg, 10);
	else if (mod->conv == 'O')
		mod->buff = ft_itoa_base(arg, 8);
	else if (mod->conv == 'X')
	{
		mod->buff = ft_itoa_base(arg, 16);
		mod->buff = ft_upp(mod->size);
	}
}
