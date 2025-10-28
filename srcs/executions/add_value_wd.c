/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_value_wd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 07:34:09 by sandriam          #+#    #+#             */
/*   Updated: 2024/12/27 09:44:41 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_value_wd(int k, int *j, t_cmd *cmd, char **my_t_cmd)
{
	if (cmd->tokens[k]->type == ARG && ft_strlen(cmd->tokens[k]->value) == 3
		&& ft_strchr(cmd->tokens[k]->value, '*')
		&& ft_strchr(cmd->tokens[k]->value, '.'))
		add_matching_files(cmd->tokens[k]->value, j, my_t_cmd);
	else
		my_t_cmd[(*j)++] = ft_strdup(cmd->tokens[k]->value);
}

void	add_value_wd_pipe(t_cmd *cmd, int i, int *j, int *k)
{
	if (cmd->tp_arg[i][(*j)]->type == ARG && ft_strlen(cmd->tp_arg[i][(*j)]->value) == 3
		&& ft_strchr(cmd->tp_arg[i][(*j)]->value, '*')
		&& ft_strchr(cmd->tp_arg[i][(*j)]->value, '.'))
		add_matching_files(cmd->tp_arg[i][(*j)]->value, k, cmd->tp_arg[i][0]->tp_args);
	else
		cmd->tp_arg[i][0]->tp_args[(*k)++] = ft_strdup(
						cmd->tp_arg[i][(*j)]->value);
}