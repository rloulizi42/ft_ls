/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:39:53 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/12 17:37:30 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>

typedef struct  s_opt
{
    int         is_l;
    int         is_R;
    int         is_a;
    int         is_r;
    int         is_t;
    char        *path;
}               t_opt;

typedef struct  s_file
{
    char            *name;
    char            *path;
    struct stat     s;
    struct s_file   *next;
}               t_file;

int     ft_read_file(char *str, t_opt *opt);
void    ft_opt(char *argv[], t_opt *opt, int nb_arg);
void    ft_get_stat(char *path, t_file *file);

#endif
