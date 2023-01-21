/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:14:06 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/21 20:13:29 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pile *a, t_pile *b)
{
	if (b->first == NULL)
		return ;
	push_before(a->first, pop(b));
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_pile *a, t_pile *b)
{
	if (a->first == NULL)
		return ;
	push_before(b->first, pop(a));
	b->size++;
	write(1, "pb\n", 3);
}
