/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:23:07 by hyunkkim          #+#    #+#             */
/*   Updated: 2021/12/18 20:15:46 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_element;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		next_element = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = next_element;
	}
}
