#include <stdio.h>
#include <string.h>

#include "common.h"
#include "FATio.h"

int gets_LR(char *buffer,int size)
{
    int scanf_count,i;
    fgets(buffer,size,stdin);
    for (i = 0; i < size; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';
            break;
        }
    }
    scanf_count = strlen(buffer);
    return scanf_count;
}

void print_Hello()
{
    printf("_________________________________\n");
    printf("         [FAT12 shell]           \n");
    printf("please choose:                   \n");
    printf("1.create a empty FAT12 floppy.   \n");
    printf("2.write in boot.bin(512byte).    \n");
    printf("3.FAT12 manage shell.            \n");
    printf("0.exit.                          \n");
    printf("_________________________________\n");
}

void print_helper()
{
    printf("[help]             show help info.\n");
    printf("[info]             show floppy information.\n");
    printf("[ls]               list the file.\n");
    printf("[rm]               delete file.\n");
    printf("[write]            write in file.\n");
    printf("[quit]             exit shell.\n\n");
    return;
}