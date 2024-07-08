/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:39:44 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/08 16:43:15 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_5(t_data_lst *data)
{
	ft_push(&data->a_stack, &data->b_stack);
	ft_push(&data->a_stack, &data->b_stack);
	ft_order_3(&data->a_stack);
	ft_check_cost(data);
}

void	ft_order_3(t_stack_list **stack)
{
	t_stack_list	*first;
	t_stack_list	*second;
	t_stack_list	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (first->index < second->index && second->index > third->index)
	{
		ft_reverse_rotate(stack);
		ft_order_3(stack);
	}
	else if (first->index > second->index && first->index > third->index)
	{
		ft_rotate(stack);
		ft_order_3(stack);
	}
	else if (first->index > second->index && second->index < third->index)
		ft_swap(stack);
}

void	ft_algorithm(t_data_lst *data) //revisar esta costra infecta
{
	if (ft_pushswap_lstsize(data->a_stack) == 2)
	{
		if (ft_check_order(data->a_stack) == 1)
			ft_swap(&data->a_stack);
	}
	else if (ft_pushswap_lstsize(data->a_stack) == 3)
	{
		ft_order_3(&data->a_stack);
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
