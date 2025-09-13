#include<bits/stdc++.h>
using namespace std;
int n,l,r;
bool a[5010];
int pos1[5010];
bool v[5010][5010];
int len=0;
char c;
int main()
{
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='a')
		{
			a[i]=1;
			pos1[++len]=i;
		}
		else
		{
			a[i]=0;
		}
	}
	
}
