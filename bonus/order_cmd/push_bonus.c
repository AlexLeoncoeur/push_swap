/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:37:12 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/18 13:37:37 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

static void	ft_push(t_stack_list **lst, t_stack_list **r_lst)
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
	ft_check_stack(*lst);
}

void	ft_push_a(t_data_lst *data)
{
	ft_push(&data->b_stack, &data->a_stack);
}

void	ft_push_b(t_data_lst *data)
{
	ft_push(&data->a_stack, &data->b_stack);
}
