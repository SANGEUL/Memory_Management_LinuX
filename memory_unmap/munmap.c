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
    int ret;
    void *p;
    /* all done with 'p', so give back the 512 KB mapping */
    ret = munmap(p, 512 * 1024);
    if(ret)
        perror("munmap");
    printf("\n  all done with 'p', so give back the 512 KB mapping \n");
return 0;
}

