/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:31:29 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/11 16:37:27 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void    ft_init_opt(t_opt *opt)
{
    opt->is_l = 0;
    opt->is_R = 0;
    opt->is_a = 0;
    opt->is_r = 0;
    opt->is_t = 0;
}

static int    ft_is_opt(char *str)
{
    while (*str)
    {
        if (ft_strchr("lRart", *str) != NULL)
            return (1);
        str++;
    }
    return (0);
}

static void    ft_fill_opt(char *str, t_opt *opt)
{
    if (*str == '-')
        str++;
    ft_init_opt(opt);
    while (*str)
    {
        if (!(ft_is_opt(str)))
            exit(EXIT_FAILURE);
        else if (*str == 'l')
            opt->is_l = 1;
        else if (*str == 'R')
            opt->is_R = 1;
        else if (*str == 'a')
            opt->is_a = 1;
        else if (*str == 'r')
            opt->is_r = 1;
        else if (*str == 't')
            opt->is_t = 1;
        str++;
    }
}

void    ft_opt(char *argv[], t_opt *opt, int nb_arg)
{
    opt->path = ".";
    if (nb_arg == 1 && argv[1][0] == '-')
        ft_fill_opt(argv[1], opt);
    if (nb_arg == 1 && argv[1][0] != '-')
        opt->path = argv[1];
    if (nb_arg == 2 && argv[1][0] == '-' && argv[2][0])
    {
        ft_fill_opt(argv[1], opt);
        opt->path = argv[2];
    }
}
