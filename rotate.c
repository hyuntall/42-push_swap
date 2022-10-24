/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:44:04 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 20:15:21 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	t_node	*node;

	node = stack->at;
	stack->ab->next = node;
	stack->ab->next->prev = stack->ab;
	stack->ab = stack->ab->next;
	stack->at = stack->at->next;
	stack->ab->next = 0;
	stack->at->prev = 0;
	command_insert(stack, "ra\n");
}

void	rotate_b(t_stack *stack)
{
	t_node	*node;

	node = stack->bt;
	stack->bb->next = node;
	stack->bb->next->prev = stack->bb;
	stack->bb = stack->bb->next;
	stack->bt = stack->bt->next;
	stack->bb->next = 0;
	stack->bt->prev = 0;
	command_insert(stack, "rb\n");
}

void	rotate_all(t_stack *stack)
{
	t_node	*node;

	node = stack->at;
	stack->ab->next = node;
	stack->ab->next->prev = stack->ab;
	stack->ab = stack->ab->next;
	stack->at = stack->at->next;
	stack->ab->next = 0;
	stack->at->prev = 0;
	node = stack->bt;
	stack->bb->next = node;
	stack->bb->next->prev = stack->bb;
	stack->bb = stack->bb->next;
	stack->bt = stack->bt->next;
	stack->bb->next = 0;
	stack->bt->prev = 0;
	command_insert(stack, "rr\n");
}
