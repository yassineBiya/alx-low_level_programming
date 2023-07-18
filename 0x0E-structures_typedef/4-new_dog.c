#include <stdlib.h>
#include "dog.h"
#include "main.h"
#include "main.h"
/**
 * _strlen - returns the length of a string.
 *
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
		int leng = 0;

		while (*s != '\0')
		{
			leng++;
			s++;
		}

		return (leng);
}
#include "main.h"
/**
 * char *_strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 *
 * @dest: cp destination.
 * @src: cp source.
 *
 * Return: string.
 */
char *_strcpy(char *dest, char *src)
{
		int l = 0;
		int m = 0;

		while (*(src + l) != '\0')
		{
			l++;
		}
		for ( ; m < l ; m++)
		{
			dest[m] = src[m];
		}
		dest[l] = '\0';
		return (dest);
}
/**
 * new_dog - creates a new dog.
 *
 * @name: name of the dog.
 * @age: age of the dog.
 * @owner: owner of the dog.
 *
 * Return: pointer to the new dog (Success), NULL otherwise.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *doggy;
	int leng1, leng2;

	leng1 = _strlen(name);
	leng2 = _strlen(owner);

	doggy = malloc(sizeof(dog_t));
	if (doggy == NULL)
		return (NULL);

	doggy->name = malloc(sizeof(char) * (leng1 + 1));
	if (doggy->name == NULL)
	{
		free(doggy);
		return (NULL);
	}
	doggy->owner = malloc(sizeof(char) * (leng2 + 1));
	if (doggy->owner == NULL)
	{
		free(doggy);
		free(doggy->name);
		return (NULL);
	}
	_strcpy(doggy->name, name);
	_strcpy(doggy->owner, owner);
	doggy->age = age;

	return (doggy);
}
