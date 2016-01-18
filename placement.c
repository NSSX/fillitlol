/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:12:06 by avella            #+#    #+#             */
/*   Updated: 2016/01/18 17:09:33 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nb_tetri(char *chaine)
{
	int count;
	int time;
	int i;

	i = 0;
	time = 0;
	count = 0;
	while (chaine[i] != '\0')
	{
		while (time < 4)
		{
			while (chaine[i] != '\n')
			{
				i++;
			}
			i++;
			time++;
		}
		count++;
		time = 0;
		if (chaine[i] == '\0')
			return (count);
		i++;
	}
	return (count);
}

char	*mychar(int *iactuel, int chainei, char **tab, t_var2 *var2)
{
	int i;
	int v;

	v = 0;
	i = 0;
	while (var2->tetri < var2->nbt)
	{
		v = backtrack(iactuel, tab, var2);
		if (v == 1)
		{
			var2->tetri++;
			if (var2->tetri < var2->nbt)
			{
				var2->carac++;
				iactuel[var2->tetri] = 0;
				chainei = 0;
			}
		}
		else if (v == 0)
			v_0(var2, iactuel);
		else if (v == 2)
			v_2(var2, iactuel);
	}
	return (var2->chaine);
}

int		backtrack(int *iactuel, char **tab, t_var2 *var2)
{
	int		i;
	int		ret;
	char	*chaine;
	char	carac;
	int		tetri;

	chaine = var2->chaine;
	carac = var2->carac;
	tetri = var2->tetri;
	ret = 3;
	i = 0;
	while (!try(dp(tab[tetri]), dp(chaine), iactuel[tetri], var2->length)
			&& chaine[iactuel[tetri]] != '\0')
		iactuel[tetri]++;
	if (try(dp(tab[tetri]), dp(chaine), iactuel[tetri], var2->length))
	{
		try(dp(tab[tetri]), chaine, iactuel[tetri], var2->length);
		ret = 1;
		chaine = trans_di(chaine, carac);
	}
	else if (carac == 'A')
		ret = 2;
	else
		ret = 0;
	return (ret);
}

void	ft_all(char *piece)
{
	char	**tab;
	int		*iactuel;
	t_var2	*var2;

	var2 = (t_var2 *)malloc(sizeof(t_var2) * 2);
	var2->nbt = nb_tetri(piece);
	iactuel = (int *)malloc(sizeof(int) * var2->nbt + 1);
	tab = all_tetri(dp(piece), 0, 0, 0);
	var2->carac = 'A';
	var2->length = 2;
	var2->chaine = malloc_chaine(var2->chaine, var2->length);
	var2->tetri = 0;
	var2->chaine = mychar(iactuel, 0, tab, var2);
	ft_putstr(var2->chaine);
}
