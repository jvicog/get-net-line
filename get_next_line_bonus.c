/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:27:32 by jvico-ga          #+#    #+#             */
/*   Updated: 2022/02/19 13:35:46 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_line(char *str)
{
	int		i;

	i = 0;
	if (str[0] == 0)
		return (0);
	while (1)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (ft_line_aux(str, i));
		i++;
	}
	return (NULL);
}

char	*ft_clean(char *str, char *content)
{
	if (content == NULL || str == NULL)
	{
		free(str);
		free(content);
		return (NULL);
	}
	if (ft_new_line(content) == 1)
		return (ft_clean_aux(str, content));
	free(content);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*content[65535];
	char		*str;
	int			bytes;

	if (fd < 0 || fd > 65535 || !get_next_line_aux(&content[fd], &str))
		return (NULL);
	while (!ft_new_line(content[fd]))
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		str[bytes] = '\0';
		content[fd] = ft_strjoin (content[fd], str);
	}
	if (str != NULL && content[fd] != NULL)
	{
		free (str);
		str = ft_line (content[fd]);
		content[fd] = ft_clean (str, content[fd]);
		return (str);
	}
	if (str != NULL)
		free(str);
	free (content[fd]);
	return (NULL);
}

int	get_next_line_aux(char **content, char **str)
{
	*str = malloc ((BUFFER_SIZE + 1) * sizeof (char));
	if (*str == NULL)
	{
		if (*content != NULL)
			free (*content);
		return (0);
	}
	if (*content == NULL)
	{
		*content = malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (*content == NULL)
		{
			free (*str);
			return (0);
		}
		**content = '\0';
	}
	return (1);
}
