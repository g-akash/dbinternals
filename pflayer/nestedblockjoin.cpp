#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>


using namespace std;


int main(int argc, char** argv)
{
	int fs,ss;
	fs=atoi(argv[1]);
	ss=atoi(argv[2]);
	if(fs>ss){
		fs+=ss;
		ss=fs-ss;
		fs=fs-ss;
	}
	cout<<fs+ss<<endl;
	for(int i=0;i<ss;i++)
	{
		cout<<i<<" "<<"r"<<endl;
		for(int j=0;j<fs;j++)
		{
			cout<<ss+j<<" "<<"r"<<endl;
		}
	}
}
	
