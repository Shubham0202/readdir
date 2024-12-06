#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
const char* getEx(const char* filename)
{
    const char* dot = strrchr(filename,'.');
    return dot;
}
int main()
{
    struct dirent *entry;
    struct stat file_stat;
    DIR* dir = opendir(".");
    int fCount=0;
    if(dir==NULL)
    printf("Dir Not Opend");

    while((entry = readdir(dir)) !=NULL)
    {
        if(entry->d_type ==DT_DIR) continue;

        stat(entry->d_name,&file_stat);
        printf("%s\t%ld\t%s\n",entry->d_name,file_stat.st_size,getEx(entry->d_name));
        fCount++;
    }
    printf("File Count=%d",fCount);
}
