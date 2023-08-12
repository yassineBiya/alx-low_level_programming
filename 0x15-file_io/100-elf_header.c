#include "main.h"
/************** my functions **************/
void __check_if_elf(unsigned char *e_ident);
void __display_magic(unsigned char *e_ident);
void __display_class(unsigned char *e_ident);
void __display_data(unsigned char *e_ident);
void __display_version(unsigned char *e_ident);
void __display_abi(unsigned char *e_ident);
void __display_osabi(unsigned char *e_ident);
void __display_type(unsigned int e_type, unsigned char *e_ident);
void __display_entry(unsigned long int e_entry, unsigned char *e_ident);
void __close_elff(int elf);
/**
 * __check_if_elf - Checks if a file is ELF.
 *
 * @e_ident: A pointer to an array of u_char.
 *
 * Return: void, exits code 98 if not ELF.
 */
void __check_if_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
		    e_ident[i] != 'E' &&
		    e_ident[i] != 'L' &&
		    e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not ELF\n");
			exit(98);
		}
	}
}
/**
 * __display_magic - display the contents of the magic bytes in ELF header.
 *
 * @e_ident: A pointer to an array of u_char.
 *
 * Return: void, space.
 */
void __display_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * __display_class - display information about the ELF class of the file.
 *
 * @e_ident: A pointer to an array of u_char.
 *
 * Return: void , unknown statement.
 */
void __display_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * __display_data - display information about ELF data encoding of the file.
 *
 * @e_ident: A pointer to an array of u_char.
 *
 * Return: void , unknown statement.
 */
void __display_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * __display_version - display information about the ELF version of the file.
 *
 * @e_ident: A pointer to an array of u_char.
 *
 * Return: void, new line.
 */
void __display_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
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
 * __display_osabi - display information about OS and ABI the ELF file.
 *
 * @e_ident: A pointer to an array of u_char.
 *
 * Return: void, unknown statement.
 */
void __display_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
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
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * __display_abi - display information about the ABI version of an ELF header.
 *
 * @e_ident: A pointer to an array of u_char..
 *
 * Return: void .
 */
void __display_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}
/**
 * __display_type - display the type of an ELF file.
 *
 * @e_type: ELF type.
 * @e_ident: A pointer to an array of u_char..
 *
 * Return: void, unknown statement.
 */
void __display_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
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
 * __display_entry - display information about the entry point of an ELF file.
 *
 * @e_entry: the entry point address of the ELF file.
 * @e_ident: A pointer to an array of u_char.
 *
 * Return: void, entry point address.
 */
void __display_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}
/**
 * __close_elff - closes a file descriptor associated with an ELF file.
 *
 * @elf_d: The file descriptor of the ELF file.
 *
 * Return: exit 98 if cannot be closed.
 */
void __close_elff(int elf_d)
{
	if (close(elf_d) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Cannott close fd %d\n", elf_d);
		exit(98);
	}
}
/**
 * main - Displays the information about the header of an ELF.
 *
 * @argc: nbr of args.
 * @argv: Array of pointers to args.
 *
 * Return: 0 on success or exit 98 on failure.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int elf_d, r_read;

	elf_d = open(argv[1], O_RDONLY);
	if (elf_d == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		__close_elff(elf_d);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r_read = read(elf_d, header, sizeof(Elf64_Ehdr));
	if (r_read == -1)
	{
		free(header);
		__close_elff(elf_d);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	__check_if_elf(header->e_ident);
	printf("ELF Header:\n");
	__display_magic(header->e_ident);
	__display_class(header->e_ident);
	__display_data(header->e_ident);
	__display_version(header->e_ident);
	__display_osabi(header->e_ident);
	__display_abi(header->e_ident);
	__display_type(header->e_type, header->e_ident);
	__display_entry(header->e_entry, header->e_ident);

	free(header);
	__close_elff(elf_d);
	return (0);
}
