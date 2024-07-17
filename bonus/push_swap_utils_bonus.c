/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:58:55 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/17 13:17:57 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ft_pushswap_lstsize(t_stack_list *lst)
{
	t_stack_list	*aux;
	int				i;

	aux = lst;
	i = 0;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

void	ft_pushswap_lstadd_back(t_stack_list **lst, t_stack_list *new)
{
	t_stack_list	*aux;

	if (*lst == NULL)
		*lst = new;
	else
	{
		aux = ft_pushswap_lstlast(*lst);
		aux->next = new;
	}
}

void	ft_pushswap_lstadd_front(t_stack_list **lst, t_stack_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

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

t_stack_list	*ft_pushswap_lstnew(int nb)
{
	t_stack_list	*newlist;

	newlist = malloc(sizeof(t_stack_list));
	if (newlist == NULL)
		return (NULL);
	newlist->nb = nb;
	newlist->pos = -1;
	newlist->target_pos = -1;
	newlist->index = -1;
	newlist->cost_a = -1;
	newlist->cost_b = -1;
	newlist->next = NULL;
	return (newlist);
}
