/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:39:22 by panther           #+#    #+#             */
/*   Updated: 2023/11/23 00:16:20 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*use_read_on_line(int fd, char *line)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*read_line;
	static char	*line[1024];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = use_read_on_line(fd, line[fd]);
	if (!line[fd])
	{
		return (NULL);
	}
	read_line = extract_line(line[fd]);
	line[fd] = update_line(line[fd]);
	return (read_line);
}

// int main(void)
// {
//   char  *line;
//   int		i;
//   int		fd1;
//   int		fd2;
//   int		fd3;

//   fd1 = open("tests/bigline_no_nl.txt", O_RDONLY);
//   fd2 = open("tests/bigline_with_nl.txt", O_RDONLY);
//   fd3 = open("tests/empty.txt", O_RDONLY);
//   i = 0;
//   while (i < 3)
//   {
//     printf(BOLD BRIGHT_BLUE "Testing file : tests/bigline_no_nl.txt\n");
//     line = get_next_line(fd1);
//     printf(BOLD BRIGHT_PURPLE
// "---------------------------------------------------------------\n");
//     printf(RESET WHITE "line [%02d]: %s", i, line);
//     free(line);
//     puts("\n");
//     printf(BOLD BRIGHT_BLUE "Testing file : tests/bigline_with_nl.txt\n");
//     line = get_next_line(fd2);
//     printf(BOLD BRIGHT_PURPLE
// "---------------------------------------------------------------\n");
//     printf(RESET WHITE "line [%02d]: %s", i, line);
//     free(line);
//     puts("\n");
//     printf(BOLD BRIGHT_BLUE "Testing file : tests/empty.txt\n");
//     line = get_next_line(fd3);
//     printf(BOLD BRIGHT_PURPLE
// "---------------------------------------------------------------\n");
//     printf(RESET WHITE "line [%02d]: %s", i, line);
//     free(line);
//     puts("\n");
//     i++;
//     }
//     close(fd1);
//     close(fd2);
//     close(fd3);
//     return (0);
// }
