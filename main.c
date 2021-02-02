#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
    if(argc<3)
    {
        return 1;
    }
    FILE *SrcFilePtr=fopen(argv[1],"rb");
    if(SrcFilePtr==NULL)
    {
        return 2;
    }
    FILE *DisFilePtr=fopen(argv[2],"wb");
    if(DisFilePtr==NULL)
    {
        return 3;
    }
    char buff[1];
    while(fread(buff,sizeof(char),1,SrcFilePtr)>0)
    {
        fwrite(buff,sizeof(char),1,DisFilePtr);
    }
    fclose(SrcFilePtr);
    fclose(DisFilePtr);

    return 0;
}
