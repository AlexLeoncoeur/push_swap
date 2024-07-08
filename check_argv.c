/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:54:13 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/08 13:49:45 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*aux;
	unsigned char	*tmp;

	aux = (unsigned char *)s1;
	tmp = (unsigned char *)s2;
	i = 0;
	while ((aux[i] != '\0' && tmp[i] != '\0') && aux[i] == tmp[i])
		i++;
	return (aux[i] - tmp[i]);
}

int	ft_check_nb(char **numbers)
{
	int		i;
	int		j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_strcmp(numbers[i], numbers[j]) == 0)
				return (1);
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
	while (numbers[i])
	{
		j = 0;
		if (numbers[i][j] == '-')
			j++;
		while (numbers[i][j])
		{
			if ((numbers[i][j] < '0' || numbers[i][j] > '9'))
				return (1);
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
