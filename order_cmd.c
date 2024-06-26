/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:24 by aarenas-          #+#    #+#             */
/*   Updated: 2024/06/26 15:20:01 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_stack_list *lst)
{
    t_stack_list    *swap;
    t_stack_list    *aux;

    if (!lst || !lst->next)
        return ;
    aux = lst;
    swap = aux;
    aux = aux->next;
    aux->next = swap;
    free(swap);
}

void    ft_push(t_stack_list *lst, t_stack_list *r_lst)
{
    t_stack_list    *new;
    t_stack_list    *aux;
    
    if (!lst)
        return ;
    if (!r_lst)
       r_lst = ft_pushswap_lstnew(NULL);
    new = ft_pushswap_lstnew(lst->nb); //quizás no funcione porque nb necesita ser un puntero(?)
    ft_lstadd_front(r_lst, new);
    aux = r_lst;
    while (aux->next != NULL)
    {
        aux = aux->next;
        aux->pos = aux->pos + 1;
    }
    aux = lst;
    lst = lst->next;
    free(aux);//free(aux) o aux = NULL(?)
}

void    ft_rotate(t_stack_list *lst) //hay que rotar las pos para que queden en su lugar correcto
{
    t_stack_list    *swap;
    t_stack_list    *aux;
	t_stack_list    *last;
    
    aux = lst;
    swap = lst;
    while (aux->next != NULL)
    {
    	aux->nb = aux->next->nb;
        aux = aux->next;
    }
	last = ft_pushswap_lstlast(lst);
	last = swap;
}

void    ft_reverse_rotate(t_stack_list *lst)
{
    t_stack_list    *swap;
    t_stack_list    *aux;
    
    aux = lst;
    swap->nb = lst->nb;
    while (aux->next != NULL)
    {
        aux->next->nb = aux->nb;
        aux = aux->next;
    }
    ft_pushswap_lstlast(lst)->nb = swap->nb;
}
