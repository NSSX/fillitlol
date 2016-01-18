/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_try.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:02:09 by avella            #+#    #+#             */
/*   Updated: 2015/12/20 14:39:46 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try_1(char *chaine)
{
	int i;

	i = 0;
	while (chaine[i] != '\0')
	{
		if (chaine[i] != '.' && chaine[i] != '#' && chaine[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		try_2(char *chaine, int count, int time, int i)
{
	while (chaine[i] != '\0')
	{
		while (time < 4)
		{
			while (chaine[i] != '\n')
			{
				if (chaine[i] == '.' || chaine[i] == '#')
					count++;
				i++;
			}
			if (count != 4)
				return (0);
			count = 0;
			i++;
			time++;
		}
		time = 0;
		if (chaine[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		try_3(char *chaine, int count, int time, int i)
{
	while (chaine[i] != '\0')
	{
		while (time < 4)
		{
			while (chaine[i] != '\n')
			{
				if (chaine[i] == '#')
					count++;
				i++;
			}
			i++;
			time++;
		}
		if (count != 4)
			return (0);
		if (chaine[i] == '\0')
			return (1);
		count = 0;
		time = 0;
		i++;
	}
	return (1);
}

int		try_f(char *chaine, int i)
{
	int count;

	count = 0;
	while (chaine[i] != '#' && chaine[i] != '\0')
		i++;
	if (chaine[i] == '#')
		count++;
	else
		return (0);
	chaine[i] = 'x';
	if (chaine[i + 1] == '#')
		count = right(chaine, i, count);
	if (chaine[i + 5] == '#')
		count = down(chaine, i, count);
	if (chaine[i - 5] == '#')
		count = up(chaine, i, count);
	if (chaine[i - 1] == '#')
		count = left(chaine, i, count);
	if (count == 4)
		return (1);
	return (0);
}

int		try_4(char *chaine)
{
	int i;
	int myi;

	myi = 0;
	i = 0;
	i = nb_tetri(chaine);
	while (i > 0)
	{
		if (!try_f(chaine, myi * 21))
			return (0);
		myi++;
		i--;
	}
	return (1);
}
