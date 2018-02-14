/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:27:50 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/14 19:29:15 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
