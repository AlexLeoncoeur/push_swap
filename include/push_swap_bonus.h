/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:50 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/18 15:13:42 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
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

/*-------------------------------- Argv check --------------------------------*/

int				ft_min_max_checker(const char *str);
int				ft_check_order(t_stack_list *stack);
int				ft_check_char(char **numbers);
int				ft_check_nb(char **numbers);

/*-------------------------------- Stack Data --------------------------------*/

t_stack_list	*ft_prepare_stack_a(char **numbers);
void			ft_prep_stack_data(t_stack_list *stack);
void			ft_check_stack(t_stack_list *stack_lst);
void			ft_calculate_cost(t_data_lst *data);
void			ft_check_cost(t_data_lst *data);
void			ft_check_index(t_stack_list *stack);

/*------------------------------ List functions ------------------------------*/

int				ft_pushswap_lstsize(t_stack_list *lst);
void			ft_pushswap_lstadd_back(t_stack_list **lst, t_stack_list *new);
void			ft_pushswap_lstadd_front(t_stack_list **lst, t_stack_list *new);
t_stack_list	*ft_pushswap_lstlast(t_stack_list *lst);
t_stack_list	*ft_pushswap_lstnew(int nb);

/*----------------------------- Movement commands ----------------------------*/

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

/*----------------------------- Error management -----------------------------*/

void			ft_pushswap_lstclear(t_stack_list **lst);
void			ft_puterrorstr(char *str);
void			ft_free(char **str);

#endif