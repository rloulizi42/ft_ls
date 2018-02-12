/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:03:41 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/12 18:11:52 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_type(t_file *file)
{
  if ((file->s.st_mode & S_IFIFO) != 0)
      ft_putstr("p");
  else if ((file->s.st_mode & S_IFDIR) != 0)
      ft_putstr("d");
  else if ((file->s.st_mode & S_IFREG) != 0)
      ft_putstr("-");
  else if ((file->s.st_mode & S_IFBLK) != 0)
      ft_putstr("b");
  else if ((file->s.st_mode & S_IFLNK) != 0)
      ft_putstr("l");
  else if ((file->s.st_mode & S_IFCHR) != 0)
      ft_putstr("c");
  else
      ft_putstr("-");
}

void    ft_rights(t_file *file)
{
  ((file->s.st_mode & S_IRUSR) != 0) ? ft_putstr("r") : ft_putstr("-");
  ((file->s.st_mode & S_IWUSR) != 0) ? ft_putstr("w") : ft_putstr("-");
  ((file->s.st_mode & S_IXUSR) != 0) ? ft_putstr("x") : ft_putstr("-");
  ((file->s.st_mode & S_IRGRP) != 0) ? ft_putstr("r") : ft_putstr("-");
  ((file->s.st_mode & S_IWGRP) != 0) ? ft_putstr("w") : ft_putstr("-");
  ((file->s.st_mode & S_IXGRP) != 0) ? ft_putstr("x") : ft_putstr("-");
  ((file->s.st_mode & S_IROTH) != 0) ? ft_putstr("r") : ft_putstr("-");
  ((file->s.st_mode & S_IWOTH) != 0) ? ft_putstr("w") : ft_putstr("-");
  ((file->s.st_mode & S_IXOTH) != 0) ? ft_putstr("x") : ft_putstr("-");
  ft_putstr(" ");
}

void    ft_get_stat(char *path, t_file *file)
{
    if ((stat(path, &file->s) == -1))
        exit(EXIT_FAILURE);
    ft_type(file);
    ft_rights(file);
    ft_printf("%2d ", file->s.st_nlink);
    ft_printf("%s  ", getpwuid(file->s.st_uid)->pw_name);
    ft_printf("%s ", getgrgid(file->s.st_gid)->gr_name);
    ft_printf("%6d ", file->s.st_size);
    ft_printf("%s ", ft_strsub(ctime(&file->s.st_mtime), 4, 12));
}
