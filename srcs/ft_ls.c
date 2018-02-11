/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:41:57 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/11 17:50:52 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_ls(char *str, t_opt *opt)
{
    DIR             *dir;
    struct dirent   *d;

    if ((dir = opendir(str)) == NULL)
            return (0);
    while ((d = readdir(dir)) != NULL)
    {
        if (d->d_name[0] == '.' && opt->is_a == 0)
            continue;
        else
            ft_printf("%s\n", d->d_name);
    }
    closedir(dir);
    return (0);
}
void    ft_putopt(t_opt *opt)
{
    ft_printf("%d\n", opt->is_l);
    ft_printf("%d\n", opt->is_R);
    ft_printf("%d\n", opt->is_a);
    ft_printf("%d\n", opt->is_r);
    ft_printf("%d\n", opt->is_t);
}

int main(int argc, char *argv[])
{
    t_opt       opt;
    
    ft_opt(argv, &opt, argc - 1);
    //ft_putopt(&opt);
    if ((argc - 1) == 0)
        ft_ls(argv[1], &opt);
    if ((argc - 1) == 1)
        ft_ls(argv[1], &opt);
    if ((argc - 1) == 2)
        ft_ls(argv[2], &opt);
}
