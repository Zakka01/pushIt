/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:01:09 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/14 19:14:59 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


typedef struct s_list
{
    int             data;
    int             index;
    struct s_list   *next;
}                   n_list;


n_list  *add_new_node(int content);
void    add_to_back(n_list **list, n_list *node);
void    add_to_front(n_list **list, n_list *node);
int     list_size(n_list *list);
char    **ft_split(char *str);
int     ft_atoi(char *str, int *error);
void	free_all_space(char **arr);
int     parse_create_list(char *arg, n_list **a_head);
int     check_dup(n_list *a_head);
void    swap(n_list **h_stack, char w_stack);
void    swap_both(n_list **a_stack, n_list **b_stack);
void    push(n_list **src_stack, n_list **dst_stack, char w_stack);
void    rotate(n_list **h_stack, char w_stack);
void    rotate_both(n_list **a_stack, n_list **b_stack);
void    rev_rotate(n_list **h_stack, char w_stack);
void    rev_rotate_both(n_list  **a_stack, n_list   **b_stack);
void    handle_list_size(n_list **a_stack, n_list **b_stack);
int     is_sorted(n_list    **a_stack);
void    index_nodes(n_list **a_stack, int size);
void    chunks_sort(n_list **a_stack, n_list **b_stack, int size);



#endif