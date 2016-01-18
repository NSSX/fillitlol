/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:19:08 by avella            #+#    #+#             */
/*   Updated: 2016/01/18 18:20:35 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*trans_di(char *chaine, char c)
{
	int i;

	i = 0;
	while (chaine[i] != '\0')
	{
		if (chaine[i] == 'x')
			chaine[i] = c;
		i++;
	}
	return (chaine);
}

char	**all_tetri(char *chaine, int i, int index, int i2)
{
	char	**tab;
	int		nb;

	nb = nb_tetri(chaine);
	tab = (char **)malloc(sizeof(char *) * nb + 1);
	while (i < nb + 1)
	{
		tab[i] = (char *)malloc(sizeof(char) * 20);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		while (i2 < 20 && chaine[index] != '\0')
		{
			tab[i][i2] = chaine[index];
			i2++;
			index++;
		}
		tab[i][i2] = '\0';
		i2 = 0;
		index++;
		i++;
	}
	return (tab);
}

char	*malloc_chaine(char *chaine, int length)
{
	int i;
	int j;
	int index;
	int l;

	index = 0;
	i = 0;
	j = 0;
	l = (length * length) + length;
	chaine = (char*)malloc(sizeof(char) * l + 1);
	while (i < length)
	{
		while (j < length)
		{
			chaine[index] = '.';
			j++;
			index++;
		}
		chaine[index] = '\n';
		index++;
		j = 0;
		i++;
	}
	chaine[index] = '\0';
	return (chaine);
}
