/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:50 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/10 17:16:26 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

# define MAX 2147483647
# define MIN -2147483648

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

/*----------------------------- Common functions -----------------------------*/

int				ft_strcmp(const char *s1, const char *s2);
int				ft_check_order(t_stack_list *stack);
int				ft_check_char(char **numbers);
int				ft_check_nb(char **numbers);

/*-------------------------------- Stack Data --------------------------------*/

t_stack_list	*ft_prepare_stack_a(char **numbers);
void			ft_prep_stack_data(t_stack_list *stack);
void			ft_check_stack(t_stack_list *stack_lst);
void			ft_calculate_cost(t_data_lst *data);
void			ft_check_cost(t_data_lst *data);
int				ft_check_index(t_stack_list *stack);

/*------------------------------ List functions ------------------------------*/

int				ft_pushswap_lstsize(t_stack_list *lst);
void			ft_pushswap_lstadd_back(t_stack_list **lst, t_stack_list *new);
void			ft_pushswap_lstadd_front(t_stack_list **lst, t_stack_list *new);
t_stack_list	*ft_pushswap_lstlast(t_stack_list *lst);
t_stack_list	*ft_pushswap_lstnew(int nb);

/*----------------------------- Movement commands ----------------------------*/

t_stack_list	*ft_best_move(t_data_lst *data);
void			ft_execute_move(t_stack_list *node, t_data_lst *data);

void			ft_push_a(t_data_lst *data);
void			ft_push_b(t_data_lst *data);

void			ft_reverse_rotate_a(t_data_lst *data);
void			ft_reverse_rotate_b(t_data_lst *data);
void			ft_reverse_rotate_both(t_data_lst *data);

void			ft_rotate_a(t_data_lst *data);
void			ft_rotate_b(t_data_lst *data);
void			ft_rotate_both(t_data_lst *data);

void			ft_swap_a(t_data_lst *data);
void			ft_swap_b(t_data_lst *data);
void			ft_swap_both(t_data_lst *data);

/*--------------------------------- Algorithm --------------------------------*/

void			ft_order_3(t_data_lst *data);
void			ft_order_5(t_data_lst *data);
void			ft_algorithm(t_data_lst *data);

/*----------------------------- Error management -----------------------------*/

void			ft_puterrorstr(char *str);
void			ft_free(char **str);

#endif