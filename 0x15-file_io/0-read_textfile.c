#include "main.h"
/**
 * read_textfile- reads a text file and prints it to the POSIX standard output.
 *
 * @filename: file to read.
 * @letters: nbr of etters to read.
 *
 * Return: 0 if flnm is NULL or fctn fails to open or read file.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t f_discript;
	char *c;
	ssize_t r_read;
	ssize_t w_write;

	f_discript = open(filename, O_RDONLY);

	if (f_discript == -1)
		return (0);

	c = malloc(sizeof(char) * letters);
	r_read = read(f_discript, c, letters);
	w_write = write(STDOUT_FILENO, c, r_read);

	free(c);
	close(f_discript);
	return (w_write);
}
