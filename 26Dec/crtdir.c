#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<stdio.h>
int main()
{
        struct stat st = {0};
        struct dirent *pDirent;
        if(stat("/home/student/Desktop/3547/26Dec/crdir",&st) == -1)
        {
	        mkdir("/home/student/Desktop/3547/26Dec/crdir",0700);
	        
        } 
        DIR *pdir;
        FILE *fp;
        pdir = opendir("/home/student/Desktop/3547/26Dec/crdir");
        fp = fopen("/home/student/Desktop/3547/26Dec/crdir/cr_fl1.txt","w");
        while((pDirent = readdir(pdir)) != NULL)
        {
                printf("[%s]\n",pDirent->d_name);
        }
        fp = popen("find /home/student/Desktop/3547/26Dec/crdir/cr_fl2.txt","w");
        pclose(fp);
        closedir(pdir);     
        return 0;
}
