/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_swap_int.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: legrivel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 01:54:21 by legrivel     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 01:54:21 by legrivel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_swap_int(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}
