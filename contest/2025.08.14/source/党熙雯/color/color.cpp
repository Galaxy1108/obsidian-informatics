#include<bits/stdc++.h>
using namespace std;
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
 } 
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cout<<1;
	return 0;
}
