/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:00:49 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 15:14:37 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv(va_list argptr, t_mod *mod, int *ret)
{
	if (mod->conv == 'd' || mod->conv == 'i' || mod->conv == 'c')
		ft_mod_int(argptr, mod, ret);
	else if (mod->conv == 'u' || mod->conv == 'o' || mod->conv == 'x' ||
			mod->conv == 'X' || mod->conv == 'U' || mod->conv == 'O')
		ft_mod_unsigned(argptr, mod);
	else if (mod->conv == 'C')
		ft_print_wchar(argptr, ret);
	else if (mod->conv == 's' && mod->size == NULL)
		ft_mod_str(argptr, mod);
	else if (mod->conv == 'S' || (mod->conv == 's' &&
				ft_strcmp(mod->size, "l") == 0))
		ft_print_swchar(argptr, ret);
	else if (mod->conv == 'p')
		ft_mod_pointer(argptr, mod);
	else if (mod->conv == 'D')
		ft_mod_long(argptr, mod);
	else if (mod->conv == '%')
		mod->buff = ft_strdup("%");
}

void	ft_mod_int(va_list argptr, t_mod *mod, int *ret)
{
	if ((mod->conv == 'd' || mod->conv == 'i') && mod->size == NULL)
		ft_int(argptr, mod);
	else if (mod->conv == 'c' && mod->size == NULL)
		ft_char(argptr, mod, ret);
	else if (ft_strcmp(mod->size, "h") == 0)
		ft_int_h(argptr, mod);
	else if (ft_strcmp(mod->size, "hh") == 0)
		ft_int_hh(argptr, mod);
	else if ((!strcmp(mod->size, "l")) && mod->conv == 'c')
		ft_print_wchar(argptr, ret);
	else if (ft_strcmp(mod->size, "l") == 0)
		ft_int_l(argptr, mod);
	else if (ft_strcmp(mod->size, "ll") == 0)
		ft_int_ll(argptr, mod);
	else if (ft_strcmp(mod->size, "j") == 0)
		ft_int_j(argptr, mod);
	else if (ft_strcmp(mod->size, "z") == 0)
		ft_int_z(argptr, mod);
}

void	ft_mod_unsigned(va_list argptr, t_mod *mod)
{
	if (mod->size == NULL)
		ft_uox(argptr, mod);
	else if (ft_strcmp(mod->size, "hh") == 0)
		ft_uox_hh(argptr, mod);
	else if (ft_strcmp(mod->size, "h") == 0)
		ft_uox_h(argptr, mod);
	else if (ft_strcmp(mod->size, "l") == 0)
		ft_uox_l(argptr, mod);
	else if (ft_strcmp(mod->size, "ll") == 0)
		ft_uox_ll(argptr, mod);
	else if (ft_strcmp(mod->size, "j") == 0)
		ft_uox_j(argptr, mod);
	else if (ft_strcmp(mod->size, "z") == 0)
		ft_uox_z(argptr, mod);
}

void	ft_mod_str(va_list argptr, t_mod *mod)
{
	char *arg;
	char *temp;

	temp = mod->buff;
	arg = va_arg(argptr, char*);
	if (arg == 0)
		mod->buff = ft_strdup("(null)");
	else
		mod->buff = ft_strdup(arg);
	free(temp);
}

void	ft_char(va_list argptr, t_mod *mod, int *ret)
{
	int arg;

	arg = va_arg(argptr, int);
	mod->buff = ft_strnew(1);
	if (arg == 0)
	{
		*ret = *ret + 1;
		ft_putchar('\0');
		mod->min_width--;
	}
	else
		mod->buff[0] = arg;
}
