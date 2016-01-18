/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcour.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:10:07 by avella            #+#    #+#             */
/*   Updated: 2016/01/18 18:17:45 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try(char *piece, char *chaine, int chainei, int length)
{
	int		piecei;
	t_var	*v;

	v = (t_var *)malloc(sizeof(t_var) * 2);
	piecei = first_di(piece);
	v->length = length + 1;
	v->count = 0;
	v->chaine = chaine;
	v->piece = piece;
	if (v->piece[piecei] == '#' && v->chaine[chainei] == '.')
		v->count++;
	else
		return (0);
	p_c_change(v, chainei, piecei);
	if (v->piece[piecei + 1] == '#' && v->chaine[chainei + 1] == '.')
		v->count = go_right(chainei, piecei, v);
	if (v->piece[piecei + 5] == '#' && v->chaine[chainei + v->length] == '.')
		v->count = go_down(chainei, piecei, v);
	if (v->piece[piecei - 5] == '#' && v->chaine[chainei - v->length] == '.')
		v->count = go_up(chainei, piecei, v);
	if (v->piece[piecei - 1] == '#' && v->chaine[chainei - 1] == '.')
		v->count = go_left(chainei, piecei, v);
	if (v->count == 4)
		return (1);
	return (0);
}

int		go_right(int ci, int pi, t_var *var)
{
	if (var->count < 4)
	{
		pi = pi + 1;
		ci = ci + 1;
		var->count++;
		var->piece[pi] = 'x';
		var->chaine[ci] = 'x';
		if (var->piece[pi + 1] == '#' && var->chaine[ci + 1] == '.')
			var->count = go_right(ci, pi, var);
		if (var->piece[pi + 5] == '#' && var->chaine[ci + var->length] == '.')
			var->count = go_down(ci, pi, var);
		if (var->piece[pi - 5] == '#' && var->chaine[ci - var->length] == '.')
			var->count = go_up(ci, pi, var);
		if (var->piece[pi - 1] == '#' && var->chaine[ci - 1] == '.')
			var->count = go_left(ci, pi, var);
	}
	return (var->count);
}

int		go_down(int ci, int pi, t_var *var)
{
	if (var->count < 4)
	{
		var->count++;
		pi = pi + 5;
		ci = ci + var->length;
		var->piece[pi] = 'x';
		var->chaine[ci] = 'x';
		if (var->piece[pi + 1] == '#' && var->chaine[ci + 1] == '.')
			var->count = go_right(ci, pi, var);
		if (var->piece[pi + 5] == '#' && var->chaine[ci + var->length] == '.')
			var->count = go_down(ci, pi, var);
		if (var->piece[pi - 5] == '#' && var->chaine[ci - var->length] == '.')
			var->count = go_up(ci, pi, var);
		if (var->piece[pi - 1] == '#' && var->chaine[ci - 1] == '.')
			var->count = go_left(ci, pi, var);
	}
	return (var->count);
}

int		go_up(int ci, int pi, t_var *var)
{
	if (var->count < 4)
	{
		var->count++;
		pi = pi - 5;
		ci = ci - var->length;
		var->piece[pi] = 'x';
		var->chaine[ci] = 'x';
		if (var->piece[pi + 1] == '#' && var->chaine[ci + 1] == '.')
			var->count = go_right(ci, pi, var);
		if (var->piece[pi + 5] == '#' && var->chaine[ci + var->length] == '.')
			var->count = go_down(ci, pi, var);
		if (var->piece[pi - 5] == '#' && var->chaine[ci - var->length] == '.')
			var->count = go_up(ci, pi, var);
		if (var->piece[pi - 1] == '#' && var->chaine[ci - 1] == '.')
			var->count = go_left(ci, pi, var);
	}
	return (var->count);
}

int		go_left(int ci, int pi, t_var *var)
{
	if (var->count < 4)
	{
		var->count++;
		pi = pi - 1;
		ci = ci - 1;
		var->piece[pi] = 'x';
		var->chaine[ci] = 'x';
		if (var->piece[pi + 1] == '#' && var->chaine[ci + 1] == '.')
			var->count = go_right(ci, pi, var);
		if (var->piece[pi + 5] == '#' && var->chaine[ci + var->length] == '.')
			var->count = go_down(ci, pi, var);
		if (var->piece[pi - 5] == '#' && var->chaine[ci - var->length] == '.')
			var->count = go_up(ci, pi, var);
		if (var->piece[pi - 1] == '#' && var->chaine[ci - 1] == '.')
			var->count = go_left(ci, pi, var);
	}
	return (var->count);
}
