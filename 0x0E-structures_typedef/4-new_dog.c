#include <stdlib.h>
#include "dog.h"
#include "main.h"
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
