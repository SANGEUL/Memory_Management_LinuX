
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
void * xcalloc0 (size_t);

int main()
{
    void *q;
    q = xcalloc0(10);

    if(q)
        printf("\n Successfull xcalloc() \n");
}

/* like malloc( ), but zeros memory and terminates on failure */
void * xcalloc0 (size_t size)
{
    void *p;
    p = calloc(1, size);
    if(!p)
    {
        perror ("xmalloc0");
        exit (EXIT_FAILURE);
    }
    return p;
}
