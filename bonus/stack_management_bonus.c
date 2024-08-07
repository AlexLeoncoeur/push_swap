/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:20:19 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/17 13:17:07 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_prep_stack_data(t_stack_list *stack)
{
	ft_check_stack(stack);
	ft_check_index(stack);
}

void	ft_check_cost(t_data_lst *data)
{
	ft_check_stack(data->a_stack);
	ft_check_stack(data->b_stack);
	ft_calculate_cost(data);
}

void	ft_check_index(t_stack_list *stack) //comprobar si esto funciona
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
}

t_stack_list	*ft_prepare_stack_a(char **numbers)
{
	int				i;
	t_stack_list	*aux;
	t_stack_list	*a_stack;

	i = 0;
	while (numbers[i + 1])
		i++;
	if (ft_min_max_checker(numbers[i]) == 1)
		ft_puterrorstr("Error: Argument is out of int limit\n");
	a_stack = ft_pushswap_lstnew(ft_atoi(numbers[i]));
	i--;
	a_stack->index = -2;
	a_stack->cost_a = '\0';
	while (i >= 0)
	{
		if (ft_min_max_checker(numbers[i]) == 1)
			ft_puterrorstr("Error: Argument is out of int limit\n");
		aux = ft_pushswap_lstnew(ft_atoi(numbers[i]));
		ft_pushswap_lstadd_back(&aux, a_stack);
		aux->index = -2;
		aux->cost_a = '\0';
		a_stack = aux;
		i--;
	}
	return (a_stack);
}

void	ft_check_stack(t_stack_list *stack_lst)
{
	int				i;
	t_stack_list	*aux;

	if (!stack_lst)
		return ;
	i = 0;
	aux = stack_lst;
	while (i < ft_pushswap_lstsize(stack_lst))
	{
		aux->pos = i;
		aux = aux->next;
		i++;
	}
}

/* 	t_stack_list *aux = data->a_stack;
	for (int i = 0; i < ft_pushswap_lstsize(data->a_stack); i++)
	{
		printf("%d ", aux->index);
		printf("%d ", aux->pos);
		printf("%d\n", aux->nb);
		aux = aux->next;
	}
	printf("\n");
	aux = data->b_stack;
	for (int i = 0; i < ft_pushswap_lstsize(data->b_stack); i++)
	{
		printf("%d ", aux->index);
		printf("%d ", aux->pos);
		printf("%d ", aux->cost_a);
		printf("%d ", aux->cost_b);
		printf("%d\n", aux->nb);
		aux = aux->next;
	}
	printf("\n"); */