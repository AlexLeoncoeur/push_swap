/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:50 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/02 11:16:57 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef struct s_stack_list
{
	int					nb;
	int					pos;
	int					index;
	int					cost_a;
	int					cost_b;
	int					target_pos;
	struct s_stack_list	*next;

}	t_stack_list;

typedef struct s_data_lst
{
	int				argc;
	char			**argv;
	t_stack_list	*a_stack;
	t_stack_list	*b_stack;
}	t_data_lst;

/********************************List functions********************************/

int				ft_pushswap_lstsize(t_stack_list *lst);
void			ft_pushswap_lstadd_back(t_stack_list **lst, t_stack_list *new);
void			ft_pushswap_lstadd_front(t_stack_list **lst, t_stack_list *new);
t_stack_list	*ft_pushswap_lstlast(t_stack_list *lst);
t_stack_list	*ft_pushswap_lstnew(int nb);

/********************************Movement commands****************************/

void			ft_push(t_stack_list **lst, t_stack_list **r_lst);
void			ft_reverse_rotate(t_stack_list **lst);
void			ft_rotate(t_stack_list **lst);
void			ft_swap(t_stack_list **lst);

#endif