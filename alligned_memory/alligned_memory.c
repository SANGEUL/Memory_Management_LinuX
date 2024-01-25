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

#define _XOPEN_SOURCE 600
#define _GNU_SOURCE

int posix_memalign(void **memptr, size_t alignment,size_t size);

int main()
{
    void *buf;
    int ret;
    
    /* allocate 1 KB along a 256-byte boundary */
    ret = posix_memalign(&buf, 256, 1024);
    if (ret) 
    {
        fprintf (stderr, "posix_memalign: %s\n",strerror (ret));
        return -1;
    }
    /* use 'buf'... */
    printf("\n FREEING  THE  BUFFER \n");
    free(buf);

}
