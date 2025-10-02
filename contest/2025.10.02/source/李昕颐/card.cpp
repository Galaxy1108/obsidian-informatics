#include<iostream>
#include<stdio.h>
using namespace std;
int a[1000006];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int num=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]%2==0)num++;
		else cnt++;
	}
	if(num==0||cnt==0)
	{
		for(int i=1;i<=k;i++)cout<<"0\n";
		return 0;
	}
	return 0;
}
