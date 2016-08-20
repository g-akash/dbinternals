#include<iostream>
#include<vector>
#include<string>


using namespace std;

int main()
{
	string s;
	float h=0,t=0;
	while(cin>>s)
	{
		if(s=="hit")h+=1;
		t+=1;
	}
	cout<<h*100.0/t<<endl;
}
