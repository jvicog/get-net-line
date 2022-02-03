/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:27:32 by jvico-ga          #+#    #+#             */
/*   Updated: 2022/02/02 17:50:55 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_new_line(char *str);
char	*ft_clean_aux(char *str, char *content);
char	*ft_line_aux(char *str, int i);
int		get_next_line_aux(char **content, char **str);

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
	static char	*content;
	char		*str;
	int			bytes;

	if (!get_next_line_aux(&content, &str))
		return (NULL);
	while (!ft_new_line(content))
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		str[bytes] = '\0';
		content = ft_strjoin (content, str);
	}
	if (str != NULL && content != NULL)
	{
		free (str);
		str = ft_line (content);
		content = ft_clean (str, content);
		return (str);
	}
	if (str != NULL)
		free(str);
	free (content);
	return (NULL);
}

int	get_next_line_aux(char **content, char **str)
{
	*str = malloc ((BUFFER_SIZE + 1) * sizeof (char));
	if (*str == '\0')
	{
		if (*content != '\0')
			free (*content);
		return (0);
	}
	if (*content == '\0')
	{
		*content = malloc ((BUFFER_SIZE + 1) * sizeof (char));
		if (*content == NULL)
		{
			free (*str);
			return (0);
		}
	}
	return (1);
}
