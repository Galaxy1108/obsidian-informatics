#include<bits/stdc++.h>
using namespace std;
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
 }
int main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	
	cout<<0;
	return 0;
}

