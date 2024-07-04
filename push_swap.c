/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:29 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/04 17:40:32 by aarenas-         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack_list	*a_stack;
	t_data_lst		*data_lst;

	if (argc <= 1 || ft_check_nb(argc, argv) == 1
		|| ft_check_char(argc, argv) == 1)
		return (ft_puterrorstr("Error: Invalid argument\n"), 1);
	if (argc == 2)
		a_stack = ft_prepare_stack_a_alpha(argv);
	else
		a_stack = ft_prepare_stack_a_beta(argc, argv);
	if (ft_check_order(a_stack) == 0)
		return (0);
	data_lst = ft_define_data_lst(argc, argv, a_stack);
	return (0);
}
/*
1: Solo un argumento con todos los numeros
2: Cada argumento es un numero
	t_stack_list	*b_stack = NULL;
	printf("%d %d %d %d\n", a_stack->nb, a_stack->next->nb, a_stack->next->next->nb, a_stack->next->next->next->nb);
	ft_push(&a_stack, &b_stack);
	printf("%d %d %d |a\n", a_stack->nb, a_stack->next->nb, a_stack->next->next->nb);
	printf("%d |b\n", b_stack->nb);
*/
//ft_print_stack(a_stack), 