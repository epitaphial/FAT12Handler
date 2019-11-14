#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <string.h>

#include "FATshell.h"
#include "fileopr.h"
#include "FATio.h"
#include "bootsec.h"
#include "FATmanage.h"

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
            char bufBoot[100],bufLoader[100];
            printf("Please input the path of the floppy:\n");
            int bufNameLen = gets_LR(bufBoot,100);
            printf("Please input the name of the booter:[boot.bin]\n");
            int loadNameLen = gets_LR(bufLoader,100);
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
            int nameLen;
            char floppyName[100];
            printf("Please input the floppy path:\n");
            nameLen = gets_LR(floppyName,100);
            if (nameLen>0)
            {
                manage_shell(floppyName);
                break;
            }
            else
            {
                printf("Floppy name cant be empty!\n");
                break;
            }
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

void manage_shell(char *floppy_name)
{
    if(access(floppy_name,0) == -1)
    {
        printf("File not exists!\n");
        return;
    }
    else
    {
        FILE *fp = fopen(floppy_name,"rb+");
	    fseek(fp, 0, SEEK_END);
	    int nFileLen = ftell(fp);
        if(nFileLen != FLOPPYBYTE)
        {
            printf("Not a valid floppy!\n");
            return;
        }
        while (1)
        {
            printf("(%s)",floppy_name);
            char Commandbuf[30];
            int Commandlen;
            Commandlen = gets_LR(Commandbuf,30);
            fflush(stdin);
            if(Commandlen == 0)
                continue;
            else if(!strncmp(Commandbuf,"help",Commandlen))
            {
                command_help();
            }
            else if(!strncmp(Commandbuf,"quit",Commandlen))
            {
                printf("Bye!\n");
                fclose(fp);
                exit(-1);
            }
            else if (!strncmp(Commandbuf,"info",Commandlen))
            {
                command_info(fp);
            }
            else if (!strncmp(Commandbuf,"ls",Commandlen))
            {
                command_ls(fp);
            }
        }
        fclose(fp);
    }
}


/*command*/

void command_info(FILE *fp)
{
    fseek(fp,0,SEEK_SET);
    FAT12BS fat12bs;
    fread(&fat12bs,sizeof(FAT12BS),1,fp);

    //OEMName
    printf("OEMName:");
    for (int i = 0; i < 8; i++)
    {
        printf("%c",fat12bs.BS_OEMName[i]);
    }
    printf("\n");
    
    //Byte per section
    printf("BytesPerSec:%d\n",fat12bs.BPB_BytesPerSec);
    //Section Per Clus
    printf("SecPerClus:%d\n",fat12bs.BPB_SecPerClus);
    //num of FAT table
    printf("NumFATs:%d\n",fat12bs.BPB_NumFATs);
    //size of rootdir
    printf("RootEntCnt:%d\n",fat12bs.BPB_RootEntCnt);
    //FileSysType
    printf("FileSysType:");
    for (int i = 0; i < 8; i++)
    {
        printf("%c",fat12bs.BS_FileSysType[i]);
    }
    printf("\n\n");
}

void command_ls(FILE *fp)
{
    FAT12TABLE fat12table;
    ReadFATtable(fp,&fat12table);
    return;
}


void command_help()
{
    print_helper();
    return;
}
