#include <stdio.h>
#include "fileopr.h"

int main()
{
    int status = CreateEPTfile("test.img");
    if (status == -1)
        printf("wrong");
    else
        printf("success");
    return 0;
}