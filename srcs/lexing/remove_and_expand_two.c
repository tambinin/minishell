/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_and_expand_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:35:09 by tambinin          #+#    #+#             */
/*   Updated: 2024/12/26 15:23:51 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	toggle_quotes(t_cmd *cmd, char ch)
{
	if (ch == '"' && !cmd->in_single_quote)
		cmd->in_double_quote = !cmd->in_double_quote;
	else if (ch == '\'' && !cmd->in_double_quote)
		cmd->in_single_quote = !cmd->in_single_quote;
}

void	skip_add_value(t_cmd *cmd, const char *str, size_t *indices,
		char *result)
{
	if (str[indices[0]] == '$' && !cmd->in_double_quote && (str[indices[0]
				+ 1] == '"' || str[indices[0] + 1] == '\''))
		indices[0]++;
	else if (str[indices[0] + 1] == '"')
	{
		result[indices[1]++] = str[indices[0]];
		indices[0]++;
	}
}

void	expand_status(size_t *indices, char *result)
{
	char	*tmp;
	size_t	i;

	tmp = ft_itoa(set_st(-1));
	i = -1;
	while (++i < ft_strlen(tmp))
		result[indices[1]++] = tmp[i];
	indices[0]++;
	free(tmp);
}

void	init_all(t_cmd *cmd, size_t *indices)
{
	indices[1] = 0;
	indices[0] = 0;
	cmd->in_single_quote = 0;
	cmd->in_double_quote = 0;
}

void	add_double_quote(const char *str, size_t *indices, char *result,
		t_cmd *cmd)
{
	if (ft_isdigit(str[indices[0] + 1]) == 1)
		indices[0]++;
	else if (str[indices[0] + 1] == '$')
	{
		result[indices[1]++] = '$';
		result[indices[1]++] = '$';
		indices[0]++;
	}
	else
		handle_dollar_sign(str, result, indices, cmd);
}
