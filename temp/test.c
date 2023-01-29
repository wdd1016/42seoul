/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:06 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/29 18:58:27 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define UTF8_1 0x7F
#define UTF8_2 0x7FF
#define UTF8_3 0xFFFF
#define UTF8_4 0x1FFFFF

static void	ft_utf_4(int unicode, int fd)
{
	unsigned char buf;
	buf = (unicode >> 18 & 7) | 240;
	write(fd, &buf, 1);
	buf = (unicode >> 12 & 63) | 128;
	write(fd, &buf, 1);
	buf = (unicode >> 6 & 63) | 128;
	write(fd, &buf, 1);
	buf = (unicode & 63) | 128;
	write(fd, &buf, 1);
}
static void	ft_utf_3(int unicode, int fd)
{
	unsigned char buf;
	buf = (unicode >> 12 & 15) | 224;
	write(fd, &buf, 1);
	buf = (unicode >> 6 & 63) | 128;
	write(fd, &buf, 1);
	buf = (unicode & 63) | 128;
	write(fd, &buf, 1);
}
static void	ft_utf_2(int unicode, int fd)
{
	unsigned char buf;
	buf = unicode >> 6 | 192;
	write(fd, &buf, 1);
	buf = (unicode & 63) | 128;
	write(fd, &buf, 1);
}
static void	ft_utf_1(char unicode, int fd)
{
	write(fd, &unicode, 1);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putwchar_fd(int unicode, int fd)
{
	if ((unicode | UTF8_1) == UTF8_1)
		ft_utf_1(unicode, fd);
	else if ((unicode | UTF8_2) == UTF8_2)
		ft_utf_2(unicode, fd);
	else if ((unicode | UTF8_3) == UTF8_3)
		ft_utf_3(unicode, fd);
	else if ((unicode | UTF8_4) == UTF8_4)
		ft_utf_4(unicode, fd);
	else
		ft_putchar_fd(unicode, fd);
}

int main(void)
{
	ft_putwchar_fd(9760, 1);
}