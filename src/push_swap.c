/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:29 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/18 17:14:57 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static int	ft_empty_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < (argc))
	{
		if (!argv[i][0])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data_lst		*data_lst;
	char			**numbers;

	numbers = NULL;
	if (ft_empty_arg(argc, argv) == 1)
		ft_puterrorstr("Error: Empty argument\n");
	if (argc == 2 && ft_strlen(argv[1]) > 1)
		numbers = ft_split(argv[1], ' ');
	else if (argc > 2)
		numbers = &argv[1];
	else
		return (1);
	ft_check_nb(numbers);
	ft_check_char(numbers);
	data_lst = ft_define_data_lst(argc, argv, NULL);
	data_lst->a_stack = ft_prepare_stack_a(numbers);
	if (ft_check_order(data_lst->a_stack) == 0)
		return (ft_clean(numbers, argc, data_lst), 0);
	ft_prep_stack_data(data_lst->a_stack);
	ft_algorithm(data_lst);
	return (ft_clean(numbers, argc, data_lst), 0);
}

	/* t_stack_list *aux = data_lst->a_stack;
	for (int i = 0; i < ft_pushswap_lstsize(data_lst->a_stack); i++)
	{
		printf("%d ", aux->index);
		printf("%d ", aux->pos);
		printf("%d\n", aux->nb);
		aux = aux->next;
	} */