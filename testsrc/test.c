#include <stdio.h>

#include "common.h"
#include "fileopr.h"
#include "FATshell.h"
#include "rootdir.h"
#include "FATio.h"

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

   //gets_LR test
   /*char buffer[5];
   int d = gets_LR(buffer,5);
   printf("%s,%d",buffer,d);*/

    //shell test
    start_shell();

    //list test
    /*FILE *fp = fopen("Floppy.img","rb+");
    FAT12DIRENTRY fat12dir[224];
    getDirInfo(fp,fat12dir);*/
    return 0;
}