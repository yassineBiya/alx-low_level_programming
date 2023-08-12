#include "main.h"
/************** my functions **************/
void __check_if_elf(unsigned char *elf_head);
void __display_magic(unsigned char *elf_head);
void __display_class(unsigned char *elf_head);
void __display_data(unsigned char *elf_head);
void __display_version(unsigned char *elf_head);
void __display_abi(unsigned char *elf_head);
void __display_osabi(unsigned char *elf_head);
void __display_type(unsigned int e_type, unsigned char *elf_head);
void __display_entry(unsigned long int e_entry, unsigned char *elf_head);
void __close_elff(int elf);
/**
 * __check_if_elf - Checks if a file is ELF.
 *
 * @elf_head: A pointer to an array of u_char.
 *
 * Return: exit 98 if not ELF.
 */
void __check_if_elf(unsigned char *elf_head)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (elf_head[i] != 127 &&
		    elf_head[i] != 'E' &&
		    elf_head[i] != 'L' &&
		    elf_head[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not ELF\n");
			exit(98);
		}
	}
}
/**
 * __display_magic - Prints the magic numbers of an ELF header.
 * @elf_head: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void __display_magic(unsigned char *elf_head)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", elf_head[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * __display_class - Prints the class of an ELF header.
 * @elf_head: A pointer to an array containing the ELF class.
 */
void __display_class(unsigned char *elf_head)
{
	printf("  Class:                             ");

	switch (elf_head[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_head[EI_CLASS]);
	}
}

/**
 * __display_data - Prints the data of an ELF header.
 * @elf_head: A pointer to an array containing the ELF class.
 */
void __display_data(unsigned char *elf_head)
{
	printf("  Data:                              ");

	switch (elf_head[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_head[EI_CLASS]);
	}
}

/**
 * __display_version - Prints the version of an ELF header.
 * @elf_head: A pointer to an array containing the ELF version.
 */
void __display_version(unsigned char *elf_head)
{
	printf("  Version:                           %d",
	       elf_head[EI_VERSION]);

	switch (elf_head[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * __display_osabi - Prints the OS/ABI of an ELF header.
 * @elf_head: A pointer to an array containing the ELF version.
 */
void __display_osabi(unsigned char *elf_head)
{
	printf("  OS/ABI:                            ");

	switch (elf_head[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_head[EI_OSABI]);
	}
}

/**
 * __display_abi - Prints the ABI version of an ELF header.
 * @elf_head: A pointer to an array containing the ELF ABI version.
 */
void __display_abi(unsigned char *elf_head)
{
	printf("  ABI Version:                       %d\n",
	       elf_head[EI_ABIVERSION]);
}

/**
 * __display_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @elf_head: A pointer to an array containing the ELF class.
 */
void __display_type(unsigned int e_type, unsigned char *elf_head)
{
	if (elf_head[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * __display_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @elf_head: A pointer to an array containing the ELF class.
 */
void __display_entry(unsigned long int e_entry, unsigned char *elf_head)
{
	printf("  Entry point address:               ");

	if (elf_head[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (elf_head[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * __close_elff - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void __close_elff(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

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
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		__close_elff(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		__close_elff(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	__check_if_elf(header->elf_head);
	printf("ELF Header:\n");
	__display_magic(header->elf_head);
	__display_class(header->elf_head);
	__display_data(header->elf_head);
	__display_version(header->elf_head);
	__display_osabi(header->elf_head);
	__display_abi(header->elf_head);
	__display_type(header->e_type, header->elf_head);
	__display_entry(header->e_entry, header->elf_head);

	free(header);
	__close_elff(o);
	return (0);
}
