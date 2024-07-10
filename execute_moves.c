/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:15:00 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/10 17:55:40 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_recalculate_cost(t_stack_list *node)
{
	if (node->cost_a > 0)
		node->cost_a--;
	if (node->cost_a < 0)
		node->cost_a++;
	if (node->cost_b > 0)
		node->cost_b--;
	if (node->cost_b > 0)
		node->cost_b++;
}

void	ft_execute_move(t_stack_list *node, t_data_lst *data)
{
	while (1)
	{
		if (node->cost_a == 0 && node->cost_b == 0)
		{
			ft_push_a(data);
			break ;
		}
		else if (node->cost_a < 0 && node->cost_b < 0)
			ft_reverse_rotate_both(data);
		else if (node->cost_a > 0 && node->cost_b > 0)
			ft_rotate_both(data);
		else if (node->cost_a < 0)
			ft_reverse_rotate_a(data);
		else if (node->cost_a > 0)
			ft_rotate_a(data);
		if (node->cost_b < 0)
			ft_reverse_rotate_b(data);
		else if (node->cost_b > 0)
			ft_rotate_b(data);
		ft_recalculate_cost(node);
	}
}

static int	ft_absolute_cost(t_stack_list *node)
{
	int	a;
	int	b;

	a = node->cost_a;
	b = node->cost_b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}

t_stack_list	*ft_best_move(t_data_lst *data)
{
	t_stack_list	*aux;
	t_stack_list	*min_node;

	aux = data->b_stack;
	min_node = data->b_stack;
	while (aux)
	{
		if (ft_absolute_cost(aux) < ft_absolute_cost(min_node))
			min_node = aux;
		aux = aux->next;
	}
	return (min_node);
}
