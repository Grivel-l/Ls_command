/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: legrivel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/24 01:18:53 by legrivel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/27 00:41:32 by legrivel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_as_list(t_file *file)
{
	print_filetype(file->file_info.st_mode);
	print_permissions(file->permissions / 100);
	print_permissions(file->permissions % 100 / 10);
	print_permissions(file->permissions % 10);
	ft_putchar(' ');
	ft_putnbr(file->file_info.st_nlink);
	ft_putchar(' ');
	ft_putstr(getpwuid(file->file_info.st_uid)->pw_name);
	ft_putchar(' ');
	ft_putstr(getgrgid(file->file_info.st_gid)->gr_name);
	ft_putchar(' ');
	ft_putnbr(file->file_info.st_size);
	ft_putchar(' ');
	print_time(ctime(&(file->file_info.st_mtim.tv_sec)));
	ft_putchar(' ');
	ft_putstr(file->filename);
}

static int	print_files(t_flist **list, char *options)
{
	if ((*list)->file->is_arg && !(*list)->file->exist)
		enoent_error();
	else
	{
		if (ft_strchr(options, 'l') != NULL)
		{
			print_as_list((*list)->file);
			ft_putchar('\n');
		}
		else
		{
			ft_putstr((*list)->file->filename);
			ft_putchar('\n');
		}
	}
	return (0);
}

void		print_flist(t_flist **list_start, char *options)
{
	if (*list_start != NULL)
	{
		ft_putstr((*list_start)->file->path);
		ft_putchar('\n');
	}
	if (ft_strchr(options, 'r') != NULL)
		browse_reverse_flist(list_start, options, print_files);
	else
		browse_flist(list_start, options, print_files);
}
