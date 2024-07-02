/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:54:13 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/02 16:11:51 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_nb(int argc, char **argv)
{

}

int	ft_check_char(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i++])
			if ((argv[1][i] <= '0' || argv[1][i] >= '9') && (argv[1][i] != ' '))
				return (1);
	}
	else
	{
		while (argv[i + 1])
		{
			j = 0;
			while (argv[i][j++])
			{
				if ((argv[i][j] <= '0' || argv[i][j] >= '9')
					&& (argv[i][j] != ' '))
					return (1);
			}
			i++;
		}
	}
	return (0);
}
