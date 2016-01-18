/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefullfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:18:08 by avella            #+#    #+#             */
/*   Updated: 2016/01/18 18:18:38 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*iactuel_reset(int *iactuel, int nbt)
{
	int i;

	i = 0;
	while (i < nbt)
	{
		iactuel[i] = 0;
		i++;
	}
	return (iactuel);
}

void	p_c_change(t_var *var, int chainei, int piecei)
{
	var->piece[piecei] = 'x';
	var->chaine[chainei] = 'x';
}

int		first_di(char *piece)
{
	int i;

	i = 0;
	while (piece[i] != '\0' && piece[i] != '#')
		i++;
	return (i);
}

void	v_0(t_var2 *var2, int *iactuel)
{
	int i;

	i = 0;
	var2->carac--;
	var2->tetri--;
	iactuel[var2->tetri]++;
	i = 0;
	while (var2->chaine[i] != '\0')
	{
		if (var2->chaine[i] == var2->carac)
			var2->chaine[i] = '.';
		i++;
	}
}

void	v_2(t_var2 *var2, int *iactuel)
{
	var2->length++;
	var2->chaine = malloc_chaine(var2->chaine, var2->length);
	iactuel = iactuel_reset(iactuel, var2->nbt);
	var2->tetri = 0;
	var2->carac = 'A';
}
