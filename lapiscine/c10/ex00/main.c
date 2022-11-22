/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:58:01 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/20 15:18:16 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_display_file(char *path)
{
	int		size;
	int		file_discriptor;
	char	buf[1024];

	file_discriptor = open(path, O_RDWR);
	if (file_discriptor < 0)
		return (0);
	size = read(file_discriptor, buf, 1024);
	if (size < 0)
		return (0);
	write(1, buf, size);
	write(1, "\n", 1);
	close(file_discriptor);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	else
	{
		if (ft_display_file(argv[1]))
			return (0);
		else
		{
			write(2, "Cannot read file.\n", 18);
			return (1);
		}
	}
}
