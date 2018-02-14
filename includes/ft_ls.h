/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:39:53 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/14 19:40:44 by rloulizi         ###   ########.fr       */
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

typedef struct      s_lst
{
    void            *data;
    struct s_lst   *next;
}                   t_lst;

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
    char        *path;
    char        rights[11];
    int         lnks;
    char        *user;
    char        *grp;
    int         byte_size;
    int         block_size;
    char        *date;
    t_lst      *sub_dir;
    char        *name;
}               t_file;

int     ft_read_file(char *str, t_lst **lst, t_opt *opt);
void    ft_opt(char *argv[], t_opt *opt, int nb_arg);
void    ft_get_stat(char *path, t_file *file);
void    ft_list_push_back_special(t_lst **lst, size_t data_size, void *data);
t_lst   *ft_create_special(size_t data_size, void *data);
void    display_files(t_lst **lst, t_opt *opt);
void    sort(t_lst **lst);

#endif
