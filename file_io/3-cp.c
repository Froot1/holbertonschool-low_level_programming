#include "main.h"

/**
 * main - program that copies the content of a file to another.
 * @argc: number of input arguments.
 * @argv: input arguments array.
 *
 * Return: 0 on success.
 */

int main(int argc, char *argv[])
{
	int from, to, error = 0;

	if (argc != 3)
	{
		write(STDERR_FILENO, "Usage: cp file_from file_to\n", 28);
		exit(97);
	}

	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	error = copy_f(from, argv[1], to, argv[2]);
	if (error != 0)
		exit(error);

	if (close(from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}
	if (close(to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to);
		exit(100);
	}
	return (0);
}

/**
 * copy_f - executes the copy of the files validated on main.
 * @from: file descriptor number from which the content will be taken.
 * @f_from: name of the file from.
 * @to: file descriptor number where the copy will be made.
 * @f_to: name of the file to.
 *
 * Return: 0 on success, 98 if fails to read from, 99 if fails to write to.
 */

int copy_f(int from, const char *f_from, int to, const char *f_to)
{
	char buf[1024] = "";
	ssize_t bsize = sizeof(buf) / sizeof(buf[0]);
	ssize_t r = 1, w = 0;

	while ((r = read(from, buf, bsize)) > 0)
	{
		w = write(to, buf, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", f_to);
			exit(99);
		}
	}
	if (r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", f_from);
		return (98);
	}

	return (0);
}
