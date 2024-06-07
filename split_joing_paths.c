/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:03:55 by lgonzal2          #+#    #+#             */
/*   Updated: 2023/02/18 14:31:10 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	count_words(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == c || str[i + 1] == '\0') && str[i] != c)
			words++;
		i++;
	}
	return (words);
}

char	**write_result(char *str, char spliter, char **rtn)
{
	int	start;
	int	i;
	int	word;

	start = 0;
	i = 0;
	word = 0;
	while (str[i] != 0)
	{
		if ((str[i + 1] == spliter || str[i + 1] == '\0') && str[i] != spliter)
		{
			rtn[word] = ft_substr(str, start, i - start + 1);
			if (!rtn[word])
			{
				ft_free(rtn);
				return (0);
			}
			word++;
		}
		if (str[i] == spliter && (str[i + 1] != spliter || str[i + 1] != '\0'))
			start = i + 1;
		i++;
	}
	rtn[word] = 0;
	return (rtn);
}

char	**ft_split(char *str, char spliter)
{
	char	**rtn;

	if (str == 0)
		return (0);
	rtn = (char **)malloc(sizeof(char *) * (count_words(str, spliter) + 1));
	if (rtn == 0)
		return (0);
	rtn = write_result(str, spliter, rtn);
	return (rtn);
}

char	*ft_strjoin(char *str_1, char *str_2)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	rtn = malloc(sizeof(char) * (ft_strlen(str_1) + ft_strlen(str_2) + 1));
	if (rtn == NULL)
		return (free(str_1), NULL);
	while (i < ft_strlen(str_1))
	{
		rtn[i] = str_1[i];
		i++;
	}
	while (j < ft_strlen(str_2))
	{
		rtn[i] = str_2[j];
		i++;
		j++;
	}
	rtn[i] = '\0';
	free(str_1);
	return (rtn);
}

char	**find_the_path(char **env)
{
	int		i;
	char	*track;
	char	**paths;

	i = 0;
	while (env[i] != NULL)
	{
		track = ft_strnstr(env[i], "PATH=", 5);
		if (track == NULL)
			i++;
		else
			break ;
	}
	if (env[i] == NULL)
		return (NULL);
	paths = ft_split(track + 5, ':');
	i = 0;
	while (paths[i] != NULL)
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	return (paths);
}
