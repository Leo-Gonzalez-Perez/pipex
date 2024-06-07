/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:03:55 by lgonzal2          #+#    #+#             */
/*   Updated: 2024/06/05 22:07:24 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	main_util_3(int fd_pipe[2], char **spl3)
{
	close(fd_pipe[0]);
	ft_free_split(spl3);
}

int	waiting(int pid[2], int status_0, int status_1)
{
	waitpid(pid[0], &status_0, 0);
	waitpid(pid[1], &status_0, 0);
	if (WIFEXITED(status_0))
		status_1 = WEXITSTATUS(status_0);
	return (status_1);
}

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
