#include "main.h"

char *f_buf_create(char *file);
void f_close(int f_descript);
/**
 * f_buf_create - allocates memory for a character buffer.
 *
 * @file: the name of the file for which the buffer is being created.
 *
 * Return: pointer to the dynamically allocated character buffer.
 */
char *f_buf_create(char *file)
{
	char *f_buf;

	f_buf = malloc(sizeof(char) * 1024);

	if (f_buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n",
			file);
		exit(99);
	}

	return (f_buf);
}
/**
 * f_close - Closes file descriptors.
 *
 * @f_descript: The file descriptor to be closed.
 *
 * Return: void.
 */
void f_close(int f_descript)
{
	int c_close;

	c_close = close(f_descript);

	if (c_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close f_descript %d\n",
			f_descript);
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
	int s_start, e_end, r_read, w_write;
	char *f_buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	f_buf = f_buf_create(argv[2]);
	s_start = open(argv[1], O_RDONLY);
	r_read = read(s_start, f_buf, 1024);
	e_end = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	while (r_read > 0)
	{
		if (s_start == -1 || r_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read s_start file %s\n",
				argv[1]);
			free(f_buf);
			exit(98);
		}

		w_write = write(e_end, f_buf, r_read);
		if (e_end == -1 || w_write == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write e_end %s\n",
				argv[2]);
			free(f_buf);
			exit(99);
		}

		r_read = read(s_start, f_buf, 1024);
		e_end = open(argv[2], O_WRONLY | O_APPEND);

	}

	free(f_buf);
	f_close(s_start);
	f_close(e_end);

	return (0);
}
