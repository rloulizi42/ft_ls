/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:16:57 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/26 19:34:08 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_mod
{
	char		*options;
	int			min_width;
	int			precision;
	char		*size;
	char		conv;
	char		*buff;
}				t_mod;

int				ft_printf(const char *format, ...);
int				ft_mod(const char *format, t_mod *mod);
void			ft_options(const char *format, t_mod *mod, size_t *i);
void			ft_min_width(const char *format, t_mod *mod, size_t *i);
void			ft_precision(const char *format, t_mod *mod, size_t *i);
void			ft_size(const char *format, t_mod *mod, size_t *i);
void			ft_conv(va_list argptr, t_mod *mod, int *ret);
void			ft_convert(const char *format, t_mod *mod, size_t *i);
void			ft_mod_int(va_list argptr, t_mod *mod, int *ret);
void			ft_mod_unsigned(va_list argptr, t_mod *mod);
void			ft_mod_wchar(va_list argptr, t_mod *mod);
void			ft_mod_swchar(va_list argptr, t_mod *mod);
void			ft_mod_str(va_list argptr, t_mod *mod);
void			ft_mod_pointer(va_list argptr, t_mod *mod);
void			ft_mod_long(va_list argptr, t_mod *mod);
void			ft_mod_buff(va_list argptr, t_mod *mod);
void			ft_mod_unsigned(va_list argptr, t_mod *mod);
void			ft_uox(va_list argptr, t_mod *mod);
void			ft_uox_h(va_list argptr, t_mod *mod);
void			ft_uox_hh(va_list argptr, t_mod *mod);
void			ft_uox_l(va_list argptr, t_mod *mod);
void			ft_uox_ll(va_list argptr, t_mod *mod);
void			ft_uox_j(va_list argptr, t_mod *mod);
void			ft_uox_z(va_list argptr, t_mod *mod);
void			ft_char(va_list argptr, t_mod *mod, int *ret);
void			ft_int_h(va_list argptr, t_mod *mod);
void			ft_int_l(va_list argptr, t_mod *mod);
void			ft_int_hh(va_list argptr, t_mod *mod);
void			ft_int_ll(va_list argptr, t_mod *mod);
void			ft_int_j(va_list argptr, t_mod *mod);
void			ft_int_z(va_list argptr, t_mod *mod);
char			*ft_upp(char *str);
void			ft_int(va_list argptr, t_mod *mod);
t_mod			*ft_mod_init(t_mod *mod);
void			ft_make(t_mod *mod);
void			ft_prec(t_mod *mod);
void			ft_prec2(t_mod *mod, int i);
void			ft_prec_s(t_mod *mod);
void			ft_min_wi(t_mod *mod);
void			ft_espace(t_mod *mod);
void			ft_more(t_mod *mod);
void			ft_static_more3(t_mod *mod);
void			ft_static2more(t_mod *mod);
void			ft_static2more3(t_mod *mod);
void			ft_static_more(t_mod *mod);
void			ft_static_esp(t_mod *mod);
void			ft_static_sharpp(t_mod *mod);
void			ft_static2esp(t_mod *mod);
void			ft_static_zero(t_mod *mod);
void			ft_static2zero(t_mod *mod, int j, size_t i);
void			ft_static_sharp(t_mod *mod);
void			ft_static_sharp2(t_mod *mod);
void			ft_more2(t_mod *mod);
void			ft_more3(t_mod *mod);
void			ft_sharp2(t_mod *mod);
void			ft_sharp(t_mod *mod);
void			ft_sharp3(t_mod *mod);
void			ft_minus2(t_mod *mod);
void			ft_zero2(t_mod *mod);
void			ft_zero3(t_mod *mod);
void			ft_minus(t_mod *mod);
void			ft_zero1(t_mod *mod);
void			ft_zero(t_mod *mod);
void			ft_print_wchar(va_list argptr, int *ret);
void			ft_print_swchar(va_list argptr, int *ret);
int				ft_atoi(const char *str);
int				ft_atoi2(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_base(size_t n, int base);
void			*ft_memalloc(size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar(char c);
void			ft_putendl(const char *str);
void			ft_putstr(const char *str);
void			ft_putnbr(int b);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strrev(char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strcpy(char *dst, char const *src);
char			*ft_strncpy(char *dst, char const *src, size_t n);
char			*ft_strcat(char *dst, char const *src);
char			*ft_strnew(size_t size);
char			*ft_strchr(const char *str, int c);
void			ft_strdel(char **as);

#endif
