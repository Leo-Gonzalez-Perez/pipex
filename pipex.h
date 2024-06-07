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
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

// Declaraciones de funciones de main_and_sons
void	son_2_b(char *p_cmd_2, char **env, char **spl3);
void	son_2(char **argv, char **env, int fd_pipe[2], char **spl3);
void	son_1_b(char **env, char *p_cmd_1, char **spl2);
void	son_1(char **argv, char **env, int fd_pipe[2], char **spl2);
int		main(int argc, char **argv, char **env);

// Declaraciones de funciones de split_joing_paths
int		count_words(char *str, char c);
char	**write_result(char *str, char spliter, char **rtn);
char	**ft_split(char *str, char spliter);
char	*ft_strjoin(char *str_1, char *str_2);
char	**find_the_path(char **env);

// Declaraciones de funciones de aux_1
char	*ft_strnstr(char *main_str, char *sub_str, int len);
char	*ft_strdup2(char *str);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
void	ft_free(char **res);

// Declaraciones de funciones de aux_2
void	take_errors(int argc);
void	ft_free_split(char **split);
void	freedom_split(spl2, spl3);
void	main_util_1(int pid_0);
void	main_util_2(int pid_1);

// Declaraciones de funciones de aux_3
void	main_util_3(int fd_pipe[2], char **spl3);
int		waiting(int pid[2], int status_0, int status_1);
char	*take_cdm(char *argv);
int		is_a_road(char *cmd);

#endif