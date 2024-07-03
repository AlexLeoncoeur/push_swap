/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:54:13 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/03 15:03:58 by aarenas-         ###   ########.fr       */
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
	while ((aux[i] != '\0' && tmp[i] != '\0')
		&& aux[i] == tmp[i])
		i++;
	return (aux[i] - tmp[i]);
}

int	ft_check_nb(int argc, char **argv)
{
	int		i;
	int		j;
	char	**numbers;

	i = 0;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_strcmp(numbers[i], numbers[j]) == 0)
				return (ft_puterrorstr("Error: Invalid argument\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_char(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i++])
			if ((argv[1][i] < '0' || argv[1][i] > '9') && (argv[1][i] != ' '))
				return (ft_puterrorstr("Error: Invalid argument\n"), 1);
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			j = -1;
			while (argv[i][j++])
			{
				if ((argv[i][j] < '0' || argv[i][j] > '9'))
					return (ft_puterrorstr("Error: Invalid argument\n"), 1);
			}
			i++;
		}
	}
	return (0);
}
