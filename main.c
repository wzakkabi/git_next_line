#include "get_next_line.h"
#include <stdio.h>

int main() {
 int fd = open("example.txt", O_RDONLY);
 char *line = get_next_line(fd);
 
 while (line != NULL) {
     printf("%s", line);
     free(line);
     line = get_next_line(fd);
 }
 close(fd);
 return 0;
}
