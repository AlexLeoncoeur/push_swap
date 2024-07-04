/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:31:50 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/04 18:08:37 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

# ifndef MAX
#  define MAX 2147483647
# endif

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
int				ft_check_char(int argc, char **argv);
int				ft_check_order(t_stack_list *stack);
int				ft_check_nb(int argc, char **argv);

/*------------------------------ List functions ------------------------------*/

int				ft_pushswap_lstsize(t_stack_list *lst);
void			ft_pushswap_lstadd_back(t_stack_list **lst, t_stack_list *new);
void			ft_pushswap_lstadd_front(t_stack_list **lst, t_stack_list *new);
void			ft_check_stack_a(t_data_lst *data_lst);
t_stack_list	*ft_prepare_stack_a_beta(int argc, char **argv);
t_stack_list	*ft_pushswap_lstlast(t_stack_list *lst);
t_stack_list	*ft_prepare_stack_a_alpha(char **argv);
t_stack_list	*ft_pushswap_lstnew(int nb);

/*----------------------------- Movement commands ----------------------------*/

void			ft_push(t_stack_list **lst, t_stack_list **r_lst);
void			ft_reverse_rotate(t_stack_list **lst);
void			ft_rotate(t_stack_list **lst);
void			ft_swap(t_stack_list **lst);

/*----------------------------- Error management -----------------------------*/

void			ft_puterrorstr(char *str);
void			ft_free(char **str);

#endif