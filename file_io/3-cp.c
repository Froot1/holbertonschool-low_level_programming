#include "main.h"

/**
 * main - program that copies the content of a file to another file.
 * @ac: Int
 * @argv: Char
 *
 * Return: Always 0.
 */

int main(int ac, char *argv[])
{
	int fd_from, fd_to, read_count, write_count, close_status;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	read_count = 1;
	while (read_count)
	{
		read_count = read(fd_from, buffer, 1024);
		if (read_count == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}

		write_count = write(fd_to, buffer, read_count);
		if (write_count == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to%s\n", argv[2]);
			exit(99);
		}
	}

	close_status = close(fd_from);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	close_status = close(fd_to);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);

}
