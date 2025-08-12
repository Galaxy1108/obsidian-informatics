#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

bool get_op()
{
	char ch=inf.readChar();
	while(ch!='B'&&ch!='C') ch=inf.readChar();
	return ch=='C';
}
void get_max(int &a,int b){if(a<b) a=b;}
void get_min(int &a,int b){if(a>b) a=b;}
int N,M;
int ocnt,acnt;
bool mp[510][510];
int clc[510][510];
int L[250010],R[250010],U[250010],D[250010],cnt[250010];
int main(int argc, char *argv[])
{
	// registerTestlibCmd(argc, argv);
	registerLemonChecker(argc, argv);
	
	memset(L,0x3f,sizeof(L));
	memset(U,0x3f,sizeof(U));

	N=inf.readInt(),M=inf.readInt();

	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++)
		mp[i][j]=get_op();
	
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++)
		acnt=max(acnt,ans.readInt());
	
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++)
	{
		clc[i][j]=ouf.readInt();
		ocnt=max(ocnt,clc[i][j]);
		if(ocnt>N*M) quitf(_wa,"Wrong Answer!");

		get_min(L[clc[i][j]],i);
		get_max(R[clc[i][j]],i);
		get_min(U[clc[i][j]],j);
		get_max(D[clc[i][j]],j);
		cnt[clc[i][j]]++;
	}

	for(int i=1;i<=ocnt;i++) if(cnt[i])
	{
		if(cnt[i]!=(R[i]-L[i]+1)*(D[i]-U[i]+1))
			quitf(_wa,"Wrong Answer!!!");
	}

	if(ocnt<=acnt) quitf(_ok,"Accepted!!!");
	else quitp(0.75*pow(acnt*1./ocnt,10)*5,"Partly Correct!!!");
	return 0;
}