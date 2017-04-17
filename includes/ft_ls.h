/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:28:16 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/14 14:35:00 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include "libft.h"
# include <sys/stat.h>
# include <time.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>

# define SIX_MONTH 15777777

typedef struct		s_flags
{
	unsigned int	l : 1;
	unsigned int	rr : 1;
	unsigned int	a : 1;
	unsigned int	r : 1;
	unsigned int	t : 1;
	unsigned int	n : 1;
	unsigned int	f : 1;
	unsigned int	g : 1;
	unsigned int	d : 1;
	unsigned int	i : 1;
	unsigned int	ss : 1;
}					t_flags;

typedef struct		s_pflags
{
	unsigned int	inode : 1;
	unsigned int	mode : 1;
	unsigned int	link : 1;
	unsigned int	uid : 1;
	unsigned int	gid : 1;
	unsigned int	size : 1;
	unsigned int	mtime : 1;
	unsigned int	name : 1;
}					t_pflags;

typedef struct		s_flgs
{
	t_flags		f;
	t_pflags	p;
}					t_flgs;

typedef struct		s_elem
{
	struct stat		buf;
	char			*name;
	char			*path;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_dirlst
{
	char			*path;
	struct s_dirlst	*next;
	struct s_dirlst	*prev;
}					t_dirlst;

typedef struct		s_env
{
	struct s_dirlst		*dirs;
	struct s_dirlst		*nondirs;
	struct s_dirlst		*files;
	int					count;
	int					noncount;
	int					fcount;
}					t_env;

void				ls_recursion(t_elem *head, char *currentdir, t_flgs fl,
						t_env *env);
void				ls_handle_dirs(t_env *env, t_flgs fl);
void				ls_handle_nof(t_env *env, t_flgs fl);
void				ls_handle_files(t_env *env, t_flgs fl);
void				ls_lstadd_dir(t_dirlst **head, char *path);
void				ls_parse_dir(int argc, char *argv[], t_flags f, t_env *env);
int					ls_set_l(t_flgs *flags);
int					ls_inval_option(char c);
void				ls_setflags(char c, t_flgs *fl);
void				ls_parseflags(int argc, char *argv[], t_flgs *flags);
void				ls_print_mode(t_elem *node);
void				ls_print_uid(t_elem *head, t_elem *node, t_flags f);
void				ls_print_gid(t_elem *head, t_elem *node, t_flags f);
void				ls_print_name(t_elem *node, t_flags f);
void				ls_lstprint(t_elem *head, t_pflags p, t_flags f);
int					ls_clc_lnk(t_elem *head);
int					ls_clc_sze(t_elem *head);
void				ls_lstadd(t_elem **head, struct stat buf,
						char *name, char *dir);
void				ls_lstswap_dir(t_dirlst *left, t_dirlst *right);
void				ls_sort_dir(t_dirlst **head, t_flags f,
						int (*direction)(char *, char *));
void				ls_sort(t_elem **head, t_flags f);
void				ls_lstswap(t_elem *left, t_elem *right);
int					ls_strcmp(const char *s1, const char *s2);
void				ls_lstswap(t_elem *left, t_elem *right);
int					ls_strcmp(const char *s1, const char *s2);
void				ls_sort_time(t_elem **head, t_flags f,
						int (*direction)(time_t, time_t));
void				ls_sort_name(t_elem **head, t_flags f,
						int (*direction)(char *, char *));
void				ls_print_filetype(struct stat filestat);
void				ls_lstprint(t_elem *head, t_pflags p, t_flags f);
int					norm_name(char *str1, char *str2);
int					rev_name(char *str1, char *str2);
blkcnt_t			calc_blocks(t_elem *head);
void				ft_ls(t_env *env, t_flgs fl, char *currentdir);
void				ls_print_time(t_elem *node);
char				*ls_next_dir(char *curdir, char *nextdir);
int					ls_set_g(t_flgs *flags);
int					ls_set_i(t_flgs *flags);
int					ls_clc_inode(t_elem *head);
int					ls_digits(int d);
int					ls_set_d(t_flgs *flags);
void				ls_sort_size(t_elem **hd, t_flags f, int (*s)(long int, long
						int), int(*n)(char *, char *));
int					norm_size(long int left, long int right);
int					rev_size(long int left, long int right);
void				ls_printblocks(t_elem *head, t_flags f);
int					ls_clc_uid(t_elem *head);
int					ls_clc_gid(t_elem *head);
void				ls_print_size(t_elem *head, t_elem *node);
int					ls_clc_major(t_elem *head);
int					ls_clc_minor(t_elem *head);
#endif
