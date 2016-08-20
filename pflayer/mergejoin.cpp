#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	double fs,ss;
	fs= atoi(argv[1]);
	ss= atoi(argv[2]);
	if(fs>ss){
		fs+=ss;
		ss=fs-ss;
		fs=fs-ss;
	}
	int j=0;
	cout<<fs+ss<<endl;
	for(double i=0;i<fs;i++)
	{
		cout<<i<<" "<<"r"<<endl;
		while(j<((i+1.0))*(ss/fs)){cout<<fs+j<<" "<<"r"<<endl;j++;}
	}
}
