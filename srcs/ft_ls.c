/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:41:57 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/14 19:09:12 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     ft_is_dir(char *path)
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

int     is_valid_dir(char *path, char *name, char type)
{
    char *new_path;

    new_path = ft_new_path(path, name);
    if (ft_strcmp(name, ".") != 0 && ft_strncmp(name, "..", 2) && (ft_is_dir(new_path)) && type == 'd')
        return (1);
    return (0);
}

int     ft_read_file(char *path, t_lst **lst, t_opt *opt)
{
    DIR             *dir;
    struct dirent   *d;
    t_file          *file;

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
        file->name = ft_strdup(d->d_name);
        file->path = ft_new_path(path, file->name);
        if (opt->is_R && is_valid_dir(path, file->name, file->rights[0]))
            ft_read_file(ft_new_path(path, d->d_name), &file->sub_dir, opt);
        ft_list_push_back_special(lst, sizeof(t_file), file);
    }
    closedir(dir);
    return (0);
}

void    bubble(t_lst *sec, t_lst *first)
{
    void *swap;

    swap = sec->data;
    sec->data = first->data;
    first->data = swap;
}

void    sort_ls(t_lst **lst)
{
    t_lst *sec;
    t_file *fsec;
    t_lst *first;
    t_file *ffirst;

    first = *lst;
    while (first)
    {
        sec = first->next;
        while (sec)
        {
            fsec = (t_file *)sec->data;
            ffirst = (t_file *)first->data;
            if (ft_strcmp(ffirst->name, fsec->name) > 0)
                bubble(first, sec);
            sec = sec->next;
        }
        first = first->next;
    }
}

int     main(int argc, char *argv[])
{
    t_opt       opt;
    t_lst      *lst;

    lst = NULL;
    ft_opt(argv, &opt, argc - 1);
    ft_read_file(opt.path, &lst, &opt);
    sort_ls(&lst);
    display_files(&lst, &opt);
}
