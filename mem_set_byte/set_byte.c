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

void * memset (void *s, int c, size_t n);

int main()
{
    void *s;
    void *temp;
    
    /* zero out [s,s+256) */
    
    temp = memset (s, '\0', 256);
    if(temp)
        printf("\n SUCCESSFULLY SET  THE MEM \n");

}
