/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:41:57 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/14 03:55:45 by rloulizi         ###   ########.fr       */
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

int     is_valid_dir(char *path, char *name, int type)
{
    char *new_path;

    new_path = ft_new_path(path, name);
    if (ft_strcmp(path, ".") != 0 && ft_strncmp(path, "..", 2) != 0
            && type == 'd' && ft_is_dir(new_path))
        return (1);
    return (0);
}

int     ft_read_file(char *path, t_lst **lst, t_opt *opt)
{
    DIR             *dir;
    struct dirent   *d;
    t_file          *file;

    (void)lst;
    dir = NULL;
    d = NULL;
    if ((dir = opendir(path)) == NULL)
            return (0);
    while ((d = readdir(dir)) != NULL)
    {
        if (d->d_name[0] == '.' && opt->is_a == 0)
            continue;
        if (!(file = (t_file *)malloc(sizeof(t_file))))
            return (0);
        ft_get_stat(ft_new_path(path, d->d_name), file);
        file->name = d->d_name;
        file->path = ft_new_path(path, file->name);
        if (is_valid_dir(path, file->name, file->rights[0])
                   && opt->is_R)
               ft_read_file(ft_new_path(path, d->d_name), &file->sub_dir, opt);
        ft_list_push_back_special(lst, sizeof(t_file), file);
        free(file);
    }
    free(d);
    closedir(dir);
    return (0);
}

void    files(t_lst *lst)
{
    t_file *file;

    while (lst)
    {
        file = lst->data;
        ft_putendl(file->name);
        lst = lst->next;
    }
}

int     main(int argc, char *argv[])
{
    t_opt       opt;
    t_lst      *lst;
    
    lst = NULL;
    ft_opt(argv, &opt, argc - 1);
    ft_read_file(opt.path, &lst, &opt);
    files(lst);
}
