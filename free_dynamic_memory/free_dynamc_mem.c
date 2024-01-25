#include <stdlib.h>
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

void free (void *ptr);
void print_chars (int , char );
int main()
{
    int n =7;
    char c ='*' ;
    printf("\n PRINTING THE PATTERN : \n");
    print_chars(n,c);
    return 0;
}

void print_chars (int n, char c)
{
    int i;
    for(i = 0; i < n; i++)
    {
        char *s;
        int j;
    /*
    * Allocate and zero an i+2 element array
    * of chars. Note that 'sizeof (char)'
    * is always 1.
    */
    s = calloc (i + 2, 1);
        if (!s)
            {
                perror ("calloc");
                break;
            }
    
    for (j = 0; j < i + 1; j++)
    s[j] = c;
    printf ("%s\n", s);
    /* Okay, all done. Hand back the memory. */
    free (s);
}
}
