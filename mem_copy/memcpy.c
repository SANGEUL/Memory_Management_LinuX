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
#define _GNU_SOURCE

void * mempcpy (void *dst, const void *src, size_t n);

int main()
{
   const char src[50] = "function behaves";
   char dest[50];

   strcpy(dest,"the same!!");
   printf("Before memcpy dest = %s\n", dest);
   
   memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);

   return 0;
}

