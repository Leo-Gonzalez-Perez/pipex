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

// Declaraciones de funciones de code_1.c
void	son_2_b(char *p_cmd_2, char **env, char **take_split_3);
void	son_2(int argc, char **argv, char **env, int fd_pipe[2], char **take_split_3);
void	ft_free_split(char **split);
void	son_1_b(char **env, char *p_cmd_1, char **take_split_2);
void	son_1(char **argv, char **env, int fd_pipe[2], char **take_split_2);
void	take_errors(int argc);

// Declaraciones de funciones de code_2.c
int		count_words(char *str, char c);
char	**write_result(char *str, char spliter, char **rtn);
char	**ft_split(char *str, char spliter);
char	*ft_strjoin(char *str_1, char *str_2);
char	**find_the_path(char **env);

// Declaraciones de funciones de code_3.c
char	*ft_strnstr(char *main_str, char *sub_str, int len);
char	*ft_strdup2(char *str);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
void	ft_free(char **res);

// Declaraciones de funciones de code_4.c
char	*take_cdm(char *argv);
int		is_a_road(char *cmd);

#endif