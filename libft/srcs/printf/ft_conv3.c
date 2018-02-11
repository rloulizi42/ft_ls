/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:28:19 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 13:35:26 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_l(va_list argptr, t_mod *mod)
{
	long int	arg;
	char		*temp;

	arg = va_arg(argptr, long int);
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

void	ft_int_ll(va_list argptr, t_mod *mod)
{
	long long int	arg;
	char			*temp;

	arg = va_arg(argptr, long long int);
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

void	ft_uox(va_list argptr, t_mod *mod)
{
	unsigned int arg;

	arg = va_arg(argptr, unsigned int);
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

void	ft_uox_hh(va_list argptr, t_mod *mod)
{
	unsigned char arg;

	arg = (unsigned char)va_arg(argptr, unsigned int);
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

void	ft_uox_h(va_list argptr, t_mod *mod)
{
	unsigned short int arg;

	arg = (unsigned short int)va_arg(argptr, int);
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
