#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file..
 *
 * @filename: the name of the file to append to.
 * @text_content:  a NULL terminated string to append to the file.
 *
 * Return: 1 on success or -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int l = 0;
	int o_open, w_write;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	o_open = open(filename, O_WRONLY | O_APPEND);
	w_write = write(o_open, text_content, l);

	if (o_open == -1 || w_write == -1)
		return (-1);

	close(o_open);

	return (1);
}
