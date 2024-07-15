/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:29 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/15 11:45:28 by aarenas-         ###   ########.fr       */
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
	t_data_lst		*data_lst;
	char			**numbers;

	numbers = NULL;
	if (argc <= 1)
		ft_puterrorstr("Error: Too few arguments\n");
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else if (argc > 2)
		numbers = &argv[1];
	ft_check_nb(numbers);
	ft_check_char(numbers);
	data_lst = ft_define_data_lst(argc, argv, NULL);
	data_lst->a_stack = ft_prepare_stack_a(numbers);
	if (ft_check_order(data_lst->a_stack) == 0)
		return (0);
	ft_prep_stack_data(data_lst->a_stack);
	ft_algorithm(data_lst);
	free(data_lst->a_stack);
	return (free(data_lst), 0);
}
/* 
1: Revisar el comportamiento de ft_check_stack con cost_a y cost_b
2: 
	t_stack_list	*b_stack = NULL;
	printf("%d %d %d %d\n", a_stack->nb, a_stack->next->nb, a_stack->next->next->nb, a_stack->next->next->next->nb);
	ft_push(&a_stack, &b_stack);
	printf("%d %d %d |a\n", a_stack->nb, a_stack->next->nb, a_stack->next->next->nb);
	printf("%d |b\n", b_stack->nb);
*/

/* 	t_stack_list *aux = data_lst->a_stack;
	for (int i = 0; i < ft_pushswap_lstsize(data_lst->a_stack); i++)
	{
		printf("%d ", aux->index);
		printf("%d ", aux->pos);
		printf("%d\n", aux->nb);
		aux = aux->next;
	} */