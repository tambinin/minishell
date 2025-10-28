/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:04:16 by sandriam          #+#    #+#             */
/*   Updated: 2024/12/27 08:59:28 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_bonus.h"

void	stock_arg(char *s, t_cmd *cmd)
{
	int		i;
	char	*arg;

	i = 0;
	init_variable(cmd);
	arg = NULL;
	while (s[i])
	{
		if (s[i] == '\'' && !cmd->in_double_quote)
		{
			cmd->in_single_quote = !cmd->in_single_quote;
			i++;
			continue ;
		}
		if (s[i] == '\"' && !cmd->in_single_quote)
		{
			cmd->in_double_quote = !cmd->in_double_quote;
			i++;
			continue ;
		}
		add_after_space(cmd, s, i, arg);
		i++;
	}
	add_final_args(s, arg, cmd, i);
}
