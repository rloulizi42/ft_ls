/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 13:10:35 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 13:36:50 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uox_z(va_list argptr, t_mod *mod)
{
	size_t arg;

	arg = va_arg(argptr, ssize_t);
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

void	ft_mod_pointer(va_list argptr, t_mod *mod)
{
	void	*ptr;
	char	*temp;

	ptr = va_arg(argptr, void*);
	mod->buff = ft_itoa_base((size_t)ptr, 16);
	temp = mod->buff;
	mod->buff = ft_strjoin("0x", mod->buff);
	free(temp);
}
