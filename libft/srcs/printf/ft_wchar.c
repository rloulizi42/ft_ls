/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:49:02 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 17:38:21 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "wchar.h"

char	*ft_fil(char *b, char *n)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (b[i] != '\0')
	{
		if (b[i] == 'x' && n[y])
		{
			b[i] = n[y];
			y++;
		}
		else if (b[i] == 'x')
			b[i] = '0';
		i++;
	}
	return (b);
}

void	ft_get_char(char *b, char *n, int l, int *ret)
{
	char	*s;
	int		i;
	char	t[4];

	t[0] = 0;
	t[1] = 9;
	t[2] = 18;
	t[3] = 27;
	i = 0;
	while (i < l)
	{
		b = ft_fil(ft_strrev(b), ft_strrev(n));
		b = ft_strrev(b);
		s = ft_strsub(b, t[i], 8);
		ft_putchar(ft_atoi2(ft_strrev(s)));
		*ret = *ret + 1;
		free(s);
		i++;
	}
	free(b);
}

void	ft_putwchar(wchar_t w, int *ret, char *n, char *b)
{
	n = ft_itoa_base((long int)w, 2);
	if (w < 128)
	{
		write(1, &w, 1);
		*ret = *ret + 1;
	}
	else if (w < 2048)
	{
		b = (char*)malloc(17);
		ft_strncpy(b, "110xxxxx 10xxxxxx", 17);
		ft_get_char(b, n, 2, ret);
	}
	else if (w < 65536)
	{
		b = (char*)malloc(27);
		ft_strncpy(b, "1110xxxx 10xxxxxx 10xxxxxx", 26);
		ft_get_char(b, n, 3, ret);
	}
	else if (w < 2097152)
	{
		b = (char*)malloc(27);
		ft_strncpy(b, "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx", 36);
		ft_get_char(b, n, 4, ret);
	}
	free(n);
}

void	ft_print_wchar(va_list argptr, int *ret)
{
	wchar_t	arg;
	char	*n;
	char	*b;

	n = NULL;
	b = NULL;
	arg = va_arg(argptr, wchar_t);
	ft_putwchar(arg, ret, n, b);
}

void	ft_print_swchar(va_list argptr, int *ret)
{
	wchar_t	*arg;
	char	*n;
	char	*b;

	n = NULL;
	b = NULL;
	arg = va_arg(argptr, wchar_t*);
	if (arg == 0)
		return ;
	while (*arg)
	{
		ft_putwchar(*arg, ret, n, b);
		arg++;
	}
}
