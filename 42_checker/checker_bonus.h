/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:12:19 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/27 21:35:46 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

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
// moves
void				swap(t_list **h_stack);
void				swap_both(t_list **a_stack, t_list **b_stack);
void				push(t_list **src_stack, t_list **dst_stack);
void				rotate(t_list **h_stack);
void				rotate_both(t_list **a_stack, t_list **b_stack);
void				rev_rotate(t_list **h_stack);
void				rev_rotate_both(t_list **a_stack, t_list **b_stack);

int					is_sorted(t_list **a_stack);

// get line
char				*get_line(int fd);
// get line helpers
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
int					ft_strlen(const char *s);
char				*flush_leftover(char **saved_buf);
int					nl_found(char *buffer);

int					validate_line(char *line);
int					is_move(char *str1, char *str2);

#endif