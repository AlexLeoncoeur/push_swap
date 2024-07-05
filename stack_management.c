/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:20:19 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/05 15:38:38 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_prep_stack_data(t_stack_list *stack)
{
	ft_check_stack(stack);
	ft_check_index(stack);
}

int	ft_check_index(t_stack_list *stack) //comprobar si esto funciona
{
	t_stack_list	*aux;
	t_stack_list	*tmp;
	t_stack_list	*min_node;
	int				min;
	int				i;

	i = 0;
	tmp = stack;
	while (i < ft_pushswap_lstsize(stack))
	{
		aux = tmp;
		min = MAX;
		while (aux)
		{
			if (aux->nb < min && aux->index < 0)
			{
				min = aux->nb;
				min_node = aux;
			}
			aux = aux->next;
		}
		min_node->index = i;
		i++;
	}
	return (0);
}

t_stack_list	*ft_prepare_stack_a(char **numbers)
{
	int				i;
	t_stack_list	*aux;
	t_stack_list	*a_stack;

	i = 0;
	while (numbers[i + 1])
		i++;
	//if (atoi_checker() == 1);
	a_stack = ft_pushswap_lstnew(ft_atoi(numbers[i]));
	while (--i >= 0)
	{
		aux = ft_pushswap_lstnew(ft_atoi(numbers[i]));
		ft_pushswap_lstadd_back(&aux, a_stack);
		a_stack = aux;
	}
	return (a_stack);
}

void	ft_check_stack(t_stack_list *stack_lst)
{
	int				i;
	int				j;
	t_stack_list	*aux;

	if (!stack_lst)
		return ;
	i = 0;
	aux = stack_lst;
	while (i < ft_pushswap_lstsize(stack_lst))
	{
		aux->pos = i;
		aux->cost_a = 0;
		aux->index = -2;
		j = ft_pushswap_lstsize(stack_lst);
		aux->cost_b = 1;
		while (j-- > aux->pos)
			aux->cost_b++;
		j = stack_lst->pos;
		while (j < aux->pos)
			j++;
		if (j > aux->cost_b)
			aux->cost_b = j + 1;
		aux = aux->next;
		i++;
	}
}
