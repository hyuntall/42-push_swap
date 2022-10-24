/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:44:04 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 16:20:15 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_stack *stack)
{
	t_node	*node;

	if (!stack->as)
		return ;
	node = stack->at;
	stack->ab->next = node;
	stack->ab->next->prev = stack->ab;
	stack->ab = stack->ab->next;
	stack->at = stack->at->next;
	stack->ab->next = 0;
	stack->at->prev = 0;
}

void	rotate_b(t_stack *stack)
{
	t_node	*node;

	if (!stack->bs)
		return ;
	node = stack->bt;
	stack->bb->next = node;
	stack->bb->next->prev = stack->bb;
	stack->bb = stack->bb->next;
	stack->bt = stack->bt->next;
	stack->bb->next = 0;
	stack->bt->prev = 0;
}

void	rotate_all(t_stack *stack)
{
	t_node	*node;

	if (!stack->bs || !stack->as)
		return ;
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
}
