/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:10:02 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/20 13:46:13 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <limits.h>
# include <stdarg.h>

//FT_PRINTF
int		ft_printf(const char *str, ...);
void	ft_print_char(char c, int *len);
void	ft_print_str(char *str, int *len);
void	ft_print_nbr(int i, int *len);
void	ft_print_adr(unsigned long l, int *len);
/*--------------------------------*/
//LIBFT
char	**ft_split(char const *s, char c);
char	*ft_join(char *s1, char *s2, int z);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*--------------------------------*/
//GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
char	*get_next_line(int fd);
char	*ft_fill(char *str);
char	*ft_remainder(char *str);
char	*ft_read(int fd, char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
/*--------------------------------*/
//HELPERS
char	*get_path(char *av, char **env);
int		check_infile(char *path);
int		check_outfile(char *path);
void	ft_error(int err);
void	ft_error_exit(int err);
void	ft_free(char **arr);
void	st_pr(int *pp, char **av, char **env);
void	nd_pr(int *pp, char **av, char **env);
/*--------------------------------*/

#endif