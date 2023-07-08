#!/bin/sh

# Get the list of all .c files in the current directory
files=$(find . -name "*.c")

# Create the static library
ar cr liball.a $files

# Print a message to indicate that the library was created successfully
echo "Static library liball.a created successfully"
