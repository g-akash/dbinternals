#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
int main(int argc,char* argv[]){
	ifstream read1("25261.txt",ios::in);
	ifstream read2("25262.txt",ios::in);
	ifstream read3("25263.txt",ios::in);
	ifstream read4("25264.txt",ios::in);
	srand(time(NULL));
	int i1=0,i2=0,i3=0,i4=0;
	int tmp1,tmp2,tmp3,tmp4;int page;char type;
	read1>>tmp1;read2>>tmp2;read3>>tmp3;read4>>tmp4;
	cout<<tmp1+tmp2+tmp3+tmp4<<endl;
	while(i1<atoi(argv[1]) || i2 <atoi(argv[2]) || i3<atoi(argv[3]) || i4<atoi(argv[4])){
		int k=rand()%4;
		if(k==0 && i1<atoi(argv[1])){read1>>page>>type;cout<<page<<" "<<type<<endl;i1++;}
		if(k==1 && i2 <atoi(argv[2])){read2>>page>>type;cout<<tmp1+page<<" "<<type<<endl;i2++;}
		if(k==2 && i3 <atoi(argv[3])){read3>>page>>type;cout<<tmp1+tmp2+page<<" "<<type<<endl;i3++;}
		if(k==3 && i4 <atoi(argv[4])){read4>>page>>type;cout<<tmp1+tmp2+tmp3+page<<" "<<type<<endl;i4++;}}
	}
