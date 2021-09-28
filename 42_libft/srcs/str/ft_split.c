/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:54:57 by mhaman            #+#    #+#             */
/*   Updated: 2021/04/21 16:19:29 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**free_tabsplit(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static size_t	ft_compt(const	char *s, char c)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			k++;
		}
	}
	return (k);
}

static char	**ft_tab(const	char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	compt;
	char	**tab;

	i = 0;
	j = 0;
	compt = ft_compt(s, c);
	tab = ft_xmalloc((compt + 1) * sizeof(char *));
	while (*s != '\0' && i <= compt)
	{
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			s++;
			j++;
		}
		if (*s == c || *s == '\0')
		{
			tab[i] = malloc((j + 1) * sizeof(char));
		}
		i++;
	}
	return (tab);
}

extern char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	compt;
	char	**tab;

	i = 0;
	j = 0;
	tab = ft_tab(s, c);
	compt = ft_compt(s, c);
	while (i < compt)
	{
		while (*s == c)
			s++;
		tab[i][j] = *s;
		s++;
		j++;
		if (*s == c || *s == '\0')
		{
			tab[i++][j] = '\0';
			j = 0;
		}
	}
	tab[i] = NULL;
	return (tab);
}
