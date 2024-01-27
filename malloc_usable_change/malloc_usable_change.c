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
#include <malloc.h>

size_t malloc_usable_size (void *ptr);

int main()
{
    size_t len = 21;
    size_t size;
    char *buf;
    
    buf = malloc (len);
    
    if (!buf) 
    {
        perror ("malloc");
        return -1;
    }
    size = malloc_usable_size (buf);
    printf("\n we can actually use 'size : %ld' bytes of 'buf'\n",size);

}

