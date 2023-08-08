#include "main.h"

void check_if_elf(unsigned char *_identifier);


/**
 * check_if_elf - Checks if the file is an ELF.
 *
 * @_identifier: A pointer to an array of 4 first bytes.
 *
 * Return: void.
 */
void check_if_elf(unsigned char *_identifier)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (_identifier[index] != 127 &&
		    _identifier[index] != 'E' &&
		    _identifier[index] != 'L' &&
		    _identifier[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
* main - Displays ELF information.
*
* @argc: nbr of args.
* @argv: array of pointers to args.
*
* Return: 0 on success.
*
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	
}
