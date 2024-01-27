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

int mlock(const void *addr, size_t len);

#define DATA_SIZE 2048
double buffer[DATA_SIZE];

int main()
{
    int ret;
    ret = mlock(buffer, DATA_SIZE * sizeof(double));
    if( ret == -1)
        perror("mlock");

    printf("Pin the pages successfully\n");
    /*
     * Start real-time work here
     */
    ret = munlock(buffer, DATA_SIZE * sizeof(double));
    if( ret == -1 )
        perror("munlock");
    printf("Unpin the pages successfully\n");

    return 0;
}

