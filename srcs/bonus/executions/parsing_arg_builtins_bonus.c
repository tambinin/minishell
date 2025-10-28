/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg_builtins_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:26:57 by sandriam          #+#    #+#             */
/*   Updated: 2024/12/27 09:00:56 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_bonus.h"

void	exec_heredoc_builtins(t_cmd *cmd, int temp_pipe_heredoc)
{
	int	i;

	if (contains_heredoc(cmd))
	{
		cmd->count_heredoc = count_heredoc_arg(cmd, cmd->count_heredoc);
		cmd->pipe_heredoc = malloc(sizeof(int *) * cmd->count_heredoc);
		i = 0;
		while (i < cmd->count_heredoc)
			cmd->pipe_heredoc[i++] = malloc(sizeof(int) * 2);
		execute_heredoc_builtins(cmd, cmd->pipe_heredoc, cmd->count_heredoc,
			&temp_pipe_heredoc);
	}
}

int	exec_redir_builtins(t_cmd *cmd)
{
	if (contains_redirection(cmd) && set_sig_heredoc(-1) != 1)
	{
		if (redirection_exec(cmd) == 2)
		{
			if (contains_heredoc(cmd))
				free_pipe_heredoc(cmd->count_heredoc, cmd->pipe_heredoc);
			dup2(cmd->stdout_backup, STDOUT_FILENO);
			dup2(cmd->stdin_backup, STDIN_FILENO);
			close(cmd->stdout_backup);
			close(cmd->stdin_backup);
			return (1);
		}
	}
	return (0);
}
