#include <stdio.h>
#include "pf.h"
#include "pftypes.h"
#include <sys/time.h>

#define disk "disk"

#define bufsize 19


struct bufferpage
{
	int bufpage,time,freq,dirty;
}

main()
{
	int error,i,pagenum,*buf,*buf1,fd,maxpagenum;
	char op;
	int pagen;
	char **pagebuf;
	int pagefetch;
	struct timeval tv1,tv2;
	unsigned long long int sec1,sec2;
	if(error=PF_CreateFile(disk)!=PFE_OK)
	{
		PF_PrintError("Could not create the disk\n");
	}
	printf("disk has been created\n");
	
	if(fd=PF_OpenFile(disk)<0)
	{
		PF_PrintError("could not open disk\n");
		exit(1);
	}
	printf("disk has been opened");
	scanf("%d",&maxpagenum);
	
	bufferpage buffer[bufsize];
	//~ int bufpages[bufsize];
	//~ int times[bufsize];
	//~ int freq[bufsize];
	for(i=0;i<maxpagenum;i++)
	{
		if(error=PF_AllocPage(fd,&pagen,&buf)!=PFE_OK)
		{
			PF_PrintError("not able to create pages on disk\n");
			exit(1);
		}
		error=PF_UnfixPage(fd,i,FALSE);
		printf("Allocated Page %d\n",pagen);
	}
	for(i=0;i<bufsize;i++)
	{
		buffer[i].bufpage=-1;
		buffer[i].time=-1;
		buffer[i].freq=-1;
		buffer[i].dirty=0;
		//~ times[i]=-1;
		//~ freq[i]=-1;
		//~ bufpages[i]=-1;
		}
	while(scanf("%d",&pagefetch))
	{
		
		scanf("%c",&op);
		gettimeofday(&tv1;NULL);
		sec1 = (tv1.tv_sec) * 1000000 + (tv1.tv_usec)  ;
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
			if(op=='w')buffer[nextpage].dirty=1;
			gettimeofday(&tv2, NULL);
			sec2 = (tv2.tv_sec) * 1000000 + (tv2.tv_usec) ;
			printf("%lu\n",sec2-sec1);
			continue;
				}
		nextpage=-1;
		printf("miss\n");
			for(i=0;i<bufsize;i++)
			{
				if(bufpages[i]==-1)
				{
				nextpage=i;
					}
				}
		if(nextpage>=0)
		{
			error=PF_GetThisPage(fd,pagefetch,pagebuf);
			bufer[nextpage].bufpage=pagefetch;
			buffer[nextpage].freq=1;
			buffer[nextpage].time=0;
			if(op=='w')
			buffer[nextpage].dirty=1;
			else buffer[nextpage].dirty=0;
			gettimeofday(&tv2, NULL);
			sec2 = (tv2.tv_sec) * 1000000 + (tv2.tv_usec) ;
			printf("%lu\n",sec2-sec1);
			}
		else
		{
			int minfreq=1000000;
			for(i=0;i<bufsize;i++)
			{
				if(buffer[i].freq<minfreq)
				{
					nextpage=i;
					minfreq=buffer[i].freq;
				}
			}
			if(buffer[nextpage].dirty==0)
			error=PF_UnfixPage(fd,bufpages[nextpage],FALSE);
			else error=PF_UnfixPage(fd,bufpages[nextpage],TRUE);
			error=PF_GetThisPage(fd,pagefetch,pagebuf);
			buffer[nextpage].bufpage=pagefetch;
			buffer[nextpage].freq=1;
			buffer[nextpage].time=0;
			if(op=='w')
			buffer[nextpage].dirty=1;
			else buffer[nextpage].dirty=0;
			gettimeofday(&tv2, NULL);
			sec2 = (tv2.tv_sec) * 1000000 + (tv2.tv_usec) ;
			printf("%lu\n",sec2-sec1);
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


	
	
	
