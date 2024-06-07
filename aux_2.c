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

void	take_errors(int argc)
{
	if (argc != 5)
		(perror("too few or too much arguments"), exit (1));
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}

void	freedom_split(spl2, spl3)
{
	if (spl2)
		ft_free_split(spl2);
	if (spl3)
		ft_free_split(spl3);
	(perror("split error"), exit (1));
}

void	main_util_1(int pid_0)
{
	if (pid_0 < 0)
	{
		perror("fork son_1's function error");
		exit (1);
	}
}

void	main_util_2(int pid_1)
{
	if (pid_1 < 0)
	{	
		perror("fork son_2's function error");
		exit (1);
	}
}
