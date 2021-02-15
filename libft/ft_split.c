/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:41:59 by seonchoi          #+#    #+#             */
/*   Updated: 2021/01/24 21:47:24 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			i++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*ft_free(char **temp)
{
	unsigned int	i;

	i = 0;
	while (temp[i] != 0)
		free(temp[i++]);
	free(temp);
	return (0);
}

char	*ft_subsplit(char const *s, unsigned int start, size_t len, char **t)
{
	char *str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (ft_free(t));
	ft_strlcpy(str, (char *)s + start, len + 1);
	return (str);
}

/*
** idx[0] = start, idx[1] = end, idx[2] = len, idx[3] = i (split index)
*/

char	**ft_split(char const *s, char c)
{
	int		idx[4];
	char	**split;

	idx[0] = 0;
	idx[1] = -1;
	idx[2] = 0;
	idx[3] = 0;
	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1))))
		return (NULL);
	while (s[++idx[1]])
		if (s[idx[1]] != c)
		{
			idx[0] = idx[1];
			while (s[idx[1]] != c && s[idx[1]])
				idx[1]++;
			idx[2] = idx[1] - idx[0];
			split[idx[3]++] = ft_subsplit(s, idx[0], idx[2], split);
			if (s[idx[1]] == 0)
				break ;
		}
	split[idx[3]] = NULL;
	return (split);
}
