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

void * realloc(void *ptr, size_t size);

struct map
    {
        int rate;
        char grade;
    };

int main()
{
    struct map *p;
    /* allocate memory for two map structures */
    p =  calloc (2, sizeof (struct map));
    if (!p) 
    {
        perror ("calloc");
        return -1;
    }
    
    struct map *r;
    /* we now need memory for only one map */
    r = realloc(p, sizeof (struct map));
    if (!r) 
    {
        /* note that 'p' is still valid! */
        perror ("realloc");
        return -1;
    }
    else
        printf("\n Allocated the memory to struct map \n");
}
