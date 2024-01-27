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

int main(int argc, char *argv[])
{
    void *p;
    int fd;
    /* open /dev/zero for reading and writing */
    fd = open (argv[1], O_RDWR);
    
    if(argc < 2)
		 printf("\nONLY ONE ARGUMENT IS PASSED \nENTER THE SECOND ARGUMENT \n");
    else
	    {
    if (fd < 0) 
        {
            perror ("open");
            return -1;
        }

    printf("\n  map [0,page size) of %s \n",argv[1]);

    p = mmap (NULL,getpagesize ( ),PROT_READ | PROT_WRITE,MAP_PRIVATE,fd,0);

    if (p == MAP_FAILED) {
        perror ("mmap");
        if (close (fd))
        perror ("close");
        return -1;
        }

        /* close /dev/zero, no longer needed */
    if (close (fd))
    perror ("close");
    printf("\n 'p' points at one page of memory, use it... \n");
    }

    return 0;
}


