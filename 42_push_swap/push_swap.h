/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:01:09 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/24 17:31:52 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

t_list				*add_new_node(int content);
void				add_to_back(t_list **list, t_list *node);
void				add_to_front(t_list **list, t_list *node);
int					list_size(t_list *list);
char				**ft_split(char *str);
int					ft_atoi(char *str, int *error);
void				free_all_space(char **arr);
int					parse_create_list(char *arg, t_list **a_head);
int					check_dup(t_list *a_head);
void				swap(t_list **h_stack, char w_stack);
void				swap_both(t_list **a_stack, t_list **b_stack);
void				push(t_list **src_stack, t_list **dst_stack, char w_stack);
void				rotate(t_list **h_stack, char w_stack);
void				rotate_both(t_list **a_stack, t_list **b_stack);
void				rev_rotate(t_list **h_stack, char w_stack);
void				rev_rotate_both(t_list **a_stack, t_list **b_stack);
void				handle_list_size(t_list **a_stack, t_list **b_stack);
void				handle_list_size(t_list **a_stack, t_list **b_stack);
int					is_sorted(t_list **a_stack);
void				index_nodes(t_list **a_stack, int size);
void				chunks_sort(t_list **a_stack, t_list **b_stack, int size);
void				size_of_two(t_list **a_stack);
void				size_of_three(t_list **a_stack);
void				size_of_f(t_list **a_stack, t_list **b_stack, int size);

#endif