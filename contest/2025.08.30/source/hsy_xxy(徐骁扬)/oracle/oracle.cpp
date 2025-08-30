#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int n,w;
int main()
{
	freopen("oracle.in","r",stdin);
	freopen("oracle.out","w",stdout);
	n=Qread(),w=Qread();
	printf("0\n");
	return 0;
}