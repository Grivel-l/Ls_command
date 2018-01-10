/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   options.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: legrivel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 23:19:10 by legrivel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 22:39:59 by legrivel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		option_error(void)
{
	ft_putstr_fd("Invalid option\n", 2);
}

static int		add_option(char **options, char c)
{
	if (ft_strchr(*options, c) != NULL)
		return (0);
	if (c == 'l')
		*options = ft_strrealloc(*options, "l");
	else if (c == 'R')
		*options = ft_strrealloc(*options, "R");
	else if (c == 'a')
		*options = ft_strrealloc(*options, "a");
	else if (c == 'r')
		*options = ft_strrealloc(*options, "r");
	else if (c == 't')
		*options = ft_strrealloc(*options, "t");
	else
	{
		option_error();
		return (-1);
	}
	if (*options == NULL)
		return (-1);
	return (0);
}

static size_t	get_args_nbr(size_t argc, char **argv)
{
	size_t	i;
	size_t	args_nbr;

	i = 0;
	args_nbr = 0;
	while (i < argc - 1)
	{
		if (argv[i][0] != '-')
			args_nbr += 1;
		i += 1;
	}
	return (args_nbr);
}

char			*get_options(size_t argc, char **argv)
{
	size_t	i;
	char	*pointer;
	char	*options;

	i = 0;
	options = NULL;
	if ((options = ft_strnew(1)) == NULL || argc-- <= 1)
		return (options);
	while (i < argc)
	{
		if (argv[i][0] != '-')
			return (options);
		pointer = argv[i];
		argv[i] += 1;
		while (*(argv[i]))
		{
			if (add_option(&options, *(argv[i])) == -1)
				return (NULL);
			argv[i] += 1;
		}
		argv[i] = pointer;
		i += 1;
	}
	return (options);
}

t_flist			*get_args_list(size_t argc, char **argv)
{
	size_t	i;
	t_flist	*list;
	t_flist	*pointer;
	size_t	args_nbr;

	i = 0;
	pointer = NULL;
	args_nbr = get_args_nbr(argc, argv);
	while (i < argc - 1)
	{
		if (argv[i++][0] != '-')
		{
			if (pointer == NULL)
			{
				if ((list = new_flist(new_file(argv[i - 1], "", args_nbr > 1))) == NULL)
					return (NULL);
				pointer = list;
			}
			else
			{
				if ((list->left = new_flist(new_file(argv[i - 1], "", args_nbr > 1))) == NULL)
					return (NULL);
				list = list->left;
			}
		}
	}
	return (pointer == NULL ? new_flist(new_file(".", "", 0)) : pointer);
}
