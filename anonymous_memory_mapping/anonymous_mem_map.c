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
#include <sys/mman.h>

void * mmap (void *start,size_t length,int prot,int flags,int fd,off_t offset);
int munmap (void *start, size_t length);


int main()
{
    void *p;
    p = mmap (NULL,512 * 1024,PROT_READ | PROT_WRITE,MAP_ANONYMOUS | MAP_PRIVATE,-1,0);

    if (p == MAP_FAILED)
        perror ("mmap");
    else
        printf(" \n 'p' points at 512 KB of anonymous memory... \n");


return 0;
}

