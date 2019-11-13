#include <stdio.h>
#include <stdlib.h>
#include "fileopr.h"
#include "bootsec.h"

int CreateEPTfile(char *szFileName){
    FILE *fp = fopen(szFileName,"wb+");
    if(fp == NULL)
        return -1;
    void *buffer = malloc(FloppySZ);
    fwrite(buffer,FloppySZ,1,fp);
    free(buffer);
    FAT12BS fat12bs;
    init_FAT12_Boot_Sec(&fat12bs);
    write_FAT12_Boot_Sec(fp,&fat12bs);
    fclose(fp);
    return 0;
}
