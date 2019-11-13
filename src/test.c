#include <stdio.h>
#include "fileopr.h"

int main()
{
    //create img test
    int status = CreateEPTfile("test.img");
    if (status == -1)
        printf("wrong");
    else
        printf("success");

    //write boot.bin test
    status = InsertBootbin("test.img","boot.bin");
    if (status == -1)
        printf("wrong");
    else
        printf("success");    
    return 0;

    
}