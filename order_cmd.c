/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:24 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/08 13:57:27 by aarenas-         ###   ########.fr       */
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
	ft_prep_stack_data(*lst);
	ft_printf("p\n");
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
	aux = NULL;
	ft_prep_stack_data(*lst);
	ft_printf("s\n");
/* 	aux = *lst;
	for (int i = 0; i < ft_pushswap_lstsize(*lst); i++)
	{
		printf("%d ", aux->index);
		printf("%d ", aux->pos);
		printf("%d\n", aux->nb);
		aux = aux->next;
	} */
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
	ft_prep_stack_data(*lst);
	ft_printf("r\n");
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
	ft_prep_stack_data(*lst);
	ft_printf("rr\n");
}
