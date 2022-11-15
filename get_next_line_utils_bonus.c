/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahsine <abahsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:11:40 by abahsine          #+#    #+#             */
/*   Updated: 2022/11/15 10:02:46 by abahsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i++] = s2[j];
		j++;
	}
	str[i] = '\0';
	return (free(s1), str);
}

int	ft_is_newline(char *buffer, int bytes_read)
{
	int	i;

	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n' && i < bytes_read)
		i++;
	if (buffer && buffer[i] && buffer[i] == '\n')
		return (1);
	return (0);
}

char	*ft_read_line(int fd, char *keep)
{
	char	*buffer;
	int		bytes_read;
	int		is_newline;

	is_newline = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!is_newline)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(keep), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		is_newline = ft_is_newline(buffer, bytes_read);
		keep = ft_strjoin(keep, buffer);
	}
	return (free(buffer), keep);
}
