#include <stdio.h>
#include "fileopr.h"
#include "FATshell.h"

int main()
{
    /*
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
    */

    //shell test
    start_shell();
    return 0;
}