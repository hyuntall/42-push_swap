/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:52:18 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/24 14:28:04 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	node = stack->at;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	node = stack->bt;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

void	print_error(t_stack	*stack)
{
	clear_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
