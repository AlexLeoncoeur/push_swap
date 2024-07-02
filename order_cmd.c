/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:24 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/02 11:15:29 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack_list **lst, t_stack_list **r_lst)
{
	t_stack_list	*aux;

	if (!lst)
		return ;
	aux = *lst;
	*lst = (*lst)->next;
	if (!r_lst)
	{
		*r_lst = aux;
		(*r_lst)->next = NULL;
	}
	else
	{
		aux->next = *r_lst;
		*r_lst = aux;
	}
}

void	ft_swap(t_stack_list **lst)
{
	t_stack_list	*aux;

	if (!lst || ft_pushswap_lstsize(*lst) < 2)
		return ;
	aux = (*lst)->next;
	(*lst)->next = aux->next;
	aux->next = (*lst);
	(*lst) = aux;
}

void	ft_rotate(t_stack_list **lst)
{
	t_stack_list	*aux;

	if (!lst || ft_pushswap_lstsize(*lst) < 2)
		return ;
	aux = *lst;
	*lst = (*lst)->next;
	ft_pushswap_lstlast(*lst)->next = aux;
	aux->next = NULL;
}

void	ft_reverse_rotate(t_stack_list **lst)
{
	t_stack_list	*aux;
	t_stack_list	*last;

	if (!lst || ft_pushswap_lstsize(*lst) < 2)
		return ;
	aux = *lst;
	last = ft_pushswap_lstlast(*lst);
	while (aux->next != last)
		aux = aux->next;
	aux->next = NULL;
	last->next = *lst;
	*lst = last;
}
