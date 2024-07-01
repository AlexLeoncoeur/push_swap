/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:29 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/01 17:55:02 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data_lst	*ft_define_data_lst(int argc, char **argv, t_stack_list *a_stack)
{
	t_data_lst	*aux;

	aux = malloc(sizeof(t_data_lst));
	if (aux == NULL)
		return (NULL);
	aux->argc = argc;
	aux->argv = argv;
	aux->a_stack = a_stack;
	aux->b_stack = NULL;
	return (aux);
}

t_stack_list	*ft_prepare_stack_a_alpha(char **argv)
{
	int				i;
	t_stack_list	*aux;
	t_stack_list	*a_stack;

	i = ft_strlen(argv[1]) - 1;
	a_stack = ft_pushswap_lstnew(argv[1][i] - '0');
	while (--i >= 0)
	{
		aux = ft_pushswap_lstnew(argv[1][i] - '0');
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

int	main(int argc, char **argv)
{
	t_stack_list	*a_stack;
	t_data_lst		*data_lst;

	if (argc <= 1)
		return (1);
	if (argc == 2)
		a_stack = ft_prepare_stack_a_alpha(argv);
	else
		a_stack = ft_prepare_stack_a_beta(argc, argv);
	data_lst = ft_define_data_lst(argc, argv, a_stack);
	printf("%d %d %d %d\n", a_stack->nb, a_stack->next->nb, a_stack->next->next->nb, a_stack->next->next->next->nb);
	ft_rotate(&a_stack);
	printf("%d %d %d %d\n", a_stack->nb, a_stack->next->nb, a_stack->next->next->nb, a_stack->next->next->next->nb);
	return (0);
}
/*
1: Solo un argumento con todos los numeros
2: Cada argumento es un numero
*/