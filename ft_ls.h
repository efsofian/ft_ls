/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 11:34:41 by seliasbe          #+#    #+#             */
/*   Updated: 2018/01/07 12:45:41 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "./libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <limits.h>
# include <sys/xattr.h>

typedef DIR				t_dir;
typedef struct dirent	t_entr;
typedef struct stat		t_stat;
typedef struct passwd	t_pwd;
typedef struct group	t_grd;
typedef struct			s_flag
{
	int					alm;
	int					rec;
	int					tim;
	int					a;
	int					g;
	int					l;
	int					o;
	int					r;
}						t_flag;

typedef struct			s_ftls
{
	char				*name;
	char				*full;
	t_stat				*buf;
	int					err;
}						t_ftls;

extern t_flag			g_flag;
extern int				(*g_sort)();
extern int				g_total;
extern int				g_link;
extern int				g_size;
void					ft_ls(char *arg);
void					ls_build_arg(int ac, char **av);
int						ls_flag(char *arg);
void					ls_mergesort(t_list **file,
							int (*sort)(t_ftls*, t_ftls*));
int						sort_alpha(t_ftls *a, t_ftls *b);
int						sort_time(t_ftls *a, t_ftls *b);
void					ls_reset_len(void);
void					ls_store(t_list **file, char *name, char *path);
void					ls_free_lst(void *node, size_t size);
void					ls_print(t_ftls *stat);
void					ls_error(char *arg, int i);
#endif
