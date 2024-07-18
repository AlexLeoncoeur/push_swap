/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:12:44 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/18 17:33:45 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_clean(char **numbers, int argc, t_data_lst *data_lst)
{
	if (argc == 2)
		ft_free(numbers);
	if (data_lst->b_stack)
		ft_pushswap_lstclear(&data_lst->b_stack);
	ft_pushswap_lstclear(&data_lst->a_stack);
	free(data_lst);
}

void	ft_free(char **str)
{
	char	**ptr;

	if (!str)
		return ;
	ptr = str;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(str);
}

void	ft_pushswap_lstclear(t_stack_list **lst)
{
	t_stack_list	*aux;

	if (!lst)
		return ;
	while (*lst)
	{
		aux = *lst;
		*lst = (*lst)->next;
		free(aux);
	}
}
