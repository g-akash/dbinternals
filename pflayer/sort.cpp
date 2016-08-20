#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int merge(int runs,int size,int i,int j,int write){
	if(runs<20){
		int q=write;
		for(int k=0;k<size;k++){
			int count=0;int r=1;
			for(int l=i+k;l<=j && r<=runs;l=l+size){
				cout<<l<<" "<<"r"<<endl;count++;r++;}
			while(count >0){
				cout<<q<<" "<<"w"<<endl;q++;count--;}}
			return 1;
}
	else{
	     int k=merge(19,size,i,i+19*size-1,write);
	     int l=merge(runs-19,size,i+19*size,j,write+19*size);
	     return k+l;
		}
}
int mergemain(int runs,int size,int i,int j,int write){
	int k=runs;
	while(k>19){
		k=merge(k,size,i,j,write);
		int k1=i,k2=j;
		size*=19;i+=(2*(k2-k1+1));j+=2*(k2-k1+1);write=j+1;}
	merge(k,size,i,j,write);
	return 0;}
int main(int argc,char* argv[]){
	int fs=atoi(argv[1]);
	int size=fs;
	int tmp=fs;
	while(tmp>19){size+=fs;if(tmp%19==0)tmp/=19;
			else tmp=(tmp/19+1);}
	size+=fs;
	cout<<size<<endl;
	int k=0,runs=0,curr=0;
	while(k<fs){
		for(int i=0;i<19 && k+i < fs;i++){
			cout<<k+i<<" "<<"r"<<endl;}
		for(int i=0;i<19 && k+i < fs;i++){
			cout<<fs+k+i<<" "<<"w"<<endl;curr=fs+k+i;}
		k+=19;runs++;}
	if(runs>1)mergemain(runs,19,fs,2*fs-1,2*fs);
}
