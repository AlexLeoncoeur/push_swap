/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:20:19 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/02 15:01:36 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_list	*ft_prepare_stack_a_alpha(char **argv)
{
	int				i;
	char			**numbers;
	t_stack_list	*aux;
	t_stack_list	*a_stack;

	i = 0;
	numbers = ft_split(argv[1], ' ');
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

t_stack_list	*ft_prepare_stack_a_beta(int argc, char **argv)
{
	int				i;
	t_stack_list	*aux;
	t_stack_list	*a_stack;

	i = 0;
	a_stack = ft_pushswap_lstnew(argv[argc - 1][0] - '0');
	while (++i < argc -1)
	{
		aux = ft_pushswap_lstnew(argv[argc - 1 - i][0] - '0');
		ft_pushswap_lstadd_back(&aux, a_stack);
		a_stack = aux;
	}
	return (a_stack);
}

void	ft_check_stack_a(t_data_lst *data_lst)
{
	int				i;
	int				j;
	t_stack_list	*aux;

	if (!data_lst->a_stack)
		return ;
	i = 0;
	aux = data_lst->a_stack;
	while (i < ft_pushswap_lstsize(data_lst->a_stack))
	{
		aux->pos = i;
		aux->cost_a = 0;
		j = ft_pushswap_lstsize(data_lst->a_stack);
		aux->cost_b = 1;
		while (j-- > aux->pos)
			aux->cost_b++;
		j = data_lst->a_stack->pos;
		while (j < aux->pos)
			j++;
		if (j > aux->cost_b)
			aux->cost_b = j + 1;
		aux = aux->next;
	}
}
