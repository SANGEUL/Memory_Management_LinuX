
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>

void * xmalloc (size_t );

int main()
{
    void *q;
    q = xmalloc(10);
    if(q)
        printf("\n succesfull xmalloc()\n");
}

/* like malloc( ), but terminates on failure */
void * xmalloc (size_t size)
{
    void *p;
    p = malloc(size);
    
    if(!p) 
    {
        perror ("xmalloc");
        exit (EXIT_FAILURE);
    }
return p;
}
