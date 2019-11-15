#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "rootdir.h"

int getDirInfo(FILE *fp,PFAT12DIRENTRY fat12dir)
{
    fseek(fp,(long)(19*512),SEEK_SET);
    for (int i = 0; i < 224; i++)
    {
        fread(&fat12dir[i],32,1,fp);
    }    
    return 0;
}

int lsDirInfo(PFAT12DIRENTRY fat12dir)
{
    int item = 0;
    while (1)
    {
        //end of dir
        void *tmpSpace = malloc(32);
        memset(tmpSpace,0,32);
        if(!memcmp(tmpSpace,&fat12dir[item],32))
            break;
        free(tmpSpace);
        tmpSpace = NULL;
        //file type
        if(fat12dir[item].DIR_Name[0]<0)
        {
            item++;
            continue;
        }
        else if(fat12dir[item].DIR_Attr == FILETYPE_BIN || fat12dir[item].DIR_Attr == FILETYPE_TEXT)
        {
            //file date
            UINT yearoffset,month,day;
            yearoffset = fat12dir[item].DIR_WrtDate>>9;
            month = (fat12dir[item].DIR_WrtDate & 0x1E0)>>5;
            day = fat12dir[item].DIR_WrtDate & 0x1F;
            printf("%04d-%02d-%02d    ",yearoffset+1980,month,day);

            //file time
            UINT hour,minute,second;
            hour = fat12dir[item].DIR_WrtTime>>11;
            minute = (fat12dir[item].DIR_WrtTime & 0x7E0) >>5;
            second = 2*(fat12dir[item].DIR_WrtTime & 0x1F);
            printf("%02d:%02d:%02d    ",hour,minute,second);

            //file size
            printf("%d BYTE      ",fat12dir[item].DIR_FileSize);

            //file name
            for (int i = 0; i < 8; i++)
            {
                char s = fat12dir[item].DIR_Name[i];
                if(s != 0x20)
                    printf("%c",fat12dir[item].DIR_Name[i]);
            }
            printf(".");
            //extend name
            for (int i = 8; i < 11; i++)
            {
                char s = fat12dir[item].DIR_Name[i];
                if(s != 0x20)
                    printf("%c",fat12dir[item].DIR_Name[i]);
            }


            printf("\n");
        }
        else if(fat12dir[item].DIR_Attr == FILETYPE_DIR)
        {
                        //file date
            UINT yearoffset,month,day;
            yearoffset = fat12dir[item].DIR_WrtDate>>9;
            month = (fat12dir[item].DIR_WrtDate & 0x1E0)>>5;
            day = fat12dir[item].DIR_WrtDate & 0x1F;
            printf("%04d-%02d-%02d    ",yearoffset+1980,month,day);

            //file time
            UINT hour,minute,second;
            hour = fat12dir[item].DIR_WrtTime>>11;
            minute = (fat12dir[item].DIR_WrtTime & 0x7E0) >>5;
            second = 2*(fat12dir[item].DIR_WrtTime & 0x1F);
            printf("%02d:%02d:%02d    ",hour,minute,second);

            //file size
            printf("%d BYTE      ",fat12dir[item].DIR_FileSize);

            
            printf("<DIR>    ");
            for (int i = 0; i < 8; i++)
            {
                char s = fat12dir[item].DIR_Name[i];
                if(s != 0x20)
                    printf("%c",fat12dir[item].DIR_Name[i]);
            }
            printf("\n");
        }
        else
        {
            item++;
            continue;
        }
        item++;
    }
    printf("\n");
    return 1;
}