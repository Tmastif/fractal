/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:26:58 by ilazar            #+#    #+#             */
/*   Updated: 2024/05/06 20:57:51 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		current = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = current;
	}
	*lst = NULL;
}
