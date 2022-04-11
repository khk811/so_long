/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:36:34 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/08 12:09:04 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*alloc_arr(char **arr, int size);
void	*ft_memset_g(void *b, int c, int len);
void	*ft_memmove_g(void *dst, void *src, int len);
int		valid_read(int fd, char **buf);
int		ft_strlen_g(char *s);

#endif
