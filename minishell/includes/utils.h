/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:07:32 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 03:33:54 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

int			ft_isspace(char c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_toupper(int c);

t_envnode	*create_envnode(t_envnode *head, char *key, char *value);
t_envnode	*get_env_node(t_envnode *env_list, char *key);
void		set_env_node(t_data *data, char *key, char *value);

void		parse_error(t_data *data, char *msg);
void		system_error(char *msg);
void		eof_exit(char *msg);
void		execve_error(char *command);

void		quick_sort(char **arr, int left, int right);

void		free_tokens(t_data *data);
void		free_parse_tree(t_treenode *node);
void		free_env_list(t_data *data);
void		free_heredoc_list_close_fd(t_data *data);
void		free_file_list(t_filelist *head);

void		signal_handler(int sig);
void		signal_handler_parent(int sig);
void		signal_handler_heredoc(int sig);
void		signal_handler_quit(int sig);

void		signal_default(void);
void		signal_child(void);
void		signal_parent(void);

char		**ft_split(const char *s, char c);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_str_alphabet_cmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);

char		*ft_itoa(int n);
char		*generate_random_heredoc_filepath(int length);
char		*ft_strdup(const char *s1);

char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin3(const char *s1, const char *s2, const char *s3);

void		*readdir_s(DIR *dir);
void		closedir_s(DIR *dir);

void		*malloc_s(size_t size);
int			fork_s(void);

#endif