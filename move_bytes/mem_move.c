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

void * memmove (void *dst, const void *src, size_t n);

int main()
{
   char dest[] = "communicate";
   char src[]  = "Applications";
   void *s;

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   s = memmove(dest, src, 9);

   if(!s)
   {
       printf("\n NO SUCCESSFUL MOVE \n");
   }
  
    printf("After memmove dest = %s, src = %s\n", dest, src);
    return 0;
}
