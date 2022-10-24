/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:02:54 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 19:44:20 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command	*ft_command_new(char *value)
{
	t_command	*comm;

	comm = (t_command *)malloc(sizeof(t_command));
	if (!comm)
		return (0);
	comm->val = value;
	comm->next = 0;
	return (comm);
}

void	first_command(t_stack *stack, char *command)
{
	t_command	*comm;

	comm = ft_command_new(command);
	stack->comm = comm;
	stack->comm_tail = comm;
}

void	command_insert(t_stack *stack, char *command)
{
	t_command	*new_command;

	if (!stack->comm)
		first_command(stack, command);
	else
	{
		new_command = ft_command_new(command);
		stack->comm_tail->next = new_command;
		stack->comm_tail = stack->comm_tail->next;
		stack->comm_tail->next = 0;
	}
}

void	clear_commands(t_stack *stack)
{
	t_command	*command;
	t_command	*temp;

	command = stack->comm;
	while (command)
	{
		temp = command->next;
		free(command);
		command = temp;
	}
}

void	print_command(t_stack *stack)
{
	t_command	*c;

	c = stack->comm;
	while (c)
	{
		if (c->next && \
		((!ft_strcmp(c->val, "rra\n") && !ft_strcmp(c->next->val, "rrb\n")) \
		|| (!ft_strcmp(c->val, "rrb\n") && !ft_strcmp(c->next->val, "rra\n"))))
		{
			write(1, "rrr\n", 4);
			c = c->next->next;
		}
		else if (c->next && \
		((!ft_strcmp(c->val, "ra\n") && !ft_strcmp(c->next->val, "rb\n")) \
		|| (!ft_strcmp(c->val, "rb\n") && !ft_strcmp(c->next->val, "ra\n"))))
		{
			write(1, "rr\n", 4);
			c = c->next->next;
		}
		else
		{
			write(1, c->val, ft_strlen(c->val));
			c = c->next;
		}
	}
}
