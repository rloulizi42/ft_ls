/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 13:55:43 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/21 16:14:53 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_mod	*ft_init(t_mod *mod)
{
	mod->options = NULL;
	mod->min_width = 0;
	mod->precision = -1;
	mod->size = NULL;
	mod->conv = 0;
	mod->buff = NULL;
	return (mod);
}

int		ft_mod(const char *format, t_mod *mod)
{
	size_t		nb;

	nb = 0;
	ft_init(mod);
	ft_options(format, mod, &nb);
	mod->min_width = ft_atoi(format + nb);
	while (format[nb] >= '0' && format[nb] <= '9')
		nb++;
	ft_precision(format, mod, &nb);
	ft_size(format, mod, &nb);
	ft_convert(format, mod, &nb);
	return (nb);
}
