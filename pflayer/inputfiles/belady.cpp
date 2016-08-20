#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

#define bufsize 3

int main()
{
	int size,var,j;
	ifstream in;
	in.open("inp.txt");
	in>>size;
	string s;
	vector<int> v;
	while(in>>var)
	{
		in>>s;
		v.push_back(var);
	}
	vector<int> buf;
	buf.resize(bufsize);
	for(int i=0;i<bufsize;i++)buf[i]=-1;
	for(int i=0;i<v.size();i++)
	{
		
		for(j=0;j<bufsize;j++)
		{
			if(buf[j]==v[i])
			{
				cout<<"hit"<<endl;
				break;
			}
		}
		
		if(j!=bufsize)continue;
		cout<<"miss"<<endl;
		for(j=0;j<bufsize;j++)if(buf[j]==-1)break;
		if(j<bufsize){buf[j]=v[i];continue;}
		
		vector<int> nacces;
		nacces.resize(bufsize);
		for(j=0;j<bufsize;j++)nacces[j]=10000000;
		int x=0;
		for(x=0;x<bufsize;x++)
		{
			for(int k=i;k<v.size();k++)if(v[k]==buf[x]){nacces[x]=k;break;}
		}
		 
		int maxdist=-1000000,index=0;
		for(x=0;x<bufsize;x++)if(nacces[x]>maxdist){index=x;maxdist=nacces[x];}
		buf[index]=v[i];
		
	}
}
		
	
