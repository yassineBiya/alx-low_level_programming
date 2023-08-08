#include "main.h"

char *f_buf_create(char *file);
void f_close(int fd);

/**
 * f_buf_create - allocates memory for a character f_buf.
 *
 * @file: the name of the file for which the f_buf is being created.
 *
 * Return: pointer to the dynamically allocated character f_buf.
 */
char *f_buf_create(char *file)
{
	char *f_buf;

	f_buf = malloc(sizeof(char) * 1024);

	if (f_buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (f_buf);
}
/**
 * f_close - Closes file descriptors.
 *
 * @fd: The file descriptor to be closed.
 *
 * Return: void.
 */
void f_close(int fd)
{
	int c_close;

	c_close = close(fd);

	if (c_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - Copies the contents of a file to another file.
 *
 * @argc: nbr of args.
 * @argv: array of pointers to args.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int from, to, r_read, w_write;
	char *f_buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	f_buf = f_buf_create(argv[2]);
	from = open(argv[1], O_RDONLY);
	r_read = read(from, f_buf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r_read == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(f_buf);
			exit(98);
		}

		w_write = write(to, f_buf, r_read);
		if (to == -1 || w_write == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(f_buf);
			exit(99);
		}

		r_read = read(from, f_buf, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r_read > 0);

	free(f_buf);
	f_close(from);
	f_close(to);

	return (0);
}
