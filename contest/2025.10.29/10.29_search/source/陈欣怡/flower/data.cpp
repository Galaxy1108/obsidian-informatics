#include<iostream>
#include<cstdio>
#define ri register int
using namespace std;
int main()
{
	freopen("flower.in","w",stdout);
	int n=16;
	//int n=rand()%40+1; 
	//while(n==39 || n%4==1 || n%4==2) n=rand()%40+1;
	printf("%d\n",n);
	for(ri i=1;i<=n;i++) printf("%d\n",i);
	return 0;
 } 
