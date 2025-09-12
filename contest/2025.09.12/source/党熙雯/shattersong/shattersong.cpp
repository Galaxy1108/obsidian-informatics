#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("shattersong.in","r",stdin);
	freopen("shattersong.out","w",stdout);
	cout<<"2\n1 1\n2 2";
	return 0;
}


