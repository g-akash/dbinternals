#include <iostream>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(int argc,char* argv[])
{
	
int fs,ss;
	fs=atoi(argv[1]);
	ss=atoi(argv[2]);
	/*buckets1 = no.of buckets in hash table of fs buskets2 for ss,b1=no.of blocks in bucket of fs,b2 for ss*/
	int buckets1,buckets2,b1,b2;
	if(fs<=19){buckets1=fs;}
	else{buckets1=19;}
	if(ss<=19){buckets2=ss;}
	else{buckets2=19;}
	if(fs>ss){buckets2=buckets1;}
	else{buckets1=buckets2;}
	b2=ceil(ss/buckets2);b2=b2*1.15;
	b1=ceil(fs/buckets1);b1=b1*1.15;
	//cout<<buckets1<<" "<<buckets2<<" "<<b1<<" "<<b2<<endl;
	cout<<fs+ss+buckets1*(b1+b2)<<endl;
	int hb1[buckets1];int hb2[buckets2];
	for(int i=0;i<buckets1;i++){
		hb1[i]=fs+ss+i*b1;}
	for(int i=0;i<buckets2;i++){
		hb2[i]=hb1[buckets1-1]+b1+i*b2;}
	for(int i=0;i<ceil(fs/19);i++){
		for(int j=0;j<19 && 19*i+j <fs;j++){
			cout<<19*i+j<<" "<<"r"<<endl;}
		for(int j=0;j<buckets1;j++){
			cout<<hb1[j]+i<<" "<<"w"<<endl;}}
	for(int i=0;i<ceil(ss/19);i++){
		for(int j=0;j<19 && 19*i+j <ss;j++){
			cout<<fs+19*i+j<<" "<<"r"<<endl;}
		for(int j=0;j<buckets1;j++){
			cout<<hb2[j]+i<<" "<<"w"<<endl;}}
	for(int i=0;i<buckets1;i++){
		for(int j=0;j<b1;j++){cout<<hb1[i]+j<<" "<<"r"<<endl;}
		for(int j=0;j<b2;j++){cout<<hb2[i]+j<<" "<<"r"<<endl;}}
}
