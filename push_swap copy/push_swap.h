/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:54:35 by matanton          #+#    #+#             */
/*   Updated: 2023/01/06 15:36:24 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_list{
	int				elem;
	int				index;
	struct s_list	*next;
}t_list;

int			is_repeated(int argc, char **data);
int			is_number(int argc, char **data);
t_list		*ft_lstnew(int elem);
t_list		*ft_lstlast(t_list *list);
void		ft_lstadd_back(t_list **list, t_list *new);
t_list		*argto_stack(int argc, char **data);
void		print_list(t_list **list);
long int	ft_psatoi(char *str);
int			is_long(int argc, char **data);
int			is_sorted(t_list *list);
int			*ft_sort(int argc, char **data);
void		put_index(int *array, t_list **list, int size_array);
void		swap_a(t_list **stack_a);
void		swap_b(t_list **stack_b);
void		rotate_a(t_list **stack_a);
void		rotate_b(t_list **stack_b);
void		ft_push(t_list **stack_one, t_list **stack_two);
void		push_ab(t_list **stack_a, t_list **stack_b);
void		push_ba(t_list **stack_b, t_list **stack_a);
int			ft_lastbit(t_list **stack);
void		push_swap(t_list **stack_a, t_list **stack_b);
int			ft_lstsize(t_list *head);
int			pb(t_list **stack_a, t_list **stack_b);
int			pa(t_list **stack_a, t_list **stack_b);
int			push(t_list **stack_to, t_list **stack_from);
int			ft_rotate(t_list **stack_one);
int			ft_swap(t_list **stack_one);
int			ft_error(void);
void		ft_sortbig(t_list **stack_a, t_list **stack_b, \
			int max_bits, int size);
int			ft_reverserotate(t_list **stack_a);
int			rra(t_list **stack_a);
int			rrb(t_list **stack_b);
int			rrr(t_list **stack_a, t_list **stack_b);
void		ft_sortthree(t_list **stack_a);
void		ft_sortfive(t_list **stack_a, t_list **stack_b);
void		ft_sortfour(t_list **stack_a, t_list **stack_b);

#endif
