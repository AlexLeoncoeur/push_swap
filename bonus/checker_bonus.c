/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:29 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/18 15:40:56 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

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

static void	ft_check_cmd(char *order, t_data_lst *data)
{
	if (ft_strncmp(order, "ss\n", 2) == 0)
		ft_swap_both(data);
	else if (ft_strncmp(order, "sa\n", 3) == 0)
		ft_swap_a(data);
	else if (ft_strncmp(order, "sb\n", 3) == 0)
		ft_swap_b(data);
	else if (ft_strncmp(order, "pa\n", 3) == 0)
		ft_push_a(data);
	else if (ft_strncmp(order, "pb\n", 3) == 0)
		ft_push_b(data);
	else if (ft_strncmp(order, "rr\n", 3) == 0)
		ft_rotate_both(data);
	else if (ft_strncmp(order, "ra\n", 3) == 0)
		ft_rotate_a(data);
	else if (ft_strncmp(order, "rb\n", 3) == 0)
		ft_rotate_b(data);
	else if (ft_strncmp(order, "rrr\n", 4) == 0)
		ft_reverse_rotate_both(data);
	else if (ft_strncmp(order, "rra\n", 4) == 0)
		ft_reverse_rotate_a(data);
	else if (ft_strncmp(order, "rrb\n", 4) == 0)
		ft_reverse_rotate_b(data);
	else
		ft_puterrorstr("Error: invalid command\n");
}

static void	ft_read_orders(t_data_lst *data)
{
	char	*order;

	while (1)
	{
		order = get_next_line(0);
		if (!order)
			break ;
		ft_check_cmd(order, data);
		free(order);
		order = NULL;
	}
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
	if (argc <= 1 || ft_empty_arg(argc, argv) == 1)
		ft_puterrorstr("Error: Invalid argument\n");
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
	ft_read_orders(data_lst);
	if (ft_check_order(data_lst->a_stack) == 0 && !data_lst->b_stack)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (argc == 2)
		ft_free(numbers);
	ft_pushswap_lstclear(&data_lst->a_stack);
	return (free(data_lst), 0);
}
