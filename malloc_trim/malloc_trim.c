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

int mallopt (int param, int value);
int malloc_trim (size_t padding);

int main()
{
    int ret;
    /* use mmap( ) for all allocations over 64 KB */
    ret = mallopt (M_MMAP_THRESHOLD, 64 * 1024);
    if (!ret)
    fprintf (stderr, "mallopt failed!\n");
    
    else
        printf("\n use mmap( ) for all allocations over 64 KB \n");
    ret = malloc_trim(32*1024);
    
    if(ret)
        printf("\n shrinks the data segment was successful \n");
}
