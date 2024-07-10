/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:21:43 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/10 12:36:14 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_min_index(t_stack_list *stack, int index)
{
	int				min_index;
	t_stack_list	*aux;

	aux = stack;
	while (aux && !min_index)
	{
		if (aux->index > index)
			min_index = aux->index;
		aux = aux->next;
	}
	while (aux)
	{
		if (aux->index < min_index && aux->index > index)
			min_index = aux->index;
		aux = aux->next;
	}
	return (min_index);
}

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
	i = 0;
	while (++i <= ft_pushswap_lstsize(data->b_stack))
	{
		if ((aux->pos) <= ((ft_pushswap_lstsize(data->b_stack) / 2)))
			aux->cost_b = aux->pos;
		else
			aux->cost_b = (i - aux->pos) * -1;
		tmp = data->a_stack;
		while (tmp)
		{
			if (tmp->index == ft_min_index(data->a_stack, aux->index))
			{
				if ((tmp->pos) <= (ft_pushswap_lstsize(data->b_stack) / 2))
					aux->cost_a = tmp->pos;
				else
					aux->cost_a = ft_get_a_cost(data, tmp) * -1;
			}
			tmp = tmp->next;
		}
		aux = aux->next;
	}
}
