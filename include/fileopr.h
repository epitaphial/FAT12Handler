#ifndef FILEOPR_H
#define FILEOPR_H 

#define FloppySZ 1474560

int CreateEPTfile(char *szFileName);
int InsertBootbin(char *szFileName,char *bootFileName);

#endif