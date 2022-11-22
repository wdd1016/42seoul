/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:46:00 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/12 17:56:39 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = argc;
	while (--i > 0)
	{
		while (*argv[i])
		{
			write(1, argv[i], 1);
			(argv[i])++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
