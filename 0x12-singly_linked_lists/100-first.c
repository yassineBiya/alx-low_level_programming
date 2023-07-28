# include "lists.h"
/**
* before_main - prints statement before the main function is executed.
*
* Return: void.
*/
void before_main(void) __attribute__((constructor));
void before_main(void)
{
	printf("You're beat! and yet, you must allow,");
	printf("\nI bore my house upon my back!\n");
}
