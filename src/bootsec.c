#include <string.h>
#include <stdio.h>

#include "bootsec.h"


void init_FAT12_Boot_Sec(PFAT12BS pfat12bs)
{
    memset(pfat12bs,0,sizeof(FAT12BS));

    //filled with nop(0x90)
    for (int i = 0; i < 3; i++)
        pfat12bs->BS_jmpBoot[i] = 0x90;

    //OEMNAME
    char tmp_oem[8] = {'C','u','r','l','e','d',' ',' '};
    strncpy(pfat12bs->BS_OEMName,tmp_oem,8);

    pfat12bs->BPB_BytesPerSec = 512;
    pfat12bs->BPB_SecPerClus = 1;
    pfat12bs->BPB_RsvdSecCnt = 1;
    pfat12bs->BPB_NumFATs = 2;
    pfat12bs->BPB_RootEntCnt = 0xE0;
    pfat12bs->BPB_TotSec16 = 0xB40;
    pfat12bs->BPB_Media = 0xF0;
    pfat12bs->BPB_FATSz16 = 0x9;
    pfat12bs->BPB_SecPerTrk = 0x12;
    pfat12bs->BPB_NumHeads = 2;
    pfat12bs->BPB_HiddSec = 0;
    pfat12bs->BPB_TotSec32 = 0;
    pfat12bs->BS_DrvNum = 0;
    pfat12bs->BS_Reserved1 = 0;
    pfat12bs->BS_BootSig = 0x29;
    pfat12bs->BS_VolID = 0;

    //vollab
    char tmp_vol[11] = {'D','r','i','v','e','A',' ',' ',' ',' ',' '};
    strncpy(pfat12bs->BS_VolLab,tmp_vol,11);

    //type
    char tmp_type[8] = {'F','A','T','1','2',' ',' ',' '};
    strncpy(pfat12bs->BS_FileSysType,tmp_type,8);

    pfat12bs->EndSig = 0xAA55;
}

void write_FAT12_Boot_Sec(FILE *fp,PFAT12BS pfat12bs)
{
    rewind(fp);
    fwrite(pfat12bs,sizeof(FAT12BS),1,fp);
}