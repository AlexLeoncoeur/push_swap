/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:38:32 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/17 13:19:03 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

static void	ft_reverse_rotate(t_stack_list **lst)
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
	ft_check_stack(*lst);
}

void	ft_reverse_rotate_a(t_data_lst *data)
{
	ft_reverse_rotate(&data->a_stack);
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_data_lst *data)
{
	ft_reverse_rotate(&data->b_stack);
	ft_printf("rrb\n");
}

void	ft_reverse_rotate_both(t_data_lst *data)
{
	ft_reverse_rotate(&data->a_stack);
	ft_reverse_rotate(&data->b_stack);
	ft_printf("rrr\n");
}
