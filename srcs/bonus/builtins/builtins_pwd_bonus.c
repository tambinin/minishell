/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:21:58 by tambinin          #+#    #+#             */
/*   Updated: 2024/12/27 09:01:40 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_bonus.h"

void	ft_pwd(char **argv)
{
	char	cwd[1024];

	if (argv[1] && argv[1][0] == '-')
	{
		set_st(1);
		ft_putendl_fd("no option is allowed", STDERR_FILENO);
		return ;
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		set_st(0);
		ft_putendl_fd(cwd, STDOUT_FILENO);
	}
	else
		perror("pwd");
}
