/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:21:43 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/11 18:23:23 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_a_cost(t_data_lst *data, t_stack_list *tmp)
{
	return ((ft_pushswap_lstsize(data->a_stack) + 1) - (tmp->pos + 1));
}

static void	ft_final_cost(t_data_lst *data, t_stack_list *b, t_stack_list *a)
{
	if ((a->pos) <= (ft_pushswap_lstsize(data->a_stack) / 2))
		b->cost_a = a->pos;
	else
		b->cost_a = ft_get_a_cost(data, a) * -1;
}

static int	ft_min_index(t_stack_list *stack, int index)
{
	int				min_index;
	t_stack_list	*aux;

	aux = stack;
	min_index = '\0';
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
				ft_final_cost(data, aux, tmp);
			}
			tmp = tmp->next;
		}
		/* ft_printf("index: %d\n", aux->index);
		ft_printf("min_index: %d\n", ft_min_index(data->a_stack, aux->index));
		ft_printf("cost: %d\n", aux->cost_a); */
		if (!aux->cost_a)
			aux->cost_a = 0;
		aux = aux->next;
	}
}
