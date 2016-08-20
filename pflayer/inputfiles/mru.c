#include <stdio.h>
#include "../pf.h"
#include "../pftypes.h"
#include <sys/time.h>

#define disk "disk"

#define bufsize 19


struct bufferpage
{
	int bufpage,time,freq,dirty;
};

main()
{
	FILE *fp;
	fp = fopen("../inp.txt", "r+");
	int error,i,pagenum,*buf,*buf1,fd,maxpagenum;
	char op[2];
	int pagen;
	char **pagebuf;
	int pagefetch;
	if(error=PF_CreateFile(disk)!=PFE_OK)
	{
		PF_PrintError("Could not create the disk\n");
	}
	
	if(fd=PF_OpenFile(disk)<0)
	{
		PF_PrintError("could not open disk\n");
		exit(1);
	}
	fscanf(fp,"%d",&maxpagenum);
	
	struct bufferpage buffer[bufsize+1];
	for(i=0;i<maxpagenum;i++)
	{
		if(error=PF_AllocPage(fd,&pagen,&buf)!=PFE_OK)
		{
			PF_PrintError("not able to create pages on disk\n");
			exit(1);
		}
		error=PF_UnfixPage(fd,i,FALSE);
	}
	for(i=0;i<bufsize;i++)
	{
		buffer[i].bufpage=-1;
		buffer[i].time=-1;
		buffer[i].freq=-1;
		buffer[i].dirty=0;
		}
	while(fscanf(fp,"%d %s",&pagefetch,op)!=EOF)
	{
		int pageinbuf=0;
		int nextpage=-1;
		for(i=0;i<bufsize;i++)
		{
			if(buffer[i].bufpage==pagefetch)
			{
				pageinbuf=1;nextpage=i;
				}
			}
			if(pageinbuf==1)
			{
			printf("hit\n");
			buffer[nextpage].freq+=1;
			if(op=="w")buffer[nextpage].dirty=1;			
			continue;
				}
		nextpage=-1;
		printf("miss\n");
			for(i=0;i<bufsize;i++)
			{
				if(buffer[i].bufpage==-1)
				{
				nextpage=i;
					}
				}
		if(nextpage>=0)
		{
			error=PF_GetThisPage(fd,pagefetch,pagebuf);
			buffer[nextpage].bufpage=pagefetch;
			buffer[nextpage].freq=1;
			buffer[nextpage].time=0;
			if(op=="w")
			buffer[nextpage].dirty=1;
			else buffer[nextpage].dirty=0;
			}
		else
		{
			int maxtime=1000000;
			for(i=0;i<bufsize;i++)
			{
				if(buffer[i].time<maxtime)
				{
					nextpage=i;
					maxtime=buffer[i].time;
				}
			}
			
			
			if(buffer[nextpage].dirty==0)
			error=PF_UnfixPage(fd,buffer[nextpage].bufpage,FALSE);
			
			else error=PF_UnfixPage(fd,buffer[nextpage].bufpage,TRUE);
			error=PF_GetThisPage(fd,pagefetch,pagebuf);
			buffer[nextpage].bufpage=pagefetch;
			buffer[nextpage].freq=1;
			buffer[nextpage].time=0;
			if(op=="w")
			buffer[nextpage].dirty=1;
			else buffer[nextpage].dirty=0;
		}
		for(i=0;i<bufsize;i++)
		{
			if(buffer[i].time>=0)
			{
				buffer[i].time++;
				}
			}
		}
		
		error=PF_CloseFile(fd);
	
}
