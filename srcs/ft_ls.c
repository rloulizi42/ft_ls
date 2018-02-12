/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:41:57 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/12 18:35:48 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     ft_is_dir(char  *path)
{
    DIR     *dir;

    if ((dir = opendir(path)) != NULL)
    {
        closedir(dir);
        return (1);
    }
    return (0);
}

char    *ft_new_path(char *original, char *dir)
{
    char    *new_path;

    new_path = ft_strjoin(original, "/");
    new_path = ft_strjoin(new_path, dir);
    return (new_path);
}

int     ft_read_file(char *str, t_opt *opt)
{
    DIR             *dir;
    struct dirent   *d;
    t_file          file;

    if ((dir = opendir(str)) == NULL)
            return (0);
    while ((d = readdir(dir)) != NULL)
    {
        if (d->d_name[0] == '.' && opt->is_a == 0)
            continue;
        if (opt->is_l == 1)
            ft_get_stat(d->d_name, &file);
        ft_printf("%s\n", d->d_name);
    }
    closedir(dir);
    return (0);
}

int     main(int argc, char *argv[])
{
    t_opt       opt;
    
    ft_opt(argv, &opt, argc - 1);
    ft_read_file(opt.path, &opt);
}
