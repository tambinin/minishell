/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils_two_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:50:12 by sandriam          #+#    #+#             */
/*   Updated: 2024/12/27 08:58:01 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_bonus.h"

int	check_syntax_one(t_token **tokens, int len_tokens, int i)
{
	if ((tokens[i]->type == REDIR_IN || tokens[i]->type == REDIR_OUT
			|| tokens[i]->type == REDIR_OUTPUT_APPEND
			|| tokens[i]->type == REDIR_HEREDOC) && i + 1 == len_tokens)
	{
		set_st(2);
		return (-2);
	}
	return (0);
}
