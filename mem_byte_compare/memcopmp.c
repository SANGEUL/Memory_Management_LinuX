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

int memcmp(const void *s1, const void *s2, size_t n);

struct dinghy
{
    int nr_ors;
    char grade;
};

int compare_dinghies(struct dinghy *, struct dinghy *);

int main()
{
    struct dinghy *temp1, *temp2;
    int ret;
    int size = sizeof(struct dinghy);
    
    /* zero out [s,s+256) */
    temp1 = malloc(sizeof(struct dinghy));
    temp2 = malloc(sizeof(struct dinghy));

    ret = compare_dinghies(temp1,temp2);

    if(ret == 0)
        printf("\n SAME SIZE OF MEMORY IS ALLOCATED \n");
    else if(ret<0)
        printf("\n temp2 is greater \n");
    else
        printf("\n temp1 is greater \n");

}

int compare_dinghies(struct dinghy *a, struct dinghy *b)
{
    int ret;
    ret = memcmp(a, b, sizeof (struct dinghy));
    return ret;
}








