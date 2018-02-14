/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:48:27 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/14 17:08:02 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    put_l(t_file *file)
{
    ft_printf("%s ", file->rights);
    ft_printf("%2d ", file->lnks);
    ft_printf("%s  ", file->user);
    ft_printf("%s ", file->grp);
    ft_printf("%6d ", file->byte_size);
    ft_printf("%s ", file->date);
    ft_printf("%s\n", file->name);
}

void    files(t_lst **lst, t_opt *opt)
{
    t_file *file;
    t_lst *files;

    files = *lst;
    while (files)
    {
        file = (t_file *)files->data;
        if (opt->is_l)
            put_l(file);
        else
            ft_putendl(file->name);
        files = files->next;
    }
}

void    dirs(t_lst **lst, t_opt *opt)
{
    t_lst   *files;
    t_file  *file;

    files = *lst;
    while (files && opt->is_R)
    {
        file = (t_file *)files->data;
        if (file->rights[0] == 'd' && file->sub_dir)
        {
            ft_printf("\n%s\n", file->path);
            display_files(&file->sub_dir, opt);
        }
        files = files->next;
    }
}

int    total_block(t_lst **lst)
{
    t_file *file;
    t_lst *files;
    int total;

    total = 0;
    files = *lst;
    while (files)
    {
        file = (t_file *)files->data;
        total += file->block_size;
        files = files->next;
    }
    return (total);
}

void    display_files(t_lst **lst, t_opt *opt)
{
    if (opt->is_l)
        ft_printf("total %d\n", total_block(lst));
    files(lst, opt);
    if (opt->is_R)
        dirs(lst, opt);
}
