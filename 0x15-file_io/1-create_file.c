#include "main.h"
/**
 * create_file - creates a file.
 *
 * @filename: the name of the file to create.
 * @text_content: a NULL terminated string to write to the file.
 *
 * Return: 1 on success or -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int l = 0, f_discript, w_write;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	f_discript = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w_write = write(f_discript, text_content, l);

	if (f_discript == -1 || w_write == -1)
		return (-1);

	close(f_discript);

	return (1);
}
