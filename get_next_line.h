/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:26:25 by jvico-ga          #+#    #+#             */
/*   Updated: 2022/02/02 17:50:52 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);

int		ft_new_line(char *str);
char	*ft_clean_aux(char *str, char *content);
char	*ft_line_aux(char *str, int i);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
int		get_next_line_aux(char **content, char **str);
char	*ft_line(char *str);
char	*ft_clean(char *str, char *content);
char	*get_next_line(int fd);

#endif
