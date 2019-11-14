#ifndef BOOTSEC_H
#define BOOTSEC_H

#define FLOPPYBYTE 2*80*18*512

#include <stdio.h>

#pragma pack(push)
#pragma pack (1)

//Part for FAT12

typedef struct FAT12BootSec
{
    char BS_jmpBoot[3];//jmp start;nop;
    char BS_OEMName[8]; //exp:Curled.
    short BPB_BytesPerSec; //commonly 512
    char BPB_SecPerClus; //commonly 1
    short BPB_RsvdSecCnt;//for boot,1
    char BPB_NumFATs;//num of FAT table,2
    short BPB_RootEntCnt;//size of rootdir,commonly 0xE0 
    short BPB_TotSec16;//2*80*18=2880,0xB40
    char BPB_Media;//0XF0
    short BPB_FATSz16;//0x9
    short BPB_SecPerTrk;//0x12
    short BPB_NumHeads;//2
    int BPB_HiddSec;//0
    int BPB_TotSec32;//0
    char BS_DrvNum;//0
    char BS_Reserved1;//0
    char BS_BootSig;//0x29
    int BS_VolID;//0
    char BS_VolLab[11];//Volume title,exp:"DRIVEA"
    char BS_FileSysType[8];//"FAT12"
    char BS_BootCode[448];
    short EndSig;//0XAA55
}FAT12BS,*PFAT12BS;

#pragma pack(pop)

//commonly init the boot section
void init_FAT12_Boot_Sec(PFAT12BS pfat12bs);

//write the boot sec to file
void write_FAT12_Boot_Sec(FILE *fp,PFAT12BS pfat12bs);



#endif