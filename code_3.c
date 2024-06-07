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

char	*ft_strnstr(char *main_str, char *sub_str, int len)
{
	int	h;
	int	n;

	h = 0;
	if (sub_str[0] == '\0')
		return ((char *)main_str);
	while (main_str[h] != '\0')
	{
		n = 0;
		while (main_str[h + n] == sub_str[n] && (h + n) < len)
		{
			if (main_str[h + n] == '\0' && sub_str[n] == '\0')
				return ((char *) &(main_str[h]));
			n++;
		}
		if (sub_str[n] == '\0')
			return ((char *)main_str + h);
		h++;
	}
	return (0);
}

char	*ft_strdup2(char *str)
{
	int		i;
	char	*rtn;

	if (!str)
		return (ft_strdup2(""));
	i = 0;
	while (str[i] != '\0')
		i++;
	rtn = malloc(sizeof(char) * i + 1);
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	int		count;
	int		size;
	char	*rtn;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup2(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	rtn = (char *)malloc((len + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	count = 0;
	while (count < len)
	{
		rtn[count] = s[start + count];
		count++;
	}
	rtn[count] = '\0';
	return (rtn);
}

void	ft_free(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
}
