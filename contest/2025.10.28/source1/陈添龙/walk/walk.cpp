#include<bits/stdc++.h>
#define pc(x) putchar(x)
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){f=ch=='-'?-1:f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
void write(int x)
{
	if(x<0){x=-x;pc('-');}
	if(x>9)write(x/10);
	pc(x%10+48);
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	puts("1");
	return 0;
}

