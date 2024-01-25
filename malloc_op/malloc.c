
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fs.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>

void * malloc (size_t size);
struct treasure_map{
    int amount;
    char grade;
};

int main()
{
    struct treasure_map *map;
/*
* allocate enough memory to hold a treasure_map stucture
* and point 'map' at it
*/
    map = malloc (sizeof (struct treasure_map));
    if (!map)
    perror ("malloc");
    printf("\n Allocated enough memory to hold a treasure_map stucture \n");
}
