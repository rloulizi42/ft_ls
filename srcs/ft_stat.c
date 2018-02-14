/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:03:41 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/14 03:44:48 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_type(struct stat *s, t_file *file)
{
    if ((s->st_mode & S_IFIFO) != 0)
        file->rights[0] = 'p';
    else if ((s->st_mode & S_IFDIR) != 0)
        file->rights[0] = 'd';
    else if ((s->st_mode & S_IFREG) != 0)
        file->rights[0] = '-';
    else if ((s->st_mode & S_IFBLK) != 0)
        file->rights[0] = 'b';
    else if ((s->st_mode & S_IFLNK) != 0)
        file->rights[0] = 'l';
    else if ((s->st_mode & S_IFCHR) != 0)
        file->rights[0] = 'c';
    else
        file->rights[0] = '-';
}

void    ft_rights(struct stat *s, t_file *file)
{
    file->rights[1] = (s->st_mode & S_IRUSR) ? 'r' : '-';
    file->rights[2] = (s->st_mode & S_IWUSR) ? 'w' : '-';
    file->rights[3] = (s->st_mode & S_IXUSR) ? 'x' : '-';
    file->rights[4] = (s->st_mode & S_IRGRP) ? 'r' : '-';
    file->rights[5] = (s->st_mode & S_IWGRP) ? 'w' : '-';
    file->rights[6] = (s->st_mode & S_IXGRP) ? 'x' : '-';
    file->rights[7] = (s->st_mode & S_IROTH) ? 'r' : '-';
    file->rights[8] = (s->st_mode & S_IWOTH) ? 'w' : '-';
    file->rights[9] = (s->st_mode & S_IXOTH) ? 'x' : '-';
    file->rights[10] = '\0';
}

void    ft_init_stat(t_file *file)
{
    file->path = NULL;
    ft_memset(file->rights, 0, 11);
    file->lnks = 0;
    file->user = NULL;
    file->grp = NULL;
    file->byte_size = 0;
    file->block_size = 0;
    file->date = NULL;
    file->sub_dir = NULL;
    file->name = NULL;
}

void    ft_get_stat(char *path, t_file *file)
{
    struct stat s;

    if ((stat(path, &s) == -1))
        exit(EXIT_FAILURE);
    ft_init_stat(file);
    ft_type(&s, file);
    ft_rights(&s, file);
    file->lnks =  (int)s.st_nlink;
    file->user = ft_strdup(getpwuid(s.st_uid)->pw_name);
    file->grp = ft_strdup(getgrgid(s.st_gid)->gr_name);
    file->byte_size = (int)s.st_size;
    file->block_size = (int)s.st_blocks;
    file->date = ft_strsub(ctime(&s.st_mtime), 4, 12);
}
