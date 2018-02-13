/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_special.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:01:14 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/13 16:27:04 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst	*ft_create_special(size_t data_size, void *data)
{
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst *));
	if (tmp)
	{
        tmp->data = malloc(data_size);
		tmp->data = ft_memcpy(tmp->data, data, data_size);
		tmp->next = NULL;
	}
	else
		return (NULL);
	return (tmp);
}
