/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 15:25:04 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/16 15:59:34 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = *alst;
	while (ptr != NULL)
	{
		del(ptr->content, ptr->content_size);
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	ptr = NULL;
	*alst = ptr;
}
