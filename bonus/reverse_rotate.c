/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:34:50 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 15:49:15 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_a(t_stack *stack)
{
	t_node	*node;

	if (!stack->as)
		return ;
	node = stack->ab;
	stack->at->prev = node;
	stack->at->prev->next = stack->at;
	stack->at = stack->at->prev;
	stack->ab = stack->ab->prev;
	stack->at->prev = 0;
	stack->ab->next = 0;
}

void	reverse_rotate_b(t_stack *stack)
{
	t_node	*node;

	if (!stack->bs)
		return ;
	node = stack->bb;
	stack->bt->prev = node;
	stack->bt->prev->next = stack->bt;
	stack->bt = stack->bt->prev;
	stack->bb = stack->bb->prev;
	stack->bt->prev = 0;
	stack->bb->next = 0;
}

void	reverse_rotate_all(t_stack *stack)
{
	t_node	*node;

	if (!stack->as || !stack->bs)
		return ;
	node = stack->ab;
	stack->at->prev = node;
	stack->at->prev->next = stack->at;
	stack->at = stack->at->prev;
	stack->ab = stack->ab->prev;
	stack->at->prev = 0;
	stack->ab->next = 0;
	node = stack->bb;
	stack->bt->prev = node;
	stack->bt->prev->next = stack->bt;
	stack->bt = stack->bt->prev;
	stack->bb = stack->bb->prev;
	stack->bt->prev = 0;
	stack->bb->next = 0;
}
