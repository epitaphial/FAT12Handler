#include <stdlib.h>
#include "FATshell.h"
#include "fileopr.h"
#include "FATio.h"

void start_shell()
{
    print_Hello();
    while (1)
    {
        printf(">>>");
        char getKey = getchar();
        switch (getKey)
        {
        case '0':
        {
            fflush(stdin);
            exit(-1);
            break;
        }
        case '1':
        {
            fflush(stdin);
            printf("Please input the name of the floppy:[a.img]\n");
            char buf[10];
            int fileNameLen = gets_LR(buf,10);
            int status;
            if(fileNameLen == 0)
                status = CreateEPTfile("a.img");
            else
            {
                status = CreateEPTfile(buf);
            }
            if (status == -1)
            {
                printf("Fail to create.\n");
                break;
            }
            else
            {    
                printf("Success to create.\n");          
                break;
            }
        }
        case '2':
        {
            fflush(stdin);
            char bufBoot[10],bufLoader[10];
            printf("Please input the name of the floppy:\n");
            int bufNameLen = gets_LR(bufBoot,10);
            printf("Please input the name of the booter:[boot.bin]\n");
            int loadNameLen = gets_LR(bufLoader,10);
            int status;
            if(bufNameLen != 0 && loadNameLen != 0)
                status = InsertBootbin(bufBoot,bufLoader);
            else if(bufNameLen == 0)
            {
                printf("Floppy name cant be empty!\n");
                break;
            }
            else
            {
                status = InsertBootbin(bufBoot,"boot.bin");
            }
            if (status == -1)
            {
                printf("Fail to insert.\n");
                break;
            }
            else
            {    
                printf("Success to insert.\n");          
                break;
            }
        }
        case '3':
        {
            fflush(stdin);
            break;
        }
        default:
        {
            fflush(stdin);
            printf("Invalid Input!\n");
            break;
        }
    }
    }
}