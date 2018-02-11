/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:39:53 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/11 16:54:13 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <dirent.h>

typedef struct  s_opt
{
    int         is_l;
    int         is_R;
    int         is_a;
    int         is_r;
    int         is_t;
    char        *path;
}               t_opt;

int     ft_ls(char *str, t_opt *opt);
void    ft_opt(char *argv[], t_opt *opt, int nb_arg);

#endif
