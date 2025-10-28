/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 07:14:40 by sandriam          #+#    #+#             */
/*   Updated: 2024/12/27 09:51:48 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_bonus.h"

int	match_pattern(char *filename, const char *pattern)
{
	char	*star;
	size_t	prefix_len;
	char	*suffix;
	size_t	filename_len;
	size_t	suffix_len;

	if (ft_strcmp(pattern, "*.*") == 0)
		return (ft_strchr(filename, '.') != NULL);
	star = ft_strchr(pattern, '*');
	if (!star)
		return (ft_strcmp(filename, pattern) == 0);
	prefix_len = star - pattern;
	suffix = star + 1;
	if (ft_strncmp(filename, pattern, prefix_len) != 0)
		return (0);
	filename_len = ft_strlen(filename);
	suffix_len = ft_strlen(suffix);
	if (filename_len < prefix_len + suffix_len)
		return (0);
	return (ft_strcmp(filename + filename_len - suffix_len, suffix) == 0);
}

int	display_matching_files(char *pattern)
{
	DIR				*dir;
	int				len;
	struct dirent	*entry;
	int				found;

	dir = opendir(".");
	if (!dir)
		return (1);
	found = 0;
	len = 0;
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (match_pattern(entry->d_name, pattern))
		{
			found = 1;
			len++;
		}
		entry = readdir(dir);
	}
	closedir(dir);
	if (found == 0)
		return (1);
	else
		return (len);
}

void	add_matching_files(char *pattern, int *j, char **tp)
{
	struct dirent	*entry;
	int				found;
	DIR				*dir;

	dir = opendir(".");
	if (!dir)
		return ;
	found = 0;
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (match_pattern(entry->d_name, pattern) && (ft_strncmp(entry->d_name,
					".", 1) != 0 || ft_strncmp(entry->d_name, "..", 1) != 0))
		{
			tp[(*j)++] = ft_strdup(entry->d_name);
			found = 1;
		}
		entry = readdir(dir);
	}
	closedir(dir);
	if (!found)
	{
		tp[(*j)++] = ft_strdup(pattern);
		return ;
	}
}
