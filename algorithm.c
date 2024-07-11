/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:39:44 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/11 13:58:38 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_5(t_data_lst *data)
{
	t_stack_list	*best_move;
	int				i;

	i = 0;
	ft_push_b(data);
	ft_push_b(data);
	ft_order_3(data);
	while (i < 2)
	{
		ft_check_cost(data);
		best_move = ft_best_move(data);
		ft_execute_move(best_move, data);
		i++;
	}
	while (data->a_stack->index != 0)
	{
		if (data->a_stack->index > data->a_stack->next->index)
			ft_rotate_a(data);
		if (data->a_stack->index != 0)
			ft_reverse_rotate_a(data);
	}
	ft_check_stack(data->a_stack);
}

void	ft_order_3(t_data_lst *data)
{
	t_stack_list	*first;
	t_stack_list	*second;
	t_stack_list	*third;

	first = data->a_stack;
	second = first->next;
	third = second->next;
	if (first->index < second->index && second->index > third->index)
	{
		ft_reverse_rotate_a(data);
		ft_order_3(data);
	}
	else if (first->index > second->index && first->index > third->index)
	{
		ft_rotate_a(data);
		ft_order_3(data);
	}
	else if (first->index > second->index && second->index < third->index)
		ft_swap_a(data);
}

void	ft_algorithm(t_data_lst *data) //revisar esta costra infecta
{
	if (ft_pushswap_lstsize(data->a_stack) == 2)
	{
		if (ft_check_order(data->a_stack) == 1)
			ft_swap_a(data);
	}
	else if (ft_pushswap_lstsize(data->a_stack) == 3)
	{
		ft_order_3(data);
		ft_check_order(data->a_stack);
	}
	else if (ft_pushswap_lstsize(data->a_stack) == 5)
	{
		ft_order_5(data);
		ft_check_order(data->a_stack);
	}
/*	else if (ft_pushswap_lstsize(data->a_stack) == 6)
	{
		ft_order_6(data->a_stack);
		ft_check_order(data->a_stack);
	} */
}
