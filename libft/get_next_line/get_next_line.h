/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:58:07 by rojornod          #+#    #+#             */
/*   Updated: 2025/01/31 14:08:14 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

size_t	get_length(const char *str);
char	*combine_strings(char *p_line, char *buf);
//char	*ft_strchr(char *str, int search);
char	*get_next_line(int fd);
char	*extract_line(char *buffer);
char	*read_and_join(int fd, char *buffer, char *line);
void	manage_buffer(char *buffer);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *c );

#endif
