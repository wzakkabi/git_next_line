# git_next_line

## Description
`git_next_line` is a simple implementation of the `get_next_line` function, which reads a line from a file descriptor. This project is designed to provide a clear and concise implementation of `get_next_line`, suitable for learning and educational purposes.

## Features
- Provides a basic implementation of the `get_next_line` function.
- Reads a line from a file descriptor and returns it without the newline character.
- Handles reading from multiple file descriptors simultaneously.
- Supports custom buffer sizes for optimization.

## Getting Started
To use `git_next_line` in your project, follow these steps:

1. Clone the repository to your local machine:
```shell
git clone https://github.com/wzakkabi/git_next_line.git && cd git_next_line
```
3. Compile the source files:
```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o gnl
```
5. Run the executable:
./gnl

## Usage
Here's an example demonstrating the usage of `git_next_line`:

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main() {
 int fd = open("example.txt", O_RDONLY);
 char * line = get_next_line(fd);
 while (line != NULL) {
     printf("%s", line);
     free(line);
     line = get_next_line(fd);
 }
 close(fd);
 return 0;
}
```
## Contact
If you have any questions, suggestions, or issues regarding git_next_line, feel free to contact [wzakkabi@gmail.com] or open an issue on the GitHub repository.

The git_next_line project was created by [walid zakkabi]. Special thanks to [(https://www.1337.ma/en/) and (https://www.42network.org)] for their contributions and support.
