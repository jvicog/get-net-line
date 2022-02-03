/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:29:07 by jvico-ga          #+#    #+#             */
/*   Updated: 2022/02/02 17:32:46 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*ptr;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (s1 == '\0' || s2 == '\0')
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr = (char *) malloc (sizeof(char) * (lens1 + lens2 + 1));
	if (ptr == NULL)
		return (NULL);
	while (lens1-- > 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (lens2-- > 0)
		ptr[i++] = s2[k++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

int	ft_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_line_aux(char *str, int i)
{
	int		j;
	char	*sol;
	int		aux;

	j = -1;
	aux = 1;
	if (str[i] == '\0')
		aux = 0;
	sol = malloc ((i + aux) * sizeof(char));
	if (sol == '\0')
		return (NULL);
	sol[i + aux] = '\0';
	while (++j <= i)
		sol[j] = str[j];
	return (sol);
}

char	*ft_clean_aux(char *str, char *content)
{
	int		i;
	char	*aux;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && content [i] == str[i])
		i++;
	aux = malloc ((ft_strlen(content) - (i - 1)) * sizeof(char));
	if (aux == '\0')
	{
		free(content);
		return (NULL);
	}
	while (content[i] != '\0')
		aux[j++] = content[i++];
	aux[j] = '\0';
	free(content);
	return (aux);
}
