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
void * valloc (size_t size);
void * memalign (size_t boundary, size_t size);

struct ship
    {
        char grade;
        int pac;
    };

int main()
{
    struct ship *pirate, *hms;
    pirate = valloc (sizeof (struct ship));

    if (!pirate) 
    {
        perror ("valloc");
        return -1;
    }

    hms = memalign (getpagesize ( ), sizeof (struct ship));
    if(!hms)
    {
        perror ("memalign");
        free (pirate);
        return -1;
    }
    /* use 'pirate' and 'hms'... */
    printf("\n SUCCESFUL USE OF PIRATE AND HMS \n");
    printf("\n NOW FREEING THE PIRATE AND HMS \n");
    free(hms);
    free(pirate);

}
