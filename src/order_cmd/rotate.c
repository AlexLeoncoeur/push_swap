/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:38:37 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/17 14:25:03 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_rotate(t_stack_list **lst)
{
	t_stack_list	*aux;

	if (!lst || ft_pushswap_lstsize(*lst) < 2)
		return ;
	aux = *lst;
	*lst = (*lst)->next;
	ft_pushswap_lstlast(*lst)->next = aux;
	aux->next = NULL;
	ft_check_stack(*lst);
}

void	ft_rotate_a(t_data_lst *data)
{
	ft_rotate(&data->a_stack);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_data_lst *data)
{
	ft_rotate(&data->b_stack);
	ft_printf("rb\n");
}

void	ft_rotate_both(t_data_lst *data)
{
	ft_rotate(&data->a_stack);
	ft_rotate(&data->b_stack);
	ft_printf("rr\n");
}
