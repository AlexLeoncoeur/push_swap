/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:38:41 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/17 13:19:09 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

static void	ft_swap(t_stack_list **lst)
{
	t_stack_list	*aux;

	if (!lst || ft_pushswap_lstsize(*lst) < 2)
		return ;
	aux = (*lst)->next;
	(*lst)->next = aux->next;
	aux->next = (*lst);
	(*lst) = aux;
	aux = NULL;
	ft_check_stack(*lst);
}

void	ft_swap_a(t_data_lst *data)
{
	ft_swap(&data->a_stack);
	ft_printf("sa\n");
}

void	ft_swap_b(t_data_lst *data)
{
	ft_swap(&data->b_stack);
	ft_printf("sb\n");
}

void	ft_swap_both(t_data_lst *data)
{
	ft_swap(&data->a_stack);
	ft_swap(&data->b_stack);
	ft_printf("ss\n");
}
