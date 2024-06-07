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

char	*take_cdm(char *argv)
{
	int		i;
	char	*cmd;

	i = 0;
	while (argv[i] && argv[i] != ' ')
		i++;
	cmd = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (argv[i] && argv[i] != ' ')
	{
		cmd[i] = argv[i];
		i++;
	}
	cmd[i] = '\0';
	return (cmd);
}

int	is_a_road(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '/')
			return (1);
		cmd++;
	}
	return (0);
}
