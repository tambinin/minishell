/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_part_two_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:40:38 by tambinin          #+#    #+#             */
/*   Updated: 2024/12/27 09:02:20 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_bonus.h"

void	sig_handler_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		set_st(130);
		set_sig_heredoc(1);
		close(STDIN_FILENO);
	}
}

void	sig_handler_heredoc_blt(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		set_st(130);
		set_sig_heredoc(1);
		close(STDIN_FILENO);
	}
}

void	sig_handler_heredoc_pipe(int signal)
{
	if (signal == SIGINT)
	{
		set_st(130);
		set_sig_heredoc(1);
		write(1, "\n", 1);
		rl_replace_line("", 0);
		close(STDIN_FILENO);
	}
}
