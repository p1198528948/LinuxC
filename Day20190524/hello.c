#include <stdio.h>
#define VERSION 3

#if(VERSION < 2)
    #error "version is too low"
#elif(VERSION == 2)
    #warning "version good"
#else
    #warning "version is too high"
#endif

int main()
{
    printf("Hello C.\n");
    return 0;
}
