#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0;
	char c=getchar();
	while(c>'9'&&c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
const int N=1e3+3;
struct T
{
	int w,up,down[N],z,x;
	bool f;
	double ans;
}a[N];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n=read(),i,j,num=0;
	for(i=2;i<=n;++i)
	{
		a[i].up=read();
		a[a[i].up].f=true;
		a[a[i].up].down[++a[a[i].up].z]=i;
	}
	for(i=1;i<=n;++i) a[i].w=read();
	while(num<n)
	{
		for(i=1;i<=n;++i)
		{
			if(!a[i].f)
			{
				while(a[a[i].up].w>=a[i].w)
				{
					a[i].ans*=a[i].x;
					a[i].ans+=a[a[i].up].w;
					a[i].ans=a[i].ans/(++a[i].z);
				}
			}
		}
	}
	for(i=1;i<=n;++i) printf("%.10lf\n",a[i].ans);
}
