/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:21:43 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/08 16:43:39 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_a_cost(t_data_lst *data, t_stack_list *tmp)
{
	return ((ft_pushswap_lstsize(data->a_stack) + 1) - tmp->pos);
}

void	ft_calculate_cost(t_data_lst *data)
{
	int				i;
	t_stack_list	*aux;
	t_stack_list	*tmp;

	aux = data->b_stack;
	tmp = data->a_stack;
	i = -1;
	while (++i < ft_pushswap_lstsize(data->b_stack))
	{
		if (aux->pos < ft_pushswap_lstsize(data->b_stack) / 2)
			aux->cost_b = i;
		else
			aux->cost_b = i - aux->pos;
		while (tmp->next)
		{
			if (tmp->index == aux->index + 1)
			{
				if (tmp->pos < ft_pushswap_lstsize(data->b_stack) / 2)
					aux->cost_a = tmp->pos - 1;
				else
					aux->cost_a = ft_get_a_cost(data, tmp);
			}
		}
		aux = aux->next;
	}
}
