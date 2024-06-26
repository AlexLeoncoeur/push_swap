/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:58:55 by aarenas-          #+#    #+#             */
/*   Updated: 2024/06/26 15:14:43 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_list	*ft_pushswap_lstlast(t_stack_list *lst)
{
	t_stack_list	*aux;

	if (lst == NULL)
		return (NULL);
	aux = lst;
	while (aux->next != NULL)
		aux = aux->next;
	return (aux);
}

t_stack_list	*ft_pushswap_lstnew(void *nb)
{
	t_stack_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	newlist->nb = nb;
    newlist->pos = 1;
    newlist->next_pos = NULL;
	newlist->next = NULL;
	return (newlist);
}