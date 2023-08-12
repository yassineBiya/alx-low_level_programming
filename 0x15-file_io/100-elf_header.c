#include "main.h"
/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	Elf32_Ehdr ehdr;

	/* Check for the correct number of arguments.*/
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
		return (98);
	}

	/*Open the ELF file.*/
	fp = fopen(argv[1], "rb");

	if (fp == NULL)
	{
		fprintf(stderr, "Could not open file: %s\n", argv[1]);
		return (98);
	}

	/* Read the ELF header.*/
	fread(&ehdr, sizeof(ehdr), 1, fp);

	/* Print the ELF header information.*/
	printf("Magic: %#x\n", ehdr.e_ident[EI_MAG0]);
	printf("Class: %#x\n", ehdr.e_ident[EI_CLASS]);
	printf("Data: %#x\n", ehdr.e_ident[EI_DATA]);
	printf("Version: %#x\n", ehdr.e_ident[EI_VERSION]);
	printf("OS/ABI: %#x\n", ehdr.e_ident[EI_OSABI]);
	printf("ABI Version: %#x\n", ehdr.e_ident[EI_ABIVERSION]);
	printf("Type: %#x\n", ehdr.e_type);
	printf("Machine: %#x\n", ehdr.e_machine);
	printf("Entry point: %#x\n", ehdr.e_entry);

	/* Close the file.*/
	fclose(fp);

	return (0);
}
