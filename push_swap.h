/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:50 by aarenas-          #+#    #+#             */
/*   Updated: 2024/06/26 14:46:06 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef struct s_stack_list
{
    int nb;
    int pos;
    int next_pos;
    struct s_stack_list *next;

}   t_stack_list;

t_stack_list	*ft_pushswap_lstlast(t_stack_list *lst);
t_stack_list	*ft_lstnew(int *nb);

#endif