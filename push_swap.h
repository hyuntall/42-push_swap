/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:43:59 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 19:45:11 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				n;
	struct s_node	*next;
}		t_node;

typedef struct s_command
{
	struct s_command	*next;
	char				*val;
}		t_command;

typedef struct s_stack
{
	int			as;
	t_node		*at;
	t_node		*ab;
	int			bs;
	t_node		*bt;
	t_node		*bb;
	t_command	*comm;
	t_command	*comm_tail;
}		t_stack;

int			ft_atoll(t_stack *stack, char *str);
char		*join_argv(t_stack *stack, char **argv);
int			argv_to_stack(t_stack *stack, char **argv);

t_node		*ft_lstnew(int value);
int			is_unique_list(t_stack *stack, int target);
void		first_insert(t_stack *stack, int num);
void		node_insert(t_stack *stack, int num);
void		node_remove(t_node *node);

t_command	*ft_command_new(char *value);
void		first_command(t_stack *stack, char *command);
void		command_insert(t_stack *stack, char *command);
void		clear_commands(t_stack *stack);
void		print_command(t_stack *stack);

void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		swap_all(t_stack *stack);

void		push_b(t_stack *stack);
void		push_a(t_stack *stack);

void		rotate_a(t_stack *stack);
void		rotate_b(t_stack *stack);
void		rotate_all(t_stack *stack);

void		reverse_rotate_a(t_stack *stack);
void		reverse_rotate_b(t_stack *stack);
void		reverse_rotate_all(t_stack *stack);

void		stack_sort(t_stack *stack);

void		merge(t_stack *stack, int *shape, int gap, int lr);

int			*make_new_shape(int	*arr, int gap);
int			*tri_shape(int size);
void		make_direct(int n, int *arr, int direct, int index);

void		clear_stack(t_stack *stack);
void		print_error(t_stack	*stack);

void		make_triangle(t_stack *stack, int *shape, int direct, int size);

int			stack_is_sort(t_stack *stack);

char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_strcmp(char *s1, char *s2);
#endif