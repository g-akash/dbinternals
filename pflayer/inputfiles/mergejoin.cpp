#include<iostream>

using namespace std;

int main()
{
	double fs,ss;
	cout<<"Give the size of the first relation"<<endl;
	cin>>fs;
	cout<<"Give the size of the second relation"<<endl;
	cin>>ss;
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
