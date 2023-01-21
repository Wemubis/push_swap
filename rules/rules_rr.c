/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:13:49 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/21 18:16:22 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pile *a)
{
	a->first = a->first->prev;
	write(1, "rra\n", 3);
}

void	rrb(t_pile *b)
{
	b->first = b->first->prev;
	write(1, "rrb\n", 3);
}

void	rrr(t_pile *a, t_pile *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 3);
}