#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
struct node
{
	int x,y;
	bool o;
}a[10003];
int main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	int n=read(),m=read(),s=read(),t=read(),i;
	bool f1=true;
	for(i=1;i<=m;++i)
	{
		a[i].x=read();
		a[i].y=read();
		a[i].o=read();
		if(a[i].o) f1=false;
	}
	if(f1)
	{
		cout<<"0 0";
		return 0;
	}
}
