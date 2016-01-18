/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_form.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:42:35 by avella            #+#    #+#             */
/*   Updated: 2015/12/20 14:42:41 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		right(char *chaine, int i, int count)
{
	if (count < 4)
	{
		i = i + 1;
		count++;
		chaine[i] = 'x';
		if (chaine[i + 1] == '#')
		{
			count = right(chaine, i, count);
		}
		if (chaine[i + 5] == '#')
		{
			count = down(chaine, i, count);
		}
		if (chaine[i - 5] == '#')
		{
			count = up(chaine, i, count);
		}
		if (chaine[i - 1] == '#')
		{
			count = left(chaine, i, count);
		}
	}
	return (count);
}

int		down(char *chaine, int i, int count)
{
	if (count < 4)
	{
		i = i + 5;
		count++;
		chaine[i] = 'x';
		if (chaine[i + 1] == '#')
		{
			count = right(chaine, i, count);
		}
		if (chaine[i + 5] == '#')
		{
			count = down(chaine, i, count);
		}
		if (chaine[i - 5] == '#')
		{
			count = up(chaine, i, count);
		}
		if (chaine[i - 1] == '#')
		{
			count = left(chaine, i, count);
		}
	}
	return (count);
}

int		up(char *chaine, int i, int count)
{
	if (count < 4)
	{
		i = i - 5;
		count++;
		chaine[i] = 'x';
		if (chaine[i + 1] == '#')
		{
			count = right(chaine, i, count);
		}
		if (chaine[i + 5] == '#')
		{
			count = down(chaine, i, count);
		}
		if (chaine[i - 5] == '#')
		{
			count = up(chaine, i, count);
		}
		if (chaine[i - 1] == '#')
		{
			count = left(chaine, i, count);
		}
	}
	return (count);
}

int		left(char *chaine, int i, int count)
{
	if (count < 4)
	{
		i = i - 1;
		count++;
		chaine[i] = 'x';
		if (chaine[i + 1] == '#')
		{
			count = right(chaine, i, count);
		}
		if (chaine[i + 5] == '#')
		{
			count = down(chaine, i, count);
		}
		if (chaine[i - 5] == '#')
		{
			count = up(chaine, i, count);
		}
		if (chaine[i - 1] == '#')
		{
			count = left(chaine, i, count);
		}
	}
	return (count);
}
