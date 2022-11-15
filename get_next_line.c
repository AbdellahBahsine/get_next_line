/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahsine <abahsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:11:35 by abahsine          #+#    #+#             */
/*   Updated: 2022/11/15 10:01:52 by abahsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *keep)
{
	char	*line;
	int		i;

	i = 0;
	if (keep[i] == '\0')
		return (NULL);
	line = malloc((ft_strlen(keep) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (keep[i] && keep[i] != '\n')
	{
		line[i] = keep[i];
		i++;
	}
	if (keep[i] && keep[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_keep(char *keep)
{
	char	*new_keep;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (keep[i] == '\0')
		return (free(keep), NULL);
	while (keep[i] && keep[i] != '\n')
		i++;
	if (keep[i] && keep[i] == '\n')
		i++;
	while (keep[i + j])
		j++;
	new_keep = malloc((j + 1) * sizeof(char));
	if (!new_keep)
		return (free(keep), NULL);
	j = -1;
	while (keep[i + ++j])
		new_keep[j] = keep[i + j];
	new_keep[j] = '\0';
	return (free(keep), new_keep);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*line;

	if (fd == -1 || BUFFER_SIZE == 0)
		return (NULL);
	keep = ft_read_line(fd, keep);
	if (!keep)
		return (NULL);
	line = ft_get_line(keep);
	keep = ft_get_keep(keep);
	return (line);
}
