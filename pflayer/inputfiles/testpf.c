/* testpf.c */
#include <stdio.h>
#include "pf.h"
#include "pftypes.h"

#define FILE1	"file1"
#define FILE2	"file2"

#define Disk "disk"
#define bufsize 19


main()
{
	
	//~ 
	int error,i,pagenum,*buf,*buf1,fd,maxpagenum;
	int pagen;int ml=13;
	char **pagebuf;
	int curbufsize=0;
	int pagefetch;
	if ((error=PF_CreateFile(Disk))!= PFE_OK){
		PF_PrintError("disk");
		exit(1);
	 }
	printf("disk created\n");
	
	
	if ((fd=PF_OpenFile(Disk))<0){
		PF_PrintError("open disk\n");
		exit(1);
	}
	printf("opened disk\n");
	scanf("%d",&maxpagenum);
	
	
	int bufpages[bufsize];
	int times[bufsize];
	int freq[bufsize];
	//writefile(Disk);
	//readfile(Disk);
	//~ 
	for(i=0;i<maxpagenum;i++)
	{
		if ((error=PF_AllocPage(fd,&pagen,&buf))!= PFE_OK){
			PF_PrintError("first buffer\n");
			exit(1);
		}
		*((int *)buf) = i;
		error=PF_UnfixPage(fd,i,TRUE);
		
		//printf("allocated page %d\n",pagenum);
		printf("Allocated Page %d\n",pagen);
	}
	int strt=0;
	for(i=10;i<maxpagenum-1;i++){printf("%d\n",i);error=PF_GetThisPage(fd,i,pagebuf);if(error!=PFE_OK)printf("notok\n");}
	error=PF_UnfixPage(fd,12,FALSE);
	
	if(error==PFE_OK)printf("maybeunfixed\n");
	error=PF_GetThisPage(fd,22,pagebuf);
	if(error==PFE_OK)printf("cantgetit\n");
	//~ if ((error=PF_DisposePage(fd,13))!= PFE_OK){
				//~ PF_PrintError("dispose\n");
				//~ exit(1);
			//~ }
	//~ if ((error=PF_CloseFile(fd))!= PFE_OK){
		//~ PF_PrintError("close file1\n");
		//~ exit(1);
	//~ }
	 
	readfile(Disk);
	
	//~ if ((fd=PF_OpenFile(Disk))<0){
		//~ PF_PrintError("open disk\n");
		//~ exit(1);
	//~ }
	//~ printf("opened disk\n");
	//~ if ((error=PF_GetThisPage(fd,12,pagebuf))!= PFE_OK){
			//~ PF_PrintError("first buffer\n");
			//~ exit(1);
		//~ }
		//~ //error=PF_UnfixPage(fd,ml,TRUE);
		//~ readfile(Disk);
	//~ 
	//~ 
	//~ int error,i,pagenum,*buf,*buf1,fd,maxpagenum;
//~ 
//~ 
//~ 
//~ int *buf2;
//~ int fd1,fd2;



	/* create a few files */
	//~ if ((error=PF_CreateFile(FILE1))!= PFE_OK){
		//~ PF_PrintError("file1");
		//~ exit(1);
	//~ }
	//~ printf("file1 created\n");
//~ 
	//~ if ((error=PF_CreateFile(FILE2))!= PFE_OK){
		//~ PF_PrintError("file2");
		//~ exit(1);
	//~ }
	//~ printf("file2 created\n");
//~ 
	//~ /* write to file1 */
	//~ writefile(FILE1);
//~ 
	//~ /* print it out */
	//~ readfile(FILE1);
//~ 
	//~ /* write to file2 */
	//~ writefile(FILE2);
//~ 
	//~ /* print it out */
	//~ readfile(FILE2);
	//~ PF_PrintError("ohyes\n");
//~ 
	//~ /* open both files */
	//~ if ((fd1=PF_OpenFile(FILE1))<0){
		//~ PF_PrintError("open file1\n");
		//~ exit(1);
	//~ }
	//~ printf("opened file1\n");
//~ 
	//~ if ((fd2=PF_OpenFile(FILE2))<0 ){
		//~ PF_PrintError("open file2\n");
		//~ exit(1);
	//~ }
	//~ printf("opened file2\n");
//~ 
	//~ /* get rid of records  1, 3, 5, etc from file 1,
	//~ and 0,2,4,6 from file2 */
	//~ for (i=0; i < PF_MAX_BUFS; i++){
		//~ if (i & 1){
			//~ if ((error=PF_DisposePage(fd1,i))!= PFE_OK){
				//~ PF_PrintError("dispose\n");
				//~ exit(1);
			//~ }
			//~ printf("disposed %d of file1\n",i);
		//~ }
		//~ else {
			//~ if ((error=PF_DisposePage(fd2,i))!= PFE_OK){
				//~ PF_PrintError("dispose\n");
				//~ exit(1);
			//~ }
			//~ printf("disposed %d of file2\n",i);
		//~ }
	//~ }
//~ 
	//~ if ((error=PF_CloseFile(fd1))!= PFE_OK){
		//~ PF_PrintError("close fd1");
		//~ exit(1);
	//~ }
	//~ printf("closed file1\n");
//~ 
	//~ if ((error=PF_CloseFile(fd2))!= PFE_OK){
		//~ PF_PrintError("close fd2");
		//~ exit(1);
	//~ }
	//~ printf("closed file2\n");
	//~ /* print the files */
	//~ readfile(FILE1);
	//~ readfile(FILE2);
//~ 
//~ 
	//~ /* destroy the two files */
	//~ if ((error=PF_DestroyFile(FILE1))!= PFE_OK){
		//~ PF_PrintError("destroy file1");
		//~ exit(1);
	//~ }
	//~ if ((error=PF_DestroyFile(FILE2))!= PFE_OK){
		//~ PF_PrintError("destroy file2");
		//~ exit(1);
	//~ }
//~ 
	//~ /* create them again */
	//~ if ((fd1=PF_CreateFile(FILE1))< 0){
		//~ PF_PrintError("create file1");
		//~ exit(1);
	//~ }
	//~ printf("file1 created\n");
//~ 
	//~ if ((fd2=PF_CreateFile(FILE2))< 0){
		//~ PF_PrintError("create file2");
		//~ exit(1);
	//~ }
	//~ printf("file2 created\n");
//~ 
	//~ /* put stuff into the two files */
	//~ writefile(FILE1);
	//~ writefile(FILE2);
//~ 
	//~ /* Open the files, and see how the buffer manager
	//~ handles more insertions, and deletions */
	//~ /* open both files */
	//~ if ((fd1=PF_OpenFile(FILE1))<0){
		//~ PF_PrintError("open file1\n");
		//~ exit(1);
	//~ }
	//~ printf("opened file1\n");
//~ 
	//~ if ((fd2=PF_OpenFile(FILE2))<0 ){
		//~ PF_PrintError("open file2\n");
		//~ exit(1);
	//~ }
	//~ printf("opened file2\n");
//~ 
	//~ for (i=PF_MAX_BUFS; i < PF_MAX_BUFS*2 ; i++){
		//~ if ((error=PF_AllocPage(fd2,&pagenum,&buf))!= PFE_OK){
			//~ PF_PrintError("first buffer\n");
			//~ exit(1);
		//~ }
		//~ *((int *)buf) = i;
		//~ if ((error=PF_UnfixPage(fd2,pagenum,TRUE))!= PFE_OK){
			//~ PF_PrintError("unfix file1");
			//~ exit(1);
		//~ }
		//~ printf("alloc %d file1\n",i,pagenum);
//~ 
		//~ if ((error=PF_AllocPage(fd1,&pagenum,&buf))!= PFE_OK){
			//~ PF_PrintError("first buffer\n");
			//~ exit(1);
		//~ }
		//~ *((int *)buf) = i;
		//~ if ((error=PF_UnfixPage(fd1,pagenum,TRUE))!= PFE_OK){
			//~ PF_PrintError("dispose file1");
			//~ exit(1);
		//~ }
		//~ printf("alloc %d file2\n",i,pagenum);
	//~ }
//~ 
	//~ for (i= PF_MAX_BUFS; i < PF_MAX_BUFS*2; i++){
		//~ if (i & 1){
			//~ if ((error=PF_DisposePage(fd1,i))!= PFE_OK){
				//~ PF_PrintError("dispose fd1");
				//~ exit(1);
			//~ }
			//~ printf("dispose fd1 page %d\n",i);
		//~ }
		//~ else {
			//~ if ((error=PF_DisposePage(fd2,i))!= PFE_OK){
				//~ PF_PrintError("dispose fd2");
				//~ exit(1);
			//~ }
			//~ printf("dispose fd2 page %d\n",i);
		//~ }
	//~ }
//~ 
	//~ printf("getting file2\n");
	//~ for (i=PF_MAX_BUFS; i < PF_MAX_BUFS*2; i++){
		//~ if (i & 1){
			//~ if ((error=PF_GetThisPage(fd2,i,&buf))!=PFE_OK){
				//~ PF_PrintError("get this on fd2");
				//~ exit(1);
			//~ }
			//~ printf("%d %d\n",i,*buf);
			//~ if ((error=PF_UnfixPage(fd2,i,FALSE))!= PFE_OK){
				//~ PF_PrintError("get this on fd2");
					//~ exit(1);
			//~ }
		//~ }
	//~ }
//~ 
	//~ printf("getting file1\n");
	//~ for (i=PF_MAX_BUFS; i < PF_MAX_BUFS*2; i++){
		//~ if (!(i & 1)){
			//~ if ((error=PF_GetThisPage(fd1,i,&buf))!=PFE_OK){
				//~ PF_PrintError("get this on fd2");
				//~ exit(1);
			//~ }
			//~ printf("%d %d\n",i,*buf);
			//~ if ((error=PF_UnfixPage(fd1,i,FALSE))!= PFE_OK){
				//~ PF_PrintError("get this on fd2");
					//~ exit(1);
			//~ }
		//~ }
	//~ }
//~ 
	//~ /* print the files */
	//~ printfile(fd2);
//~ 
	//~ printfile(fd1);
//~ 
	//~ /*put some more stuff into file1 */
	//~ printf("putting stuff into holes in fd1\n"); 
	//~ for (i=0; i < (PF_MAX_BUFS/2 -1); i++){
		//~ if (PF_AllocPage(fd1,&pagenum,&buf)!= PFE_OK){
			//~ PF_PrintError("PF_AllocPage");
			//~ exit(1);
		//~ }
		//~ *buf =pagenum;
		//~ if (PF_UnfixPage(fd1,pagenum,TRUE)!= PFE_OK){
			//~ PF_PrintError("PF_UnfixPage");
			//~ exit(1);
		//~ }
	//~ }
//~ 
	//~ printf("printing fd1");
	//~ printfile(fd1);
//~ 
	//~ PF_CloseFile(fd1);
	//~ printf("closed file1\n");
//~ 
	//~ PF_CloseFile(fd2);
	//~ printf("closed file2\n");
//~ 
	//~ /* open file1 twice */
	//~ if ((fd1=PF_OpenFile(FILE1))<0){
		//~ PF_PrintError("open file1");
		//~ exit(1);
	//~ }
	//~ printf("opened file1\n");
//~ 
	//~ /* try to destroy it while it's still open*/
	//~ error=PF_DestroyFile(FILE1);
	//~ PF_PrintError("destroy file1, should not succeed");
//~ 
//~ 
	//~ /* get rid of some invalid page */
	//~ error=PF_DisposePage(fd1,100);
	//~ PF_PrintError("dispose page 100, should fail");
//~ 
//~ 
	//~ /* get a valid page, and try to dispose it without unfixing.*/
	//~ if ((error=PF_GetThisPage(fd1,1,&buf))!=PFE_OK){
		//~ PF_PrintError("get this on fd2");
		//~ exit(1);
	//~ }
	//~ printf("got page%d\n",*buf);
	//~ error=PF_DisposePage(fd1,1);
	//~ PF_PrintError("dispose page1, should fail");
//~ 
	//~ /* Now unfix it */
	//~ if ((error=PF_UnfixPage(fd1,1,FALSE))!= PFE_OK){
		//~ PF_PrintError("get this on fd2");
			//~ exit(1);
	//~ }
//~ 
	//~ error=PF_UnfixPage(fd1,1,FALSE);
	//~ PF_PrintError("unfix fd1 again, should fail");
//~ 
	//~ if ((fd2=PF_OpenFile(FILE1))<0 ){
		//~ PF_PrintError("open file1 again");
		//~ exit(1);
	//~ }
	//~ printf("opened file1 again\n");
//~ 
	//~ printfile(fd1);
//~ 
	//~ printfile(fd2);
//~ 
	//~ if (PF_CloseFile(fd1) != PFE_OK){
		//~ PF_PrintError("close fd1");
		//~ exit(1);
	//~ }
//~ 
	//~ if (PF_CloseFile(fd2)!= PFE_OK){
		//~ PF_PrintError("close fd2");
		//~ exit(1);
	//~ }
//~ 
	//~ /* print the buffer */
	//~ printf("buffer:\n");
	//~ PFbufPrint();
//~ 
	//~ /* print the hash table */
	//~ printf("hash table:\n");
	//~ PFhashPrint();
//~ }
}

/************************************************************
Open the File.
allocate as many pages in the file as the buffer
manager would allow, and write the page number
into the data.
then, close file.
******************************************************************/
writefile(fname)
char *fname;
{
int i;
int fd,pagenum;
int *buf;
int error;
	PF_PrintError("Oh Teri Ye kya ho gaya\n");
	/* open file1, and allocate a few pages in there */
	if ((fd=PF_OpenFile(fname))<0){
		PF_PrintError("open file1");
		exit(1);
	}
	printf("opened %s\n",fname);

	for (i=0; i < PF_MAX_BUFS; i++){
		if ((error=PF_AllocPage(fd,&pagenum,&buf))!= PFE_OK){
			PF_PrintError("first buffer\n");
			exit(1);
		}
		*((int *)buf) = i;
		printf("allocated page %d\n",pagenum);
	}

	if ((error=PF_AllocPage(fd,&pagenum,&buf))==PFE_OK){
		printf("too many buffers, and it's still OK\n");
		exit(1);
	}

	/* unfix these pages */
	for (i=0; i < PF_MAX_BUFS; i++){
		if ((error=PF_UnfixPage(fd,i,TRUE))!= PFE_OK){
			PF_PrintError("unfix buffer\n");
			exit(1);
		}
	}

	/* close the file */
	if ((error=PF_CloseFile(fd))!= PFE_OK){
		PF_PrintError("close file1\n");
		exit(1);
	}

}


//~ 
//~ /**************************************************************
//~ print the content of file
//~ *************************************************************/
readfile(fname)
char *fname;
{
int error;
int *buf;
int pagenum;
int fd;
	PF_PrintError("Yes I am here\n");
	printf("opening %s\n",fname);
	if ((fd=PF_OpenFile(fname))<0){
		PF_PrintError("open file");
		exit(1);
	}
	printfile(fd);
	if ((error=PF_CloseFile(fd))!= PFE_OK){
		PF_PrintError("close file");
		exit(1);
	}
}

printfile(fd)
int fd;
{
int error;
int *buf;
int pagenum;

	printf("reading file\n");
	pagenum = -1;
	while ((error=PF_GetNextPage(fd,&pagenum,&buf))== PFE_OK){
		printf("got page %d, %d\n",pagenum,*buf);
		if ((error=PF_UnfixPage(fd,pagenum,FALSE))!= PFE_OK){
			PF_PrintError("unfix");
			exit(1);
		}
	}
	if (error != PFE_EOF){
		PF_PrintError("not eof\n");
		exit(1);
	}
	printf("Oh Nodfffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg\n");
	printf("eof reached\n");

}

