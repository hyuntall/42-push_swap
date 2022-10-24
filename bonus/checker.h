/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:39:10 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 17:01:37 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				n;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	int			as;
	t_node		*at;
	t_node		*ab;
	int			bs;
	t_node		*bt;
	t_node		*bb;
}		t_stack;

int		ft_atoll(t_stack *stack, char *str);
char	*join_argv(t_stack *stack, char **argv);
int		argv_to_stack(t_stack *stack, char **argv);

t_node	*ft_lstnew(int value);
int		is_unique_list(t_stack *stack, int target);
void	first_insert(t_stack *stack, int num);
void	node_insert(t_stack *stack, int num);
void	node_remove(t_node *node);

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_all(t_stack *stack);

void	push_b(t_stack *stack);
void	push_a(t_stack *stack);

void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_all(t_stack *stack);

void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_all(t_stack *stack);

int		stack_is_sort(t_stack *stack);

void	clear_stack(t_stack *stack);
void	print_error(t_stack	*stack);

char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		in_next_line(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif