#ifndef BOOTSEC_H
#define BOOTSEC_H

#pragma pack(push)
#pragma pack (1)

//Part for FAT12

typedef struct FAT12BootSec
{
    UCHAR BS_jmpBoot[3];//jmp start;nop;
    char BS_OEMName[8]; //exp:Curled.
    USHORT BPB_BytesPerSec; //commonly 512
    UCHAR BPB_SecPerClus; //commonly 1
    USHORT BPB_RsvdSecCnt;//for boot,1
    UCHAR BPB_NumFATs;//num of FAT table,2
    USHORT BPB_RootEntCnt;//size of rootdir,commonly 0xE0 
    USHORT BPB_TotSec16;//2*80*18=2880,0xB40
    UCHAR BPB_Media;//0XF0
    USHORT BPB_FATSz16;//0x9
    USHORT BPB_SecPerTrk;//0x12
    USHORT BPB_NumHeads;//2
    UINT BPB_HiddSec;//0
    UINT BPB_TotSec32;//0
    UCHAR BS_DrvNum;//0
    UCHAR BS_Reserved1;//0
    UCHAR BS_BootSig;//0x29
    UINT BS_VolID;//0
    char BS_VolLab[11];//Volume title,exp:"DRIVEA"
    char BS_FileSysType[8];//"FAT12"
    UCHAR BS_BootCode[448];
    USHORT EndSig;//0XAA55
}FAT12BS,*PFAT12BS;

#pragma pack(pop)

//commonly init the boot section
void init_FAT12_Boot_Sec(PFAT12BS pfat12bs);

//write the boot sec to file
void write_FAT12_Boot_Sec(FILE *fp,PFAT12BS pfat12bs);



#endif