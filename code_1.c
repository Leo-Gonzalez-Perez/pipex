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

void	son_2_b(char *p_cmd_2, char **env, char **spl3)
{	
	char	**paths;
	char	*x;
	int		i;
	
	i = 0;
	paths = find_the_path(env);
	while (paths[i] != NULL)
	{
		paths[i] = ft_strjoin(paths[i], p_cmd_2);
		i++;
	}
	free(p_cmd_2);
	i = 0;
	while (paths[i] && access(paths[i], X_OK) < 0)
		i++;
	x = ft_strdup2(paths[i]);
	ft_free_split(paths);
	execve(x, spl3, env);
	ft_free_split(spl3);
	perror("127. execve's son 2 error");
	perror(x);
	free(x);
	exit (127);
}

void	son_2(char **argv, char **env, int fd_pipe[2], char **spl3)
{
	char	*p_cmd_2;
	int		fd_out;
	int		road;

	close(fd_pipe[1]);
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
	    ft_free_split(spl3);
		(perror("open son_2's function error"), exit (1));
	}
	(dup2(fd_out, 1), close(fd_out), dup2(fd_pipe[0], 0), close(fd_pipe[0]));
	p_cmd_2 = take_cdm(argv[3]);
	road = is_a_road(p_cmd_2);
	if (road || env == NULL || env[0] == NULL)
	{
		execve(p_cmd_2, spl3, env);
		ft_free_split(spl3);
		free(p_cmd_2);
		perror("execve's son 2 error");
		exit (1);
	}
	son_2_b(p_cmd_2, env, spl3);
}

void	son_1_b(char **env, char *p_cmd_1, char **spl2)
{
	char	**paths;
	char	*x;
	int		i;

	i = 0;
	paths = find_the_path(env);
	while (paths[i] != NULL)
	{
		paths[i] = ft_strjoin(paths[i], p_cmd_1);
		i++;
	}
	free(p_cmd_1);
	i = 0;
	while (paths[i] && access(paths[i], X_OK) < 0)
		i++;
	if (paths[i] == NULL)
		exit (1);
	x = ft_strdup2(paths[i]);
	ft_free_split(paths);
	execve(x, spl2, env);
	ft_free_split(spl2);
	free(x);
    (perror("execve's 1 error"), exit (1));
}

void	son_1(char **argv, char **env, int fd_pipe[2], char **spl2)
{
	char	*p_cmd_1;
	int		fd_in;
	int		road;

	(close(fd_pipe[0]), fd_in = open(argv[1], O_RDONLY));
	if (fd_in == -1)
	{
		ft_free_split(spl2);
    	(perror("open son_1's function error"), exit (1));
	}
	(dup2(fd_in, 0), close(fd_in), dup2(fd_pipe[1], 1), close(fd_pipe[1]));
	p_cmd_1 = take_cdm(argv[2]);
	road = is_a_road(p_cmd_1);
	if (road || env == NULL || env[0] == NULL)
	{
		execve(p_cmd_1, spl2, env);
	    ft_free_split(spl2);
    	perror("execve's son 1 error");
		exit (1);
	}
	son_1_b(env, p_cmd_1, spl2);
}
void	take_errors(int argc)
{
	if (argc != 5)
		(perror("too few or too much arguments"), exit (1));
}

void ft_free_split(char **split)
{
    int i = 0;

    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void	freedom_split(spl2, spl3)
{
	if  (spl2)
		ft_free_split(spl2);
	if  (spl3)
		ft_free_split(spl3);
	(perror("split error"), exit (1));
}
int	waiting(int pid_1_2[2], int status[0], int status[1])
{
	waitpid(pid_1_2[0], &status[0], 0);
	waitpid(pid_1_2[1], &status[0], 0);
	if (WIFEXITED(status[0]))
		status[1] = WEXITSTATUS(status[0]);
}

int	main(int argc, char **argv, char **env)
{
	int	fd_pipe[2];
	int	pid_1_2[2];
	int	status[3];
	char **spl2;
	char **spl3;

	take_errors(argc);
	if (pipe(fd_pipe) < 0)
		(perror("pipe's function error"), exit (1));
	spl2 = ft_split(argv[2], ' ');
	spl3 = ft_split(argv[3], ' ');
	if (spl2 == NULL || spl3 == NULL)
		freedom_split(spl2, spl3);
	pid_1_2[0] = fork();
	if (pid_1_2[0] < 0)
		(perror("fork son_1's function error"), exit (1));
	if (pid_1_2[0] == 0)
		son_1(argv, env, fd_pipe, spl2);
	(close(fd_pipe[1]), ft_free_split(spl2));
	pid_1_2[1] = fork();
	if (pid_1_2[1] < 0)
		(perror("fork son_2's function error"), exit (1));
	if (pid_1_2[1] == 0)
		son_2(argv, env, fd_pipe, spl3);
	close(fd_pipe[0]);
	ft_free_split(spl3);
	status[2] = waiting(pid_1_2, status[0], status[1]);
	return (status[2]);
}

