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

void * calloc (size_t nr, size_t size);

int main()
{
    int *x, *y;
    x = malloc (50 * sizeof (int));
    if (!x) 
        {
            perror ("malloc");
            return -1;
        }
    printf("\n malloc() is succesful \n");
    
    y = calloc (50, sizeof (int));
    if (!y)
    {
        perror ("calloc");
        return -1;
    }
    printf("\n calloc() is succesful \n");
}
