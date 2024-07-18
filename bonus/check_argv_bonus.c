/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:54:13 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/18 17:25:24 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static int	ignorespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_min_max_checker(const char *str)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (ignorespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	result *= sign;
	if (result < MIN || result > MAX)
		return (1);
	return (0);
}

int	ft_check_nb(char **numbers)
{
	int		i;
	int		j;

	i = 0;
	if (!numbers)
		ft_puterrorstr("Error: Invalid argument\n");
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_strcmp(numbers[i], numbers[j]) == 0)
				ft_puterrorstr("Error: Argument is repetead\n");
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_char(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	if (!numbers)
		ft_puterrorstr("Error: Invalid argument\n");
	while (numbers[i])
	{
		j = 0;
		if (numbers[i][j] == '-')
			j++;
		while (numbers[i][j])
		{
			if ((numbers[i][j] < '0' || numbers[i][j] > '9'))
				ft_puterrorstr("Error: Argument is not a number\n");
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_order(t_stack_list *stack)
{
	t_stack_list	*aux;
	t_stack_list	*tmp;
	int				min;

	tmp = stack;
	while (tmp)
	{
		aux = tmp;
		min = aux->nb;
		while (aux && aux->next)
		{
			aux = aux->next;
			if (aux->nb < min)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
