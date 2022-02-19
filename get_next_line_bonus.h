/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:26:25 by jvico-ga          #+#    #+#             */
/*   Updated: 2022/02/19 13:35:44 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

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
