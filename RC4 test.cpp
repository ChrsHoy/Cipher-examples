#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
int S[25];

char letter;

//char ct[256];

string StrIn="cryptographyisamethodofprotectinginformationandcommunicationsthroughtheuseofcodessothatonlythoseforwhomtheinformationisintendedcanreadandprocessit";
for (int i=0;i <26;i++)
	S[i]=i;
int CODE[]={2,14,3,4,18};
int T[25];
for (int i=0;i<26;i++)
	T[i]=CODE[i%(sizeof(CODE)/sizeof(CODE[0]))];



	{
	int j=0;
	int Temp=0;	
	for (int i=0;i<(sizeof(S)/sizeof(S[0]));i++)
		{
		Temp=S[i];
		j=(j+S[i]+T[i])%((sizeof(S)/sizeof(S[0])));
		S[i]=S[j];
		S[j]=Temp;
		
		//cout<<S[i]<<",";
		}

	//for (int i=0;i<26;i++)
	//	cout<<S[i]<<",";
	cout<<endl;	
	}

	
	int i,j = 0;
	int k[(sizeof(S)/sizeof(S[0]))];
	char ct[StrIn.length()-1];
	char dt[StrIn.length()-1];
	for (int i=0; i<(sizeof(S)/sizeof(S[0]));i++)
		{
		int Temp=0;
		//letter =StrIn[i];
		i=(i+1)%((sizeof(S)/sizeof(S[0])));
		j=(j+S[i])%((sizeof(S)/sizeof(S[0])));
		Temp=S[i];
		S[i]=S[j];
		S[j]=Temp;
		k[i]=S[(S[i]+S[j])%((sizeof(S)/sizeof(S[0])))];
		
		cout<<k[i]<<",";
		}
	cout<<endl;

	cout<<StrIn;
	
	cout<<endl;

	//xor implementation
		
		for(int i=0;i<StrIn.length();i++)
		{
		letter=StrIn[i];
		ct[i]=((int(letter)>>2)^(k[i%((sizeof(k)/sizeof(k[0])))])+96);
			if(ct[i]>122)
			{	ct[i]=ct[i]%123+97;}	
		cout<<ct[i];
		}
		cout<<endl;
	
	
		//~ xor
	

		
		for(int i=0;i<StrIn.length();i++)
		{
		dt[i]=((((ct[i]>>2)&k[i%((sizeof(k)/sizeof(k[0])))])+97)|((~(ct[i]>>2)&~(k[i%((sizeof(k)/sizeof(k[0])))]))+97));
		cout<<dt[i];
		}
		

		/*
		for(int i=0;i<StrIn.length();i++)
		{
		dt[i]=~((ct[i]>>2)^(k[i%((sizeof(k)/sizeof(k[0])))])+96);
		cout<<dt[i];
		*/
		
		cout<<endl;

	
	
return 0;

}

