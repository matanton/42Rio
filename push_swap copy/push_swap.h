/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:54:35 by matanton          #+#    #+#             */
/*   Updated: 2023/01/03 14:55:02 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

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
int			is_sorted(t_list list);
int			*ft_sort(int argc, char **data);
void		put_index(int *array, t_list **list, int size_array);
void		ft_swap(t_list **stack_one);
void		swap_a(t_list **stack_a);
void		swap_b(t_list **stack_b);
void		ft_rotate(t_list **stack_one);
void		ft_push(t_list **stack_one, t_list **stack_two);

#endif
